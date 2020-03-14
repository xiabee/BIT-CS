#include  <stdio.h>

int main()
{
	int n, i = 1, h = 1,l = 1 ;
	scanf ("%d", &n);
	for (; l <= n; l++)
	{ 
		h = 1;
		for (; h <= n; h++)
		{
			printf ("%3d", i++);
		}
		printf ("\n");
	}
	
	
	return 0;
}