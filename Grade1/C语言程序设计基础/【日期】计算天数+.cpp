#include <stdio.h>
int main()
{
	int y1, m1, d1, y2, d2, m2;
	scanf("%d %d %d", &y1, &m1, &d1);
	scanf("%d %d %d", &y2, &m2, &d2);
	int a[2][13] = { {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
	   {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31} };
	int alld = 0;
	for (int i = y1; i <= y2; i++)
	{
		if (i % 400 == 0 || i % 4 == 0 && i % 100 != 0)
			alld += 366;
		else alld += 365;
	}

	int j1 = y1 % 400 == 0 || y1 % 4 == 0 && y1 % 100 != 0, dd1 =  d1;
	for (int i = 1; i < m1; i++)
		dd1 += a[j1][i];

	int j2 = y2 % 400 == 0 || y2 % 4 == 0 && y2 % 100 != 0,dd2 = 0;
	for (int i = 1; i < m2; i++)
		d2 += a[j2][i];
	if (j2 == 0) dd2 = 365 - d2;
	else if (j2 == 1) dd2 = 366 - d2;

	int r = alld - dd1 - dd2;
	if (r == 1) printf("1 day\n");
	else printf("%d days\n", r);
}