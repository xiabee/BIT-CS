#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstring> 
using namespace std;
const int maxn = 2000;
int p[maxn]; int m[maxn][maxn] = { 0 }, s[maxn][maxn] = { 0 }; int n;
void matrixchain() {
	int i, j, k, r;
	for (r = 2; r <= n; r++)
		for (i = 1; i <= n - r + 1; i++) {
			j = i + r - 1;
			m[i][j] = m[i + 1][j] + p[i - 1] * p[i] * p[j];//表格赋值
			s[i][j] = i;//储存决策点
			for (k = i + 1; k < j; k++) {
				int t = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
				if (t < m[i][j]) {
					m[i][j] = t;
					s[i][j] = k;
				}
			}
		}
	return;
}
void print(int i, int j) {
	if (i == j) {
		cout << "A" << i;
		return;
	}
	cout << "(";
	print(i, s[i][j]);
	print(s[i][j] + 1, j);//递归1到s[i][j]
	cout << ")";
	return;
}
int main() {
	std::ios::sync_with_stdio(false);
	cin >> n;
	int i, j;
	for (i = 0; i <= n; i++)
		cin >> p[i];
	if (n == 1) {
		cout << "0" << endl << "(A1)" << endl;
		return 0;
	}
	matrixchain();
	cout << m[1][n] << endl;
	print(1, n);
	cout << endl;
	return 0;
}