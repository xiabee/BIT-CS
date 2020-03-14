#include<stdio.h>
int main()
{
	int t, n, v;
	v = scanf("%d", &t);
	while (t--) {
		v = scanf("%d", &n);
		printf("%d\n", ((n / 2) * ((n / 2) - 1)) / 2 + (n - (n / 2)) * (n - (n / 2) - 1) / 2);}
	return 0;}