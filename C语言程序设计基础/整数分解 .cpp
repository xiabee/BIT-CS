#include <stdio.h>
int main()
{
	int n, ok = 0;
	scanf("%d", &n);
	for (int i = 1; i <= n / 2; i++)
	{ 
		int temp = i, j;
		for ( j = i + 1; temp < n; j++)
			temp += j;
		if (temp == n)
		{
			ok = 1;
			printf("%d~%d\n", i, j - 1);
		}
	}
	if (!ok)
		printf("None\n");
}