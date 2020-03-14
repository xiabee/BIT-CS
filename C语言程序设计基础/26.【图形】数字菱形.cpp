#include <stdio.h>
#include <math.h>

int main()
{
	int i, j, n;
	scanf ("%d", &n);
	for (j = 1; j <= n; j++)
	{ 
		i = 1;
		int space1 = n-j;
		int temp = n;
		for (i = 1; i <= space1; i ++) 
			printf ("  ");
		for (; i<= n; i++) 
			printf ("%-2d", temp--);
		temp++;
		for (; i<= j+n-1; i++) 
			printf ("%-2d", ++temp);
		printf ("\n");
	}
	j = j - 2;
	for (; j >= 1; j--)
	{ 
		i = 1;
		int space1 = n-j;
		int temp = n;
		for (i = 1; i <= space1; i ++) 
			printf ("  ");
		for (; i<= n; i++) 
			printf ("%-2d", temp--);
		temp++;
		for (; i<= j+n-1; i++) 
			printf ("%-2d", ++temp);
		printf ("\n");
	} 
	
	return 0;
}