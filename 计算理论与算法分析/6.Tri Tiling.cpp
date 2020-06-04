#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main()
{
	long long int mm[32] = { 0 }, a, i;
	mm[0] = 1;//定边界条件
	mm[2] = 3;
	for (i = 4; i < 32; i = i + 2) 
		mm[i] = 4 * mm[i - 2] - mm[i - 4];//=======f(n)-f(n-2) ；
	while (scanf("%lld", &a) != EOF && a != -1) 
		printf("%lld\n", mm[a]);
	return 0;
}