#include <stdio.h>

int findday (int y)
{ 
	int d = 0;
	int a[2][13] = {{0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
				 {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}};
	int j = (y % 400 == 0 || y % 4 == 0 && y % 100 != 0) ;
	for (int i = 0; i < 5; i++)
	{
		d = d + a[j][i];
	}
	return d + 1;					 
}

int main()
{
	int y, dd = 0, t;
	scanf ("%d", &y);
	
	for (int i = 1900; i < y; i++)
	{
		if (i % 400 == 0 || i % 4 == 0 && i % 100 != 0)  dd = dd + 366;
		else dd = dd + 365;
	}
	dd = dd + findday(y);
	
	int xq_may = dd % 7;
	if (xq_may == 0)  t  = 8;
	else t = 7 - xq_may + 8; 
	printf ("%d\n", t);  
}