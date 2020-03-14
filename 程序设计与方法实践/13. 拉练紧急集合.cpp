#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define INF 200000000000000001
long long aabs(long long n);
long long m, n, c, d, i, j, k, sum = 0, sum1[4], maxx = 0, maxy = 0, minx = 0, miny = -INF, flag, flag1, flag2, flag3, flag4, min = INF, gg = 0;
long long* x, * y, * x1, * y1;
int main()
{
	scanf("%lld %lld", &m, &n);
	scanf("%lld", &c);							//记录宿舍楼数量
	x = (long long*)malloc(sizeof(long long) * c);
	y = (long long*)malloc(sizeof(long long) * c);
	memset(x, 0, sizeof(x));
	memset(y, 0, sizeof(y));
	memset(sum1, 0, sizeof(sum1));
	for (i = 0; i < c; i++)
	{
		scanf("%lld %lld", &x[i], &y[i]);	//记录宿舍楼坐标；
		if (x[i] > m || y[i] > n)
		{
			x[i] = -1;
			y[i] = -1;							//超出学校范围，舍弃；
		}
		if (x[i] + y[i] > maxx)
		{
			maxx = x[i] + y[i];
			flag1 = i;
		}
		if (x[i] - y[i] > minx && x[i] >= 0)
		{
			minx = x[i] - y[i];
			flag2 = i;
		}
		if (y[i] - x[i] > maxy)
		{
			maxy = y[i] - x[i];
			flag3 = i;
		}
		if (-y[i]-x[i] > miny && y[i] >= 0)
		{
			miny = -y[i] - x[i];
			flag4 = i;
		}
	}
	scanf("%lld", &d);							//记录集合点数量；
	x1 = (long long*)malloc(sizeof(long long) * d);
	y1 = (long long*)malloc(sizeof(long long) * d);
	memset(x1, 0, sizeof(x1));
	memset(y1, 0, sizeof(y1));
	for (i = 0; i < d; i++)
	{
		scanf("%lld %lld", &x1[i], &y1[i]);
		if (x1[i] > m || y1[i] > n)
		{
			x1[i] = -1;							//超出学校范围，舍弃；
			y1[i] = -1;
		}
	}
	for (i = 0; i < d; i++)
	{
		if (x1[i] >= 0 && y1[i] >= 0)
		{
			sum1[0] = aabs(x1[i] - x[flag1]) + aabs(y1[i] - y[flag1]);
			sum1[1] = aabs(x1[i] - x[flag2]) + aabs(y1[i] - y[flag2]);
			sum1[2] = aabs(x1[i] - x[flag3]) + aabs(y1[i] - y[flag3]);
			sum1[3] = aabs(x1[i] - x[flag4]) + aabs(y1[i] - y[flag4]);
			sum = sum1[0];
			for (j = 0; j < 4; j++)
			{
				if (sum1[j] > sum)
					sum = sum1[j];			//找出边界点到集合点的最远距离；
			}
		}
		if (sum < min)
		{
			min = sum;						//找出sum的最小值；
			flag = i;
		}
	}
	//printf("%lld\n", flag);
	for (i = 0; i < c; i++)
	{
		sum = aabs(x[i] - x1[flag]) + aabs(y[i] - y1[flag]);
		if (sum > gg)
			gg = sum;
	}
	printf("%lld\n", gg);
	return 0;
}

long long aabs(long long n)
{
	if (n >= 0)
		return n;
	else
		return -n;
}