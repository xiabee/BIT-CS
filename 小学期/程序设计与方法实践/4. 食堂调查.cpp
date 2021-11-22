#include<stdio.h>
#include<string.h>
#define MAX 1000500
int max = 0, min = MAX;
long long n, i;
long long s, t;		//s<t;
long long time[MAX] = { 0 };
int main()
{
	long long maxstu = 0;
	scanf("%lld", &n);
	for (i = 0; i < n; i++)
	{
		scanf("%lld%lld", &s, &t);
		time[s]++;
		time[t + 1]--;
		if (t > max)
			max = t;
		if (s < min)
			min = s;
	}
	for (i = min; i <= max; i++)
	{
		time[i] += time[i - 1];
		if (time[i] > maxstu)
			maxstu = time[i];
	}
	printf("%lld\n", maxstu);
	return 0;
}