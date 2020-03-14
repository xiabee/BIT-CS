#include <stdio.h>
int main()
{
	int n, a[100], i = 0;
	scanf ("%d", &n);
	while (n > 0)
	{
		a[i++] = n % 10;
		n = n / 10;
	}
	int ws = i;
	for (int j = 1; j <= ws-1; j++)
	{
		for (i = 0; i + 1 < ws; i++)
		{
			if (a[i] <= a[i+1])
			{
	int temp ;
	temp = a[i];
	a[i] = a[i+1];
	a[i+1] = temp;
			}
		}
	}
	for (i = 0; i < ws; i++)
		printf ("%d", a[i]);
	printf ("\n");
}