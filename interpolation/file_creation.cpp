#include "interpolation.h"

void	create_files(vector<point> &mesh, int n, vector<point> &table,
					 string &file_name, string method)
{
	/* таблица значений функции в узлах сетки */
	ofstream	input_nodes(DIR + file_name + method + "_nodes.csv");

	for (int i = 0; i < n; i++)
		input_nodes << mesh[i].x << ", " << mesh[i].y << endl;

	input_nodes.close();

	/* интерполяционные узлы */
	ofstream	output(DIR + file_name + method + "_table.csv");

	for (int i = 0; i < table.size(); i++)
		output << table[i].x << ", " << table[i].y << endl;

	output.close();
}

