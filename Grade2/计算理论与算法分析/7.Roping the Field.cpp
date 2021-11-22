#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<cmath>
#include<iostream>
#include <algorithm>

using namespace std;
const double esp = 1e-6;
const int maxn = 155;
int n, m;
double R;
typedef struct node
{
	double x;
	double y;
}point;
point a[maxn], b[maxn];
int ans[maxn][maxn];
bool vis[maxn][maxn];

double dis(point u, point v)
{
	return sqrt((u.x - v.x) * (u.x - v.x) + (u.y - v.y) * (u.y - v.y));
}//计算两点间的距离

double DIS(point u, point v, point w)
{
	double a, b, c;
	a = dis(u, v);
	b = dis(u, w);
	c = dis(v, w);
	if (c <= esp || b <= esp)
		return 0;
	if (a <= esp)
		return b;
	if (c * c >= a * a + b * b)
		return b;
	if (b * b >= a * a + c * c)
		return c;
	double p = (a + b + c) / 2;//三角形周长的一半
	double s = sqrt(p * (p - a) * (p - b) * (p - c));//三角形面积
	return 2 * s / a;//三角形的高
}//返回点线距

bool judge(point u, point v, point w)
{
	double d1 = DIS(u, v, w);
	if (d1 > R)
		return 0;
	return 1;
}//判断是否穿过圆形

bool check(point u, point v)
{
	for (int i = 1; i <= m; i++)
		if (judge(u, v, b[i]))
			return 0;
	return 1;
}

int main()
{
	//FILE* sss = freopen("input.txt", "r", stdin);
	int trs;
	trs = scanf("%d%d%lf", &n, &m, &R);
	for (int i = 1; i <= n; i++)
		trs = scanf("%lf%lf", &a[i].x, &a[i].y);
	for (int i = 1; i <= m; i++)
		trs = scanf("%lf%lf", &b[i].x, &b[i].y);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
		{
			if (i == j)
				continue;
			vis[i][j] = check(a[i], a[j]);
		}
	for (int len = 3; len <= n; len++)
		for (int i = 1; i <= n - len + 1; i++)
		{
			for (int j = i; j <= i + len - 1; j++)
				ans[i][i + len - 1] = max(ans[i][i + len - 1], ans[i][j] + ans[j][i + len - 1]);
			if (vis[i][i + len - 1] && (i != 1 || i + len - 1 != n))
				ans[i][i + len - 1]++;
		}
	printf("%d\n", ans[1][n]);
	return 0;

}