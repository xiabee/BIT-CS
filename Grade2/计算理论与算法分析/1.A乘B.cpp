#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
const int maxn = 40020; char factorA[maxn], factorB[maxn]; int ans[maxn] = { 0 }; int a[maxn], b[maxn]; int tsh;
int main() {
	//FILE* vvv = freopen("input.txt", "r", stdin);
	tsh = scanf("%s%s", factorA,factorB);
	int lenA = strlen(factorA);
	int lenB = strlen(factorB);
	for (int i = 0; i < lenA; i++)
		a[i] = factorA[lenA - i - 1] - 48;
	for (int i = 0; i < lenB; i++)
		b[i] = factorB[lenB - i - 1] - 48;
	for (int i = 0; i < lenA; i++)
		for (int j = 0; j < lenB; j++)
			ans[i + j] += a[i] * b[j];//运算
	for (int i = 0; i < lenA + lenB; i++) {
		ans[i + 1] += ans[i] / 10;
		ans[i] %= 10;
	}//进位
	int len;
	if (lenA + lenB <= 1) {
		printf("0\n");
		exit(-1);
	}	
	if (ans[lenA + lenB -1]!=0)
		len = lenA + lenB - 1;
	else
		len = lenA + lenB - 2;
	for (int k = len; k >= 0; k--)
		printf("%d", ans[k]);
	printf("\n");
	return 0;
}