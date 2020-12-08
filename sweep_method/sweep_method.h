#ifndef SWEEP_METHOD_H
#define SWEEP_METHOD_H

#include "../main.h"

struct	tridiagonal_matrix
{
	vector<VALUE_TYPE>	a;
	vector<VALUE_TYPE>	b;
	vector<VALUE_TYPE>	c;
	vector<VALUE_TYPE>	d;
};

vector<VALUE_TYPE>	sweep_method(tridiagonal_matrix slae, int n);

#endif
