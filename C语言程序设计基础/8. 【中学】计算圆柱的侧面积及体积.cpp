#include <stdio.h>
#define P 3.1415926

void main()
{
	double r, h, s, v;
	scanf ("%lf", &r);
	scanf ("%lf", &h);

	

	s = 2 * P * r * h;
	v = P * r * r * h;

	printf ("s=%.2lf,v=%.2lf\n", s, v);

}