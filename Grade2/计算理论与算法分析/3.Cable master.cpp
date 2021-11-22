#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
using namespace std;
const int maxn = 10005;
const double esp = 1e-8;
double cables[maxn];

bool check(double mid, long long n, long long k) {
	long long ans = 0;
	for (long long i = 0; i < n; i++)
		ans += cables[i] / mid;
	return ans >= k;
}
int main() {
	long long n, k;
	cin >> n >> k;
	double maxr = 0, l = 0, r, mid;
	for (long long i = 0; i < n; i++) {
		cin >> cables[i];
		cables[i] += 0.005;//补充精度损失
		maxr = max(cables[i], maxr);
	}
	r = maxr;
	while (l + esp < r) {//二分寻找最长分割长度
		mid = (l + r) / 2;
		if (check(mid, n, k))
			l = mid;
		else
			r = mid;
	}
	printf("%.2f\n", floor(l * 100) / 100);
	return 0;
}