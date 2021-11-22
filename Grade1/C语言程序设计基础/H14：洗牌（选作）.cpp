#include<stdio.h>
int main()
{
	int n, i, a[100000] = {0}, b[100000] = {0}, tot = 0;
	scanf ("%d", &n);
	n = n * 2;
	int half = n / 2;
	for (i = 1; i <= n; i++)
		a[i] = i;
	while (1)
	{ 
		int j = 1, o = 2;
		for (i = half + 1; i <= n; i++, j = j + 2)
			b[j] = a[i];
		for (i = 1; i <= half; i++, o = o + 2)
			b[o] = a[i];
		for (i = 1; i <= n; i++)
			a[i] = b[i];
		tot++;
		
		/*for (i = 1; i <= n; i++)
			printf("%d ", a[i]);
		printf ("\n");*/
		
		for (i = 1; a[i] == i; i++);
		if (i == n + 1)
			break;
	}
	printf ("%d\n", tot);
}