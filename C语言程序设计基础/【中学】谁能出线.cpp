#include <stdio.h>
int main()
{
	int a[15];
	for (int i = 1; i <= 10; i++)
		scanf("%d", &a[i]);
	int max = 0;
	for (int i = 1; i <= 10; i++)
	{
		if (a[i] > max)
			max = a[i];
	}
	for (int i = 1; i <= 10; i++)
	{
		if (a[i] == max)
			printf("%d\n", i);
	}
}