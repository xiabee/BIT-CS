#include <stdio.h>
int main()
{
	int a[25], n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	int mid = (n - 1) / 2;
	for (int i = 0; i <= mid; i++)
	{
		if (i == n - 1 - i)
			printf("%d \n", a[i]);
		else
		{
			int temp = a[i] * a[n - 1 - i];
			if (i == mid)
	printf("%d \n", temp);
			else
	printf("%d ", temp);
		}
	}
}