#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main() {
	int a, num, trs, i;
	trs = scanf("%d", &num);
	for (i = 0; i < num; i++) {
		trs = scanf("%d", &a);
		printf("%d\n", (a - 1) % 3);
	}
	return 0;
}