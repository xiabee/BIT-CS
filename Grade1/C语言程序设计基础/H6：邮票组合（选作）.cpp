#include <stdio.h>
int data[10000];
int main()
{
	int n1, n2, n3, n4, a, b, c, d, total, sum, lx=0, i;
	scanf ("%d %d %d %d", &a, &b, &c, &d);
	for (n1 = 0; n1 <= 5; n1 ++)
	{
		for (n2 = 0; n2 <= 5-n1; n2++)
		{
			for (n3 = 0; n3 <= 5-n1-n2; n3++)
			{
	for (n4 = 0; n4 <= 5-n1-n2-n3; n4++)
	{
	 sum = a*n4 + b*n3 + c*n2 + d*n1;
	 data[sum] = sum;
	 //printf ("%d\n", data[sum]);
	}
			}
		}
	}
	for (i=1; data[i] == i; i++);
	printf ("The max is %d.\n", i-1);
	
}