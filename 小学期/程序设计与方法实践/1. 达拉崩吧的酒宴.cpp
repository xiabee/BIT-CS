#include<stdio.h>
#include<math.h>
long long wine[10001];//储存酒桶；
int main()
{
	int total, i, mouse;
	scanf("%d", &total);
	for (i = 0; i < total; i++)
	{
		scanf("%lld", &wine[i]);
		for (mouse = 0;; mouse++)
			if (wine[i] <= pow(2, mouse))//计算2的mouse次方 
			{
				printf("%d\n", mouse);
				break;
			}
	}
	return 0;
}