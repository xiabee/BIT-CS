#include <stdio.h>
int main()
{
	int a[2][13] = {{0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
	 {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}};
	int forbid0[7][3] = {{3, 8}, {4, 9}, {5, 0}, {1, 6}, {2, 7}};
	int y, m, d;
	scanf ("%d %d %d", &y, &m, &d);
	int d0 = 31 + 29 + 31 +9; //2012 4 9第几天 
	for (int i = 2012; i < y; i++)
	{
		if (i % 400 == 0 || i % 4 == 0 && i % 100 != 0) d = d + 366;
		else d = d + 365;
	}
	int j = y % 400 == 0 || y % 4 == 0 && y % 100 != 0;
	for (int i = 1; i < m; i++)
		d = d + a[j][i];
	int dd = d - d0 + 1; //相隔天数
	int week13 = dd / (7*13) % 5; 
	int xq = dd % 7;
	int f = xq - 1 - week13;
	if (f < 0) f = 5 + f;
// printf ("%d %d %d\n", dd, xq, week13);
	if (xq != 0 && xq != 6) printf ("%d and %d.\n",forbid0[f][0], forbid0[f][1]);
	else printf ("Free.\n");
}