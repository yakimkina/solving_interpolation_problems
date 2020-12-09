#include "interpolation.h"

tridiagonal_matrix	create_tridiagonal_slae(vector<point> &mesh, int n)
{
	tridiagonal_matrix	slae;

	slae.b.push_back(2 * ((mesh[1].x - mesh[0].x) + (mesh[2].x - mesh[1].x)));
	slae.c.push_back(mesh[2].x - mesh[1].x);
	slae.d.push_back(3 * (((mesh[2].y - mesh[1].y) / (mesh[2].x - mesh[1].x)) -
		((mesh[1].y - mesh[0].y) / (mesh[1].x - mesh[0].x))));
	for (int i = 3; i < n; i++)
	{
		slae.a.push_back(mesh[i - 1].x - mesh[i - 2].x);
		slae.b.push_back(2 * ((mesh[i - 1].x - mesh[i - 2].x) + (mesh[i].x - mesh[i - 1].x)));
		slae.c.push_back(mesh[i].x - mesh[i - 1].x);
		slae.d.push_back(3 * (((mesh[i].y - mesh[i - 1].y) / (mesh[i].x - mesh[i - 1].x)) -
			((mesh[i - 1].y - mesh[i - 2].y) / (mesh[i - 1].x - mesh[i - 2].x))));
	}
	slae.a.push_back(mesh[n - 1].x - mesh[n - 2].x);
	slae.b.push_back(2 * ((mesh[n - 1].x - mesh[n - 2].x) + (mesh[n].x - mesh[n - 1].x)));
	slae.d.push_back(3 * (((mesh[n].y - mesh[n - 1].y) / (mesh[n].x - mesh[n - 1].x)) -
		((mesh[n - 1].y - mesh[n - 2].y) / (mesh[n - 1].x - mesh[n - 2].x))));

	return slae;
}

vector<VALUE_TYPE>	create_c(vector<point> &mesh, int n)
{
	vector<VALUE_TYPE>	c;

	if (n == 3)
	{
		VALUE_TYPE	d = 3 * (((mesh[2].y - mesh[1].y) / (mesh[2].x - mesh[1].x)) -
				((mesh[1].y - mesh[0].y) / (mesh[1].x - mesh[0].x)));
		VALUE_TYPE	b = 2 * ((mesh[1].x - mesh[0].x) + (mesh[2].x - mesh[1].x));
		c.push_back(d / b);
	}
	else
	{
		tridiagonal_matrix	slae = create_tridiagonal_slae(mesh, n - 1);
		c = sweep_method(slae, n - 2);
	}

	c.insert(c.begin(), 0);
	c.push_back(0);

	return c;
}

void	calculate_coefficients(vector<VALUE_TYPE> &a, vector<VALUE_TYPE> &b, vector<VALUE_TYPE> &c,
							vector<VALUE_TYPE> &d, vector<point> &mesh, int n)
{
	for (int i = 1; i < n; i++)
	{
		VALUE_TYPE	h = mesh[i].x - mesh[i - 1].x; // h_i = x_i - x_(i - 1)
		a[i - 1] = mesh[i - 1].y;  // a_i = y_(i - 1);
		b[i - 1] = (mesh[i].y - mesh[i - 1].y) / h - (c[i] + 2 * c[i - 1]) * h / 3; // b_i = (y_i - y_(i - 1)) / h_i - (c_(i + 1) + 2_c_i) * h_i / 3
		d[i - 1] = (c[i] - c[i - 1]) / (3 * h);  // d_i = (c_(i + 1) - c_i) / (3 * h_i)
	}
}

void	interpolation_with_natural_cubic_spline(vector<point> &mesh, vector<point> &table, int n)
{
	vector<VALUE_TYPE>	c = create_c(mesh, n);
	vector<VALUE_TYPE>	a(n - 1), b(n - 1), d(n - 1);

	calculate_coefficients(a, b, c, d, mesh, n);

	/* граничный случай до: удаляем точки, для которых нет сплайнов*/
	int	j = 0;
	while (table[j].x < mesh[0].x)
		j++;

	table.erase(table.begin(), table.begin() + j);

	j = 0;
	for (int i = 1; i < n; i++)
	{
		for (; (table[j].x < mesh[i].x) && (j < table.size()); j++)
		{
			VALUE_TYPE	delta = table[j].x - mesh[i - 1].x;
			table[j].y = a[i - 1] + b[i - 1] * delta + c[i - 1] * pow(delta, 2) +
					d[i - 1] * pow(delta, 3);
		}
	}

	/* граничный случай после: удаляем точки в таблице, для которых нет сплайнов */
	if (j < table.size()) table.erase(table.begin() + j, table.end());
}

