#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<iostream>
#include<algorithm>
using namespace std;
const int maxn = 2000000;
struct gg//用来存每一个时间节点
{
	long long time;
	int sys;//-1表示此点为起点，+1表示为终点
};
gg xz[maxn];
bool cmp(struct gg x, struct gg y)
{
	if (x.time != y.time)
		return x.time < y.time;
	else
		return x.sys > y.sys;
}
int trs;
void oper()
{
	int n;
	int sum = 0, ans = 0;//ans为最终的答案
	long long start, end;
	trs = scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		trs = scanf("%lld %lld", &start, &end);
		xz[sum].time = start;
		xz[sum++].sys = -1;
		xz[sum].time = end;
		xz[sum++].sys = 1;
	}
	sort(xz, xz + sum, cmp);
	int temp = 0;
	for (int i = 0; i < sum; i++)
	{
		if (xz[i].sys == -1)
			temp++;
		else if (xz[i].sys == 1)
			temp--;
		if (temp > ans)//更新最大值
			ans = temp;
	}
	printf("%d\n", ans);
	return;
}
int main()
{
	oper();
	return 0;
}
