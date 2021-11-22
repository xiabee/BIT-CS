#include<stdio.h>
#include<string.h>
int a[3001] = { 0 }, b[3001] = { 0 };		//第i棵果树上有b[i]个桃子， 在a[i]天后成熟 
int day[1000010];	//记录当天成熟的桃子总数
int total = 0, flag = 0;						//记录摘得的总数； 
int main()
{
	int n, v, i, j, max_day = 0;		//max_day记录最大天数,v为一天内摘的最大数目 
	memset(day, 0, sizeof(day));
	scanf("%d%d", &n, &v);
	for (i = 0; i < n; i++)
	{
		scanf("%d%d", a + i, b + i);
		if (a[i] > max_day)
			max_day = a[i];
	}
	for (i = 0; i < n; i++)
		day[a[i]] += b[i];

	if (day[0] > v)			//第一天没摘完 
	{
		total += v;
		flag = 1;
		day[0] -= v;
	}
	else				//第一天全部摘完 
		total += day[0];
	for (i = 1; i < max_day + 2; i++)		//剩余
	{
		if (flag)			//前一天有剩余
		{
			if (day[i - 1] > v)	//前一天的依然没摘完 
			{
				total += v;
				flag = 1;
			}
			else
			{
				total += day[i - 1];
				if (v - day[i - 1] > day[i])
				{
					total += day[i];
					flag = 0;			//当天全部摘完； 
				}
				else
				{
					total += v - day[i - 1];
					day[i] -= v - day[i - 1];
					flag = 1;
				}
			}
		}
		else			//前一天的全部摘完 
		{
			if (day[i] > v)	//有剩余 
			{
				total += v;
				day[i] -= v;
				flag = 1;
			}
			else
			{
				total += day[i];
				flag = 0;
			}
		}
	}
	printf("%d\n", total);
	return 0;
}