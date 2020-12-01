#include "main.h"

void	create_files(vector<vector<VALUE_TYPE>> &table, int n, vector<VALUE_TYPE> &x, vector<VALUE_TYPE> &y,
				 string &file_name, string method)
{
	fstream	input_nodes(DIR + file_name + method + "_nodes.dat");
	
	for (int i = 0; i < n; i++)
		input_nodes << table[0][i] << " " << table[1][i] << endl;

	input_nodes.close();


	fstream	output(DIR + file_name + method + ".dat");

	for (int i = 0; i < x.size(); i++)
		output << x[i] << " " << y[i] << endl;

	output.close();
}

vector<VALUE_TYPE>	create_x(int a, int b)
{
	vector<VALUE_TYPE>	x;

	for (VALUE_TYPE i = a; i <= b; i += STEP)
		x.push_back(i);

	return x;
}

vector<vector<VALUE_TYPE>>	create_table(VALUE_TYPE	(*function)(VALUE_TYPE), VALUE_TYPE a, VALUE_TYPE b, int n)
{
	vector<vector<VALUE_TYPE>>	table;
	VALUE_TYPE	step = (b - a) / (n - 1);

	vector<VALUE_TYPE>	x;
	vector<VALUE_TYPE>	y;

	for (int i = 0; i < n; i++)
	{
		x.push_back(a + step * i);
		y.push_back(function(x[i]));
	}

	table.push_back(x);
	table.push_back(y);

	return (table);
}

void	function_handler(VALUE_TYPE	(*function)(VALUE_TYPE), VALUE_TYPE a, VALUE_TYPE b,
					  int n, string file_name)
{
	vector<vector<VALUE_TYPE>>	table = create_table(function, a, b, n);
	vector<VALUE_TYPE>	x = create_x(a, b);

	/* многочлен Лагранжа */
	vector<VALUE_TYPE> y = interpolation_with_Lagrangian_polynomial(table, x, n);
	create_files(table, n, x, y, file_name, "_Lagrange");
	
}

int		main()
{
	int n[] = {3, 5, 10, 50, 100};

	/* y = x^2 */
	for (int i : n)
		function_handler(parabola, -1, 1, i, "fun1." + to_string(i));
	


	return 0;
}
