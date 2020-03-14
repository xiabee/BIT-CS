#include <stdio.h>
#include <math.h>
int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		int n, a[105][2];
		scanf("%d", &n);
		for (int i = 0; i < n; i++)
			scanf("%d %d", &a[i][0], &a[i][1]);
		double max = 0;
		for (int i = 0; i + 2 < n; i++)
		{
			for (int j = i + 1; j + 1 < n; j++)
			{
	for (int k = j + 1; k < n; k++)
	{
	 double l1 = sqrt((a[i][0] - a[j][0])*(a[i][0] - a[j][0]) + (a[i][1] - a[j][1])*(a[i][1] - a[j][1]));
	 double l2 = sqrt((a[i][0] - a[k][0])*(a[i][0] - a[k][0]) + (a[i][1] - a[k][1])*(a[i][1] - a[k][1]));
	 double l3 = sqrt((a[j][0] - a[k][0])*(a[j][0] - a[k][0]) + (a[j][1] - a[k][1])*(a[j][1] - a[k][1]));
	 double p = (l1 + l2 + l3) / 2;
	 double s = sqrt (p*(p - l1)*(p - l2)*(p - l3));
	 if (s > max)
	  max = s;
	}
			}
		}
		printf("%.1lf\n", max);
	}
}