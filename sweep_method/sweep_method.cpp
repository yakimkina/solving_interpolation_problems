#include "sweep_method.h"

void	direct_traverse(tridiagonal_matrix &slae, int n)
{
	slae.c[0] /= ((-1) * slae.b[0]); // alpha_2
	slae.d[0] /= slae.b[0]; // beta_2
	slae.b[0] = 1; // x1 = alpha_2 * x2 + beta_2
	for (int i = 1; i < n - 1; i++)
	{
		slae.c[i] /= ((-1) * slae.b[i] - slae.a[i - 1] * slae.c[i - 1]); // alpha_(i + 1) = c_i / ((-1) * b_i - a_i * alpha_i)
		slae.d[i] = ((-1) * slae.d[i] + slae.a[i - 1] * slae.d[i - 1]) /
				((-1) * slae.b[i] - slae.a[i - 1] * slae.c[i - 1]); // beta_(i + 1) = ((-1) * d_i + a_i * beta_i) / ((-1) * b_i - a_i * alpha_i)
		slae.a[i - 1] = 0;
		slae.b[i] = 1; // x_i = alpha_(i + 1) * x_(i + 1) + beta_(i + 1)
	}
	slae.d[n - 1] = ((-1) * slae.d[n - 1] + slae.a[n - 2] * slae.d[n - 2]) /
					((-1) * slae.b[n - 1] - slae.a[n - 2] * slae.c[n - 2]); // beta_n
	slae.a[n - 2] = 0;
	slae.b[n - 1] = 1;
}

void	reverse_traverse(tridiagonal_matrix &slae, int n)
{
	for (int i = n - 2; i >= 0; i--)
	{
		slae.d[i] += slae.c[i] * slae.d[i + 1];
		slae.c[i] = 0;
	}
}

vector<VALUE_TYPE>	sweep_method(tridiagonal_matrix slae, int n)
{
	vector<VALUE_TYPE> x(n);

	direct_traverse(slae, n);
	reverse_traverse(slae, n);

	for (int i = 0; i < n; i++) // вынести в отдельную функцию ?
		x[i] = slae.d[i];

	return x;
}

