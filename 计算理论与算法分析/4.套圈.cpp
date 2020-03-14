#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;
const int MAX = 1000005;
struct nmd {
	int id;
	double x, y;//不用int型，避免13、14行宽字节溢出
};
nmd pt[MAX];
int a[MAX];
double get_dis(nmd a, nmd b) {
	double delta_x = a.x - b.x;
	double delta_y = a.y - b.y;
	return sqrt(delta_x * delta_x + delta_y * delta_y);
}//计算两点距离
bool cmp(nmd a, nmd b) {
	return a.x == b.x ? a.y < b.y : a.x < b.x;
}//取x较小值，相等则取y较小值
bool cmp_y(int id1,int id2) {
	return pt[id1].y < pt[id2].y;
}//取y的较小值
double solve(int l, int r) {
	if (r == l + 1)
		return get_dis(pt[l], pt[r]);
	if (l + 2 == r)
		return min(get_dis(pt[l], pt[r]), min(get_dis(pt[l], pt[l + 1]), get_dis(pt[l + 1], pt[r])));
	int mid = (l + r) >> 1;
	double ans = min(solve(l, mid), solve(mid + 1, r));
	int i, j, cnt = 0;
	for (i = l; i <= r; i++)
		if (pt[i].x >= pt[mid].x - ans && pt[i].x <= pt[mid].x + ans)
			a[cnt++] = i;
	sort(a, a + cnt, cmp_y);
	for (i = 0; i < cnt; i++)
		for (j = i + 1; j < cnt; j++) {
			if (pt[a[j]].y - pt[a[i]].y >= ans) break;
			ans = min(ans, get_dis(pt[a[i]], pt[a[j]]));
		}
	return ans;
}	
int main() {
	int n, trs;
	//FILE* v = freopen("input.txt", "r", stdin);
	while (~scanf("%d", &n)) {
		if (n == 0)
			return 0;
		for (int i = 0; i < n; i++)
			trs = scanf("%lf%lf", &pt[i].x, &pt[i].y);
		sort(pt, pt + n, cmp);
		printf("%.2lf\n", solve(0, n - 1) / 2.0);
	}
	return 0;
}