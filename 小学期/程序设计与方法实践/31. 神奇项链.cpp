#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int v, T, i, j, k, K, n;
#define maxn 100000
long long f[5][maxn];
long long sum;
int main()
{
	v = scanf("%d", &T);
	while (T--)//T组用例
	{
		v = scanf("%d%d", &n, &K);
		for (i = 1; i <= K; i++)
		{
			f[1][i] = 1;
			for (j = 2; j <= K; j++)
			{
				f[2][j] = 1;

			}
		}
	}
}