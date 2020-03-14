#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int cmp1(const void* a, const void* b);
long long abs1(long long n);
int n, i, j, k;
//long long x[100010], y[100010];
long long* x, * y;
long long sumx = 0, sumx1 = 0, sumx2 = 0, sumy = 0, sumy1 = 0, sumy2 = 0, sum = 0;
int main()
{
	scanf("%d", &n);
	x = (long long*)malloc(sizeof(long long) * n);
	y = (long long*)malloc(sizeof(long long) * n);
	memset(x, 0, sizeof(x));
	memset(y, 0, sizeof(y));
	for (i = 0; i < n; i++)
		scanf("%lld %lld", &x[i], &y[i]);
	qsort(x, n, sizeof(long long), cmp1);
	qsort(y, n, sizeof(long long), cmp1);
	for (i = 0; i < n; i++)					//最终y值相同，直接相加；
	{
		sumy1 += abs1(y[i] - y[n / 2]);
		sumy2 += abs1(y[i] - y[n / 2 + 1]);
	}
	sumy = sumy1 < sumy2 ? sumy1 : sumy2;

	for (i = 0; i < n; i++)
		x[i] -= (i + 1);
	qsort(x, n, sizeof(long long), cmp1);
	for (i = 0; i < n; i++)					//最终y值相同，直接相加；
	{
		sumx1 += abs1(x[i] - x[n / 2]);
		sumx2 += abs1(x[i] - x[n / 2 + 1]);
	}
	sumx = sumx1 < sumx2 ? sumx1 : sumx2;
	sumx = sumx1 < sumx2 ? sumx1 : sumx2;
	printf("%lld\n", sumx + sumy);
	return 0;
}

int cmp1(const void* a, const void* b)
{
	return (*(int*)a - *(int*)b);
}
long long abs1(long long n)
{
	if (n >= 0)
		return n;
	else
		return -n;
}