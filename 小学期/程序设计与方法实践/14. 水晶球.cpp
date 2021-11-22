#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
struct qnmd
{
	long long a1;
	long long b1;
	long long c1;
	long long order;
}*LEN;

long long n, i, j, * r, max = 0, flag, flag1 = 0, rn, rm, sss, g1, g2;	//sss用于判断合并后的石头是否比原来大；
void swap(long long* a, long long* b);
int mmp(const void* p1, const void* p2);
int main()
{
	scanf("%lld", &n);
	r = (long long*)malloc(sizeof(long long) * n);
	LEN = (struct qnmd*)malloc(sizeof(struct qnmd) * (n + 1));
	memset(LEN, 0, sizeof(LEN));
	for (i = 0; i < n; i++)
	{
		scanf("%lld%lld%lld", &LEN[i].a1, &LEN[i].b1, &LEN[i].c1);//最终从小到大排序；
		LEN[i].order = i;
		if (LEN[i].a1 >= LEN[i].b1 && LEN[i].b1 >= LEN[i].c1)				//c<b<a;
			swap(&LEN[i].a1, &LEN[i].c1);
		if (LEN[i].b1 >= LEN[i].a1 && LEN[i].a1 >= LEN[i].c1)				//c<a<b;
		{
			swap(&LEN[i].a1, &LEN[i].c1);
			swap(&LEN[i].b1, &LEN[i].c1);
		}
		if (LEN[i].a1 >= LEN[i].c1 && LEN[i].c1 >= LEN[i].b1)			//b<c<a;
		{
			swap(&LEN[i].a1, &LEN[i].b1);
			swap(&LEN[i].b1, &LEN[i].c1);
		}
		if (LEN[i].c1 >= LEN[i].a1 && LEN[i].a1 >= LEN[i].b1)			//b<a<c;
			swap(&LEN[i].a1, &LEN[i].b1);
		if (LEN[i].b1 >= LEN[i].c1 && LEN[i].c1 >= LEN[i].a1)				//a<c<b;
			swap(&LEN[i].c1, &LEN[i].b1);
		if (LEN[i].c1 >= LEN[i].b1 && LEN[i].b1 >= LEN[i].a1);			//a<b<c;
					//求出每个半径:取最短边
		if (LEN[i].a1 > max)						
		{
			max = LEN[i].a1;						//记录单个最大半径；
			flag = i;
		}
	}
	qsort(LEN, n, sizeof(LEN[0]), mmp);		//从小到大排序；
	for (i = 0; i < n - 1; i++)				//寻找匹配的石头：让最短边变大，即b,c相等，aa相加；
	{
		if (LEN[i].c1 == LEN[i + 1].c1 && LEN[i].b1 == LEN[i + 1].b1)
		{
			rn = LEN[i].a1 + LEN[i + 1].a1;
			if (rn > LEN[i].b1)			//rn不是最短边
			{
				rm = LEN[i].b1;
				if (rm > max)
				{
					max = rm;
					sss = i;
					flag1 = 1;
				}
			}
			else if (rn > LEN[i].c1 && LEN[i].b1 > LEN[i].c1)			//rn不是最短边
			{
				rm = LEN[i].c1;
				if (rm > max)
				{
					max = rm;
					sss = i;
					flag1 = 1;
				}
			}
			else//rn为最短边
			{
				rm = rn;
				if (rm > max)
				{
					max = rm;
					sss = i;
					flag1 = 1;
				}
			}
		}
	}
	if (flag1)
	{
		g1 = LEN[sss].order;
		g2 = LEN[sss + 1].order;
		if (g1 < g2)
			printf("2\n%lld %lld\n", g1 + 1, g2 + 1);
		else
			printf("2\n%lld %lld\n", g2 + 1, g1 + 1);
	}
	else
		printf("1\n%lld\n", flag + 1);
	return 0;
}
void swap(long long* a, long long* b)
{ 
	*a ^= *b;
	*b ^= *a;
	*a ^= *b;
	return;
}

int mmp(const void* p1, const void* p2)
{
	struct qnmd* c = (qnmd*)p1;
	struct qnmd* d = (qnmd*)p2;
	if (c->c1 != d->c1)
	{
		return d->c1 < c->c1 ? 1 : -1;
	}
	else if (c->b1 != d->b1)
		return d->b1 < c->b1 ? 1 : -1;
	else 
		return d->a1 < c->a1 ? 1 : -1;
}