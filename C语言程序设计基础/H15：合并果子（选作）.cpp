// ConsoleApplication2.cpp: 定义控制台应用程序的入口点。
#include <stdio.h>
#include <stdlib.h>
int up(const void * a, const void * b)
{
	return *(int*)a - *(int*)b;
}
int bfind_db(int *a, int x, int y, int v)
{ 
	int m;
	while (x < y)
	{
		m = x + (y - x) / 2;
		if (a[m] >= v)  y = m;
		else  x = m + 1;
	}
	return x;
}
int main()
{
	int n, a[30000] = { 0 }, tot = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	qsort(a, n, sizeof(a[0]), up);
	for (int i = 1; i < n; i++)
	{
		int temp = a[i] + a[i - 1];
		int insert = bfind_db(a, i + 1, n, temp);
		if (insert == n)
		{
			for (int j = i + 1; j < n; j++)
	a[j - 1] = a[j];
			a[n - 1] = temp;
		}
		else 
		{
			for (int j = i + 1; j < insert; j++)
	a[j - 1] = a[j];
			a[insert - 1] = temp;
		}
		tot = tot + temp;
	}
	printf("%d\n", tot);
}