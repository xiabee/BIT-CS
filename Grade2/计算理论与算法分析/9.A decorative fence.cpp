#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<cstdio>
#include <cstring>
using namespace std;
int t, n;
long long c;
long long dp[25][25][2];
void init() {
	memset(dp, 0, sizeof(dp));
	dp[1][1][0] = dp[1][1][1] = 1;//正向反向初值
	for (int i = 2; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			for (int k = j; k < i; k++) {
				dp[i][j][0] += dp[i - 1][k][1];
			}
			for (int k = 1; k < j; k++) {
				dp[i][j][1] += dp[i - 1][k][0];
			}
		}
	}
}
int res[25];
int vis[25];
void oper()
{
	int trs = scanf("%d%lld", &n, &c);
	init();
	memset(res, 0, sizeof(res));
	memset(vis, 0, sizeof(vis));
	int no = 0;
	long long s = 0;
	for (int cur = 1; cur <= n; cur++) {
		no = 0;
		for (int i = 1; i <= n; i++) {
			if (!vis[i]) {
				++no;
				long long num = 0;
				if (cur == 1)
					num = dp[n][no][0] + dp[n][no][1];
				else {
					if (i > res[cur - 1] && (cur <= 2 || res[cur - 2] > res[cur - 1])) {
						num += dp[n - cur + 1][no][1];
					}
					else if (i < res[cur - 1] && (cur <= 2 || res[cur - 2] < res[cur - 1])) {
						num += dp[n - cur + 1][no][0];
					}
				}
				s += num;
				if (s >= c) {
					s -= num;
					res[cur] = i;
					vis[i] = 1;
					break;
				}
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		printf("%d%c", res[i], i == n ? '\n' : ' ');//输出
	}
}
int main() {
	int t, trs;
	trs = scanf("%d", &t);
	while (t--) {
		oper();
	}
}