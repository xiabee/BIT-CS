#include <stdio.h>

int tianshu(int y, int m, int d)
{ 
	int i, j, r = d;
	int day[2][13] = {
		{0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
		{0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}};
	if (y % 400 == 0 || y % 4 == 0 && y % 100 != 0)
	{j = 1;}
	else j = 0;

	for (i = 0; i < m; i++)
	{
		r = r + day[j][i];
	}

	return r;
}

void main()
{
	int y, m, d, i, x;
	int dd = 0;

	scanf ("%d %d %d", &y, &m, &d);

	for (i = 1900; i < y; i++)
	{
		if (i % 400 == 0 || i % 4 == 0 && i % 100 != 0)  dd = dd + 366;
		else											 dd = dd + 365;
	}

	dd = dd + tianshu(y, m, d);
	x = dd % 7 ;   

	printf ("%d\n", x);


}