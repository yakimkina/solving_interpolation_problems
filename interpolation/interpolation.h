#ifndef INTERPOLATION_H
#define INTERPOLATION_H

#include "../sweep_method/sweep_method.h"

vector<point>	create_table(VALUE_TYPE a, VALUE_TYPE b, VALUE_TYPE step);
vector<point>	create_uniform_mesh(VALUE_TYPE (*function)(VALUE_TYPE), VALUE_TYPE a, VALUE_TYPE b, int n);
vector<point>	create_Chebyshev_mesh(VALUE_TYPE (*function)(VALUE_TYPE), VALUE_TYPE a, VALUE_TYPE b, int n);

void	interpolation_with_Lagrangian_polynomial(vector<point> &mesh, vector<point> &table, int n);
void	interpolation_with_natural_cubic_spline(vector<point> &mesh, vector<point> &table, int n);

void	create_files(vector<point> &mesh, int n, vector<point> &table, string &file_name, string method);

#endif
