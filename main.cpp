#include "main.h"

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
	create_files(Chebyshev_mesh, n, interpolation_table, file_name, "_Chebyshev");

	/* сплайн */
	interpolation_with_natural_cubic_spline(uniform_mesh, interpolation_table, n);

}

int		main()
{
	int n[] = {3, 5, 10, 50, 100};

	/* y = x^2 */
	for (int i : n)
		function_handler(parabola, -1, 1, i, "fun1." + to_string(i));
	


	return 0;
}
