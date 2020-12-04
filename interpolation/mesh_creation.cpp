#include "interpolation.h"

vector<point>	create_Chebyshev_mesh(VALUE_TYPE (*function)(VALUE_TYPE), VALUE_TYPE a, VALUE_TYPE b, int n)
{
	vector<point>	mesh;

	for (int i = 0; i < n; i++)
	{
		point	tmp;
		tmp.x = (a + b) / 2 + (b - a) / 2 * cos((2 * i + 1) * M_PI / (2 * n));
		tmp.y = function(tmp.x);

		mesh.push_back(tmp);
	}

	return (mesh);
}

vector<point>	create_uniform_mesh(VALUE_TYPE (*function)(VALUE_TYPE), VALUE_TYPE a, VALUE_TYPE b, int n)
{
	vector<point>	mesh;
	VALUE_TYPE	step = (b - a) / (n - 1);

	for (int i = 0; i < n; i++)
	{
		point	tmp;
		tmp.x = a + step * i;
		tmp.y = function(tmp.x);

		mesh.push_back(tmp);
	}

	return (mesh);
}

