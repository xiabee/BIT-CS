#include<stdio.h>
#include<string.h>
#include<stdlib.h>
long long n, q, i, j, k, kkk, total = 0, max = 0, didi = 0;
typedef struct nmb
{
	long long t;
	long long d;
}qnmd;
qnmd* XZ;
int mmp(const void* p1, const void* p2);
int main()
{
	total = 0;
	scanf("%lld%lld", &n, &q);
	XZ = (qnmd*)malloc(sizeof(qnmd) * (n + 1));
	memset(XZ, 0, sizeof(XZ));
	for (i = 0; i < n; i++)
	{
		scanf("%lld%lld", &XZ[i].t, &XZ[i].d);
		total += XZ[i].d;
	}
	qsort(XZ, n, sizeof(XZ[0]), mmp);
	for (i = 0; i < q; i++)
	{
		max = 0;
		didi = 0;
		//didi = 0;
		scanf("%lld", &kkk);
		j = 0;
		k = 0;
		while (k < n)
		{
			if (XZ[k].t - XZ[j].t < kkk)
			{
				didi += XZ[k].d;
				k++;
				if (didi > max)
					max = didi;
			}
			if (XZ[k].t - XZ[j].t >= kkk)
			{
				didi -= XZ[j].d;
				j++;
			}
		}

		printf("%lld\n", total - max);
	}
	return 0;
}

int mmp(const void* p1, const void* p2)
{
	qnmd* ccc = (nmb*)p1;
	qnmd* ddd = (nmb*)p2;
	if (ddd->t != ccc->t)
		return ddd->t < ccc->t ? 1 : -1;
	else
		return ddd->d < ccc->d ? 1 : -1;
}