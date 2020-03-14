#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <cmath>

using namespace std;
const int mod = 1e4;
long long tmp[5][5];

void multy(long long a[][4],long long b[][4]){
	memset(tmp,0,sizeof tmp);
	for(int i = 1;i <= 2;i++)
		for(int j = 1;j <= 2;j++)
			for(int k = 1;k <= 2;k++){
				tmp[i][j] += a[i][k] * b[k][j];
				tmp[i][j] %= mod;
			}
}
long long quick(long long x){
	long long ans[4][4];
	memset(ans,0,sizeof ans);
	for(int i = 1;i <= 2;i++)
		ans[i][i] = 1;
	long long res[4][4];
	res[1][1] = 1;
	res[1][2] = 1;
	res[2][1] = 1;
	res[2][2] = 0;
	while(x){
		if(x & 1){
			multy(ans,res);
			for(int i = 1;i <= 2;i++)
			for(int j = 1;j <= 2;j++)
				ans[i][j] = tmp[i][j];
		}
		multy(res,res);
		for(int i = 1;i <= 2;i++)
			for(int j = 1;j <= 2;j++)
				res[i][j] = tmp[i][j];
		x /= 2;
	}
	return ans[2][1] % mod;
}
int main () {
	long long n;
	while(scanf("%lld",&n)!= EOF && n!= -1)
	{
		printf ("%lld\n", quick(n));
	}
	return 0;
}

