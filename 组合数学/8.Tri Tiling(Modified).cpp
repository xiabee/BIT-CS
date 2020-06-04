#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
const int maxn = 1e7;
const int mod = 9973;
unsigned int mm[maxn] = { 0 }, input, cnt;

int main()
{
	mm[0] = 1;//定边界条件
	mm[2] = 3;
	for (cnt = 4; cnt < 32; cnt = cnt + 2)
	{
		mm[cnt] = 4 * mm[cnt - 2] - mm[cnt - 4];//=======f(n)-f(n-2)
		mm[cnt] %= mod;
	}
	while (scanf("%d", &input) != EOF && input != -1)
		printf("%d\n", mm[input]);
	return 0;
}