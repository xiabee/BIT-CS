#include <stdio.h>
int main()
{
	int tab[2][13] = {{0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
					  {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}};
	int n;
	scanf("%d", &n);
	while (n--)
	{
		int y, m, d;
		scanf("%d %d %d", &y, &m, &d);
		int d0 = d;
		int j = y % 400 == 0 || y % 4 == 0 && y % 100 != 0;
		for (int i = 1990; i < y; i++)
		{
			if (i % 400 == 0 || i % 4 == 0 && i % 100 != 0)
				d = d + 366;
			else
				d = d + 365;
		}
		for (int i = 1; i < m; i++)
			d = d + tab[j][i];
		//printf ("%d\n", d);
		if (d % 5 >= 1 && d % 5 <= 3)
			printf("He was fishing on %d.%d.%d\n", y, m, d0);
		else
			printf("He was basking on %d.%d.%d\n", y, m, d0);
	}
}