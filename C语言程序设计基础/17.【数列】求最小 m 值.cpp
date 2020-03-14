#include  <stdio.h>

int main()
{
	int n, m = 0, sum = 0;
	scanf ("%d", &n);
	
	while (sum < n)
	{ 
		m++;
		sum = sum + m; 
	}
	
	printf ("%d\n", m);
	return 0;
}