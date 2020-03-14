#include <stdio.h>
#include <stdlib.h>
int up(const void *a, const void *b)
{
	return *(int*)a - *(int*)b;
}
int main()
{
	int n, a[1005], r;
	scanf("%d %d", &n, &r);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	qsort(a, n, sizeof(int), up);
	for (int i = 0; i < n; i++)
	{
		if (r > a[i])
			continue;
		else
		{
			r += 2;
			a[i] = 0;
		}
	}
	for (int i = 0; i < n; i++)
	{
		if (a[i] > 0)
			r++;
	}
	printf("%d\n", r);
}