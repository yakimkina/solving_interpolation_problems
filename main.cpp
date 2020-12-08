#include "main.h"

// переименовать размер матрицы n на size

void	function_handler(VALUE_TYPE	(*function)(VALUE_TYPE), VALUE_TYPE a, VALUE_TYPE b,
					  int n, string file_name)
{
	vector<point>	uniform_mesh = create_uniform_mesh(function, a, b, n);
	vector<point>	Chebyshev_mesh = create_Chebyshev_mesh(function, a, b, n);
	vector<point>	interpolation_table = create_table(a, b, STEP);

	/* многочлен Лагранжа */
	interpolation_with_Lagrangian_polynomial(uniform_mesh, interpolation_table, n);
	create_files(uniform_mesh, n, interpolation_table, file_name, "_Lagrange");

	interpolation_with_Lagrangian_polynomial(Chebyshev_mesh, interpolation_table, n);
	create_files(Chebyshev_mesh, n, interpolation_table, file_name, "_Lagrange[Chebyshev]");

	/* сплайн */
	interpolation_with_natural_cubic_spline(uniform_mesh, interpolation_table, n);
	create_files(uniform_mesh, n, interpolation_table, file_name, "_splines");

	interpolation_with_natural_cubic_spline(Chebyshev_mesh, interpolation_table, n);
	create_files(Chebyshev_mesh, n, interpolation_table, file_name, "_splines[Chebyshev]");
}

int		main()
{
	int n[] = {3, 10, 50};

	/* test 1 */
	for (int i : n)
		function_handler(test_1, -1, 1, i, "test1[" + to_string(i) + "]");

	/* test 2 */
	for (int i : n)
		function_handler(test_2, -1, 1, i, "test2[" + to_string(i) + "]");

	/* test 3 */
	for (int i : n)
		function_handler(test_3, -3, 3, i, "test3[" + to_string(i) + "]");

	/* test 4 */
	for (int i : n)
		function_handler(test_4, -1, 1, i, "test4[" + to_string(i) + "]");


	return 0;
}
