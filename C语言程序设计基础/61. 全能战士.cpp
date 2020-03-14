#include<stdio.h>
int main()
{
	int n, n1, n2, n3, n12, n23, n13;
	scanf("%d %d %d %d %d %d %d", &n, &n1, &n2, &n3, &n12, &n23, &n13);
	int r = n1 + n2 + n3 - n12 - n23 - n13;
	printf("%d\n",  n - r);
}