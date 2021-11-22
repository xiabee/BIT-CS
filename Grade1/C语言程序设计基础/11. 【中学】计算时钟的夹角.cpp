#include <stdio.h>

double jd(double x, double y)
{ 
	double r;

	if (x > y)  r = x - y;
	else		r = y - x;

	return r;
}

void main()
{
	int s, f;
	double deg, r1;

	scanf ("%d %d", &s, &f);

	r1 = jd (s/12.0 + f/720.0, f/60.0);
	if (r1 > 0.5)  r1 = 1 - r1;
	
	deg = 360.0 * r1;

	if (f < 10)
	{
		printf ("At %d:0%d the angle is %.1lf degrees.\n", s, f, deg);
	}

	else printf ("At %d:%d the angle is %.1lf degrees.\n", s, f, deg);
}