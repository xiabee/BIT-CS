#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAXGG 2147483647//最大数....题目让我取余我就取余
long long dp[2002][2035];//不知道第二维有多大，就随便试一下.......不知道会不会爆
long long ggam[2002];
int vvv;//用于记录scanf返回值
long long i, j, gg_left, gg_right, ans_gg = 0;
long long n;
int main()
{
	vvv = scanf("%lld", &n);//输入总数
	for (i = 0; i <= n; i++)//第一项输入了两个，所以多输入一项
		vvv = scanf("%lld", &ggam[i]);
	dp[1][ggam[0]] = 1;//初始化，第一块木板的尾部只有一个位置
	for (i = 2; i <= n; i++)//第一行已经赋值，不用再计算
	{
		for (j = 1; j <= n + 1; j++)//gg_left为上一层的左端点，gg_right为右端点（这里不再区分头和尾是怕混淆）
		{
			if (j < ggam[i - 1])//比较大小，区分左右端
			{
				gg_left = j;
				gg_right = ggam[i - 1];
			}
			else//比较大小，区分左右端
			{
				gg_left = ggam[i - 1];
				gg_right = j;
			}
			if (ggam[i] > gg_left)//比较大小，区分左右端
			{
				dp[i][gg_left] += dp[i - 1][j];
				dp[i][gg_left] %= MAXGG;//每次计算直接取余，防止爆掉
			}
			if (ggam[i] < gg_right)//比较大小，区分左右端
			{
				dp[i][gg_right] += dp[i - 1][j];
				dp[i][gg_right] %= MAXGG;//每次计算直接取余，防止爆掉/gg
			}
		}
	}

	for (i = 1; i <= n + 1; i++)//从第二行开始爆算
	{
		ans_gg += dp[n][i];
		ans_gg %= MAXGG;//每次计算直接取余，防止爆掉/gg
	}
	printf("%lld\n", ans_gg);
	return 0;//程序君您休息/cy
}