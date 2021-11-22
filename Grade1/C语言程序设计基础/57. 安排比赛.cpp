#include <stdio.h>
int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		int n;
		scanf("%d", &n);
		if (n == 1) printf("0\n");
		else if (n % 2 == 0) printf("%d\n", n - 1);
		else printf("%d\n", n);
	}
}