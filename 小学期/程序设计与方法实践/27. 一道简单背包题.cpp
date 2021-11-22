#include<stdio.h>
#include<string.h>
#include<stdlib.h>
long long ptemp;//记录输入大小
long long dp[4005];//存储两遍输入，翻倍储存
int n, v, i, j;
int vvv;
int main()
{
	dp[0] = 1;//设置初始条件，首项为1
	vvv = scanf("%d%d", &n, &v);//记录scanf返回值
	for (i = 1; i <= n; i++) //开始寻找
	{
		vvv = scanf("%lld", &ptemp);//记录scanf返回值
		ptemp = ptemp % v;
		if (ptemp == 0)
			ptemp = v;
		for (j = 2 * v; j >= ptemp; j--) 
			dp[j] = (dp[j] + dp[j - ptemp]) % 10000000;//条件转移方程//每次计算全部取余
		for (j = 2 * v; j >= ptemp; j--) 
		{
			if (j > v) 
			{
				dp[j - v] = (dp[j - v] + dp[j]) % 10000000;//条件转移方程//每次计算全部取余
				dp[j] = 0;//计算后归零
			}
		}
	}
	printf("%lld\n", dp[v] % 10000000);
	return 0;
}