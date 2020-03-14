#include<stdio.h>
#include<string.h>
#include<stdlib.h>
long long find(long long* a, long long min, long long max);//找出最大高度 
long long sum(long long* a, long long flag);

long long j, len, total;
long long max = 0, flag, min;	//找到中间最高点,以及左右两边的次高点 
long long* height = NULL;		//定义高度指针;
long long* p;
int main()
{
	int T, i, j, k;
	scanf("%d", &T);
	for (i = 0; i < T; i++)
	{
		total = 0;
		scanf("%lld", &len);
		height = (long long*)malloc(len * sizeof(long long int));
		for (j = 0; j < len; j++)
			scanf("%lld", &height[j]);							//输入 

		flag = find(height, 0, len);							//寻找最高
		total += sum(height, flag);
		printf("%lld\n", total);
		free(height);
	}
	return 0;
}

long long find(long long* a, long long min, long long max)		//寻找最高 
{
	long long l, GG = 0, gg = 0;
	for (l = min; l < max; l++)
		if (a[l] > GG)
		{
			GG = a[l];
			gg = l;
		}
	return gg;
}

long long sum(long long* a, long long flag)
{
	long long j, sum_1 = 0, sum_2 = 0;
	for (j = 0; j < len; j++)		//先求原大小 
		sum_1 += a[j];

	for (j = 1; j < flag; j++)
		if (a[j] < a[j - 1])
			a[j] = a[j - 1];

	for (j = len - 2; j > flag; j--)
		if (a[j] < a[j + 1])
			a[j] = a[j + 1];

	for (j = 0; j < len; j++)//灌水后的大小 
		sum_2 += a[j];
	return sum_2 - sum_1;
}