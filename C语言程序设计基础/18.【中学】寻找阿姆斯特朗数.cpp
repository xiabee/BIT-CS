#include <stdio.h>
#include <math.h>

void  main()
{
	int n, i, a[6], sum, j, flag = 0;
	scanf ("%d", &n);
	
	for (i = pow(10, n-1); i < pow(10, n); i++)
	{ 
		sum = 0;
		for (j = 0; j < n; j++)
		{
			int temp = i / pow(10, j);
			a[j] = temp % 10;
			sum = sum + pow(a[j], n);
		}
	
		if (sum == i)  
		{ 
			flag = 1;
			printf ("%d\n", i);
		}
	}
	
	if (flag == 0)  printf ("No output.\n");
}