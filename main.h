#ifndef MAIN_H
#define MAIN_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cmath>

#define WIDTH	8
#define PREC	4
#define STEP	0.02
#define EPSILON	0.0001

#define DIR		"output/"

#define PRINT_STEPS	false
#define PRINT_CHECK	false

using namespace std;

typedef double VALUE_TYPE;

struct	point
{
	VALUE_TYPE	x;
	VALUE_TYPE	y;
};

#include "interpolation/math_functions.h"
#include "interpolation/interpolation.h"

void	print_vector(vector<VALUE_TYPE> x);
void 	print_slae(vector<vector<VALUE_TYPE>> slae, int m, int n); /* print SLAE with b vector */
void	print_slae(vector<vector<VALUE_TYPE>> &slae, int size); /* print SLAE without b vector */

#endif
