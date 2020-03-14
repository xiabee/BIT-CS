#include <stdio.h>
int main()
{
	int a[10], b[10], ok = 0, sign = 0, r = 0;
	for (int i = 1; i <= 7; i++)
		scanf ("%d %d", &a[i], &b[i]);
	for (int i = 1; i <= 7; i++)
	{
		if (a[i] + b[i] >= 10)
		{ 
			ok = 1;
			if (a[i] + b[i] > r)
			{
	sign = i;
	r = a[i] + b[i];
			}
		}
	}
	if (ok)
		printf ("%d\n", sign);
	else
		printf ("0\n");
}