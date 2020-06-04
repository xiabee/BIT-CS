#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int inf = 0x3f3f3f3f;
const int maxn = 310;
int n, num[maxn], len[maxn], option1[maxn], option2[maxn];
int dp[maxn][maxn][2];
int nsum(int i, int j) 
{
	int tmp = (i != 0); j = n - j;
	return option2[j] - option2[i - tmp];
}
int lsum(int i, int j) 
{
	return option1[j] - option1[i];
}
int dfs(int i, int j, int pos) 
{
	if (dp[i][j][pos] != inf) 
		return dp[i][j][pos];
	if (i + j >= n) 
		return dp[i][j][pos] = 0;
	if (pos == 1) 
	{
		dp[i][j][1] = min(dp[i][j][1], dfs(i, j + 1, 1) + len[n - (j + 1)] * nsum(i, j + 1));
		dp[i][j][1] = min(dp[i][j][1], dfs(i, j + 1, 0) + (option1[i] + lsum(n - j, n)) * nsum(i, j + 1));
	}
	else 
	{
		dp[i][j][0] = min(dp[i][j][0], dfs(i + 1, j, 0) + len[i] * nsum(i + 1, j));
		dp[i][j][0] = min(dp[i][j][0], dfs(i + 1, j, 1) + (option1[i] + lsum(n - j, n)) * nsum(i + 1, j));
	}
	return dp[i][j][pos];
}
void opper(int n)
{
	int trs;
	for (int i = 0; i < n; i++)
		trs = scanf("%d%d", &num[i], &len[i]);
	option1[0] = option2[0] = num[n] = 0;
	for (int i = 1; i <= n; i++)
	{
		option1[i] = option1[i - 1] + len[i - 1];
		option2[i] = option2[i - 1] + num[i];
	}
	memset(dp, inf, sizeof(dp));
	int ans = min(dfs(0, 0, 0), dfs(0, 0, 1));
	printf("%d\n", ans);
}
int main() {
	
	while (~scanf("%d", &n)) 
	{
		if (!n)	
			break;
		if (n > maxn)
			exit(0);
		opper(n);
	}
	return 0;
}