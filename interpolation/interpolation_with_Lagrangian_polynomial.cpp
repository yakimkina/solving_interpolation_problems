#include "interpolation.h"

VALUE_TYPE	calculate_c_k(vector<point> &mesh, VALUE_TYPE x, int k, int n)
{
	VALUE_TYPE	c_k = 1;

	for (int j = 0; j < n; j++)
		c_k *= (j != k) ? (x - mesh[j].x) / (mesh[k].x - mesh[j].x) : 1;

	return c_k;
}

void	interpolation_with_Lagrangian_polynomial(vector<point> &mesh, vector<point> &table, int n)
{
	for (int i = 0; i < table.size(); i++)
	{
		table[i].y = 0;

		for (int j = 0; j < n; j++)
			table[i].y += calculate_c_k(mesh, table[i].x, j, n) * mesh[j].y; // c_k(x) * y_i
	}
}

