#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
const int maxn = 1e5 + 10;
typedef long long ll;
ll vis[maxn], re[maxn];
int main() {
	//FILE* v = freopen("input.txt", "r", stdin);
	std::ios::sync_with_stdio(false);
	ll n, m;
	while (cin >> n >> m) {
		if (!n && !m) {
			break;
		}
		ll sum = 0, t;
		memset(vis, 0, sizeof(vis));
		for (ll i = 1; i <= m; i++) {
			cin >> re[i];
		}
		for (ll i = 1; i <= m; i++) {
			sum += re[i];
			t = sum % n;//t为余数
			if (t == 0) {//直接除尽的情况
				for (ll j = 1; j < i; j++) {
					cout << j << " ";
				}
				cout << i << endl;
				break;
			}
			else if (vis[t]) {  //如果余数在前面出现过，现在又出现了，则中间一定加了n的倍数
				for (ll j = vis[t] + 1; j < i; j++) {
					cout << j << " ";
				}
				cout << i << endl;
				break;
			}
			vis[t] = i;
		}
	}
	return 0;
}