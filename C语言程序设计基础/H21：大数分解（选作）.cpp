#include <stdio.h>
int is_ss(int n)
{
	for (int i = 2; i*i <= n; i++)
		if (n % i == 0) return 0;
	return 1;
}
int main()
{
	int n;
	scanf ("%d", &n);
	for (int i = 2; i*i <= n; i++)
	{
		if (is_ss(i) && n % i == 0)
		{
			while (n % i == 0)
			{
	printf ("%d\n", i);
	n = n / i;
			}
		}
	}
	if(n != 1)
		printf ("%d\n", n);
}