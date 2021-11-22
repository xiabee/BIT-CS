#include <stdio.h>
int main()
{
	int n, ok = 0;
	scanf ("%d", &n);
	int n1, n2, n3;
	for (n3 = 1; n3 <= n*10; n3++)
	{
		if (n3 * 20 % 15 == 0 && n3 * 20 % 18 == 0)
		{
			n2 = n3 * 20 / 15;
			n1 = n3 * 20 / 18;
			if (10*n3 + 5 * n2 + n1 == n*100)
			{
	ok = 1;
	break;
			}
		}  
	}
	if (ok) printf ("%d,%d,%d\n", n1, n2, n3);
	else printf ("No change.\n");
	return 0;
}