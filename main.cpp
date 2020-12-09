#include "main.h"

// переименовать размер матрицы n на size

VALUE_TYPE	find_max_delta(VALUE_TYPE (*f)(VALUE_TYPE), vector<point> &table)
{
	VALUE_TYPE	max_epsilon = abs(f(table[0].x) - table[0].y);

	for (int i = 1; i < table.size(); i++)
	{
		VALUE_TYPE	epsilon = abs(f(table[i].x) - table[i].y);
		if (epsilon > max_epsilon) max_epsilon = epsilon;
	}

	return max_epsilon;
}

void	function_handler(VALUE_TYPE (*function)(VALUE_TYPE), VALUE_TYPE a, VALUE_TYPE b,
					  int n, string file_name)
{
	vector<point>	uniform_mesh = create_uniform_mesh(function, a, b, n);
	vector<point>	Chebyshev_mesh = create_Chebyshev_mesh(function, a, b, n);
	vector<point>	interpolation_table = create_table(a, b, STEP);

	ofstream	f_eps;

	f_eps.open("eps.txt", ios::app);

	/* многочлен Лагранжа */
	interpolation_with_Lagrangian_polynomial(uniform_mesh, interpolation_table, n);
	create_files(uniform_mesh, n, interpolation_table, file_name, "_Lagrange");
	VALUE_TYPE	eps = find_max_delta(function, interpolation_table);
	f_eps << file_name << "_Lagrange, MAX EPSILON = " << find_max_delta(function, interpolation_table) << endl;

	interpolation_with_Lagrangian_polynomial(Chebyshev_mesh, interpolation_table, n);
	create_files(Chebyshev_mesh, n, interpolation_table, file_name, "_Lagrange[Chebyshev]");
	VALUE_TYPE	eps1 = find_max_delta(function, interpolation_table);
	f_eps << file_name << "_Lagrange[Chebyshev], MAX EPSILON = " << find_max_delta(function, interpolation_table) << endl;

	/* сплайн */
	interpolation_with_natural_cubic_spline(uniform_mesh, interpolation_table, n);
	create_files(uniform_mesh, n, interpolation_table, file_name, "_splines");
	VALUE_TYPE	eps2 = find_max_delta(function, interpolation_table);
	f_eps << file_name << "_splines, MAX EPSILON = " << find_max_delta(function, interpolation_table) << endl;

	interpolation_with_natural_cubic_spline(Chebyshev_mesh, interpolation_table, n);
	create_files(Chebyshev_mesh, n, interpolation_table, file_name, "_splines[Chebyshev]");
	VALUE_TYPE	eps3 = find_max_delta(function, interpolation_table);
	f_eps << file_name << "_splines[Chebyshev], MAX EPSILON = " << find_max_delta(function, interpolation_table) << endl;

	f_eps.close();
}

int		main()
{
	int n[] = {3, 10, 50};

	/* очищаем файл */
	ofstream	f_eps("eps.txt");
	f_eps.close();

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
