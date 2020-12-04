#include "interpolation.h"

vector<point>	create_table(VALUE_TYPE a, VALUE_TYPE b, VALUE_TYPE step)
{
	vector<point>	table;

	for (VALUE_TYPE i = a; i <= b; i += step)
	{
		point	tmp;
		tmp.x = i;

		table.push_back(tmp);
	}

	return table;
}

