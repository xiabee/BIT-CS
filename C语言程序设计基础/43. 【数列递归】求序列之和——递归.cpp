#include <stdio.h>
double f(int n)
{
	if (n == 1) return 1;
	else
	{
		if (n % 2 == 0)
			return 1.0/n + f(n - 1);
		else
			return -1.0/n + f(n - 1);
	}
}
int main()
{
	int n;
	scanf ("%d", &n);
	if (n == 1)
		printf ("1\n");
	else printf ("%.6lf\n", f(n));
	
}