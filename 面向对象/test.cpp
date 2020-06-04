#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
long long x, y, n;
const int maxn = 200005;
typedef struct sss
{
	int scl;
	int fx;
}node;
node xz[maxn];

int cmp(const void* a, const void* b) {          //scl从大到小,fx从小到大
	struct sss* c = (sss*)a;
	struct sss* d = (sss*)b;
	if (c->scl != d->scl)  
		return d->scl - c->scl;
	else    
		return c->fx - d->fx;
}

int main()
{
	int trs;
	int k, n;
	int sum_scl = 0, sum_fx = 0;
	trs = scanf("%d%d", &k, &n);
	for (int i = 0; i < n; i++)
		trs = scanf("%d", &xz[i].fx);
	for (int i = 0; i < n; i++)
		trs = scanf("%d", &xz[i].scl);
	qsort(xz, n, sizeof(xz[0]), cmp);
	for (int i = 0; i < k; i++)
	{
		sum_scl += xz[i].scl;
		sum_fx += xz[i].fx;
	}
	printf("%d %d\n", sum_fx, sum_scl);
	return 0;
}