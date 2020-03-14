#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAX 100005
#define INF 999999
long long sum = 0, ans = 0, i, j1, j2, k, num, n, ink[MAX], ink1[MAX], s1, s2, s3, s;
int v;
long long findmin(long long a, long long b, long long c);
int mmp(const void* p1, const void* p2);
int main()
{
	memset(ink, INF, sizeof(ink));
	memset(ink1, INF, sizeof(ink1));
	v = scanf("%lld", &n);
	while (n--)
	{
		v = scanf("%lld", &num);
		if (num == 1)
		{
			v = scanf("%lld", &num);
			printf("0\n");
			continue;
		}
		for (i = 0; i < num; i++)
			v = scanf("%lld", &ink[i]);
		qsort(ink, num, sizeof(long long), mmp);
		j1 = 0;
		j2 = 0;
		ans = 0;
		for (i = 0; i <num-1; i++)
		{
			s1 = ink[j1] + ink[j1 + 1];
			s2 = ink[j1] + ink1[j2];
			s3 = ink1[j2] + ink1[j2 + 1];
			s = findmin(s1, s2, s3);
			if (s1 == s)
				j1 += 2;
			else if (s2 == s)
			{
				j1++;
				j2++;
			}
			else
				j2 += 2;
			ink1[i] = s;//用ink1记录合并后的值；
			ans += s;
			//printf("%lld\n", s);
		}
		printf("%lld\n", ans);
		memset(ink, INF, sizeof(ink));
		memset(ink1, INF, sizeof(ink1));
	}
	return 0;
}
long long findmin(long long a, long long b, long long c)
{
	if (a <= b && a <= c)
		return a;
	else if (b <= a && b <= c)
		return b;
	else
		return c;
}
int mmp(const void* p1, const void* p2)
{
	return *(long long*)p1 - *(long long*)p2;
}