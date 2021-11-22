#include <stdio.h>
int main()
{
	int n, flag = 0;
	scanf ("%d", &n);
	for (int i = 1; i <= 9; i++)
	{
		for (int j = 1; j <= 9; j++)
		{ 
			int a[15] = {0}, ok = 1;
			int temp1 = n*100 + i*10 + j;
			int temp2 = temp1*2;
			int temp3 = temp1*3;
			int n1 = temp1, n2 = temp2, n3 = temp3;
			while (temp1)
			{
	a[temp1%10] = temp1 % 10;
	a[temp2%10] = temp2 % 10;
	a[temp3%10] = temp3 % 10;
	temp1 = temp1 / 10;
	temp2 = temp2 / 10;
	temp3 = temp3 / 10;
			}
			for (int i = 1; i <= 9; i++)
			{
	if (a[i] == 0)
	 ok = 0;
			}
			if (ok)
			{
	flag = 1;
	printf ("%d,%d,%d\n", n1, n2, n3);
			}
		}
	}
	if (!flag)
		printf ("0,0,0\n");
}