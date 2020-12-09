#include "main.h"

/* y = x^2 */
VALUE_TYPE	test_1(VALUE_TYPE x)
{ return pow(x, 2); }

/* y = 1 / (1 + x^2) */
VALUE_TYPE	test_2(VALUE_TYPE x)
{ return (1 / (1 + 25 * pow(x, 2))); }

/* y = 1 / arctg(1 + 10x^2) */
VALUE_TYPE	test_3(VALUE_TYPE x)
{ return (1 / atan(1 + 10 * pow(x, 2))); }

/* y = (4x^3 + 2x^2 - 4x + 2)^√2 + arcsin(1 / (5 + x - x^2)) - 5 */
VALUE_TYPE	test_4(VALUE_TYPE x)
{
	VALUE_TYPE	x2 = pow(x, 2);
	return (pow((4 * pow(x, 3) + 2 * x2 - 4 * x + 2), sqrt(2)) +
	asin(1 / (5 + x - x2)) - 5);
}


