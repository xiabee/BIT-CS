#include <stdio.h>
int a[2][13] = {{0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
			 {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}};

				 
int findday(int y, int m, int d)		//这一年的第几天 
{ 
	int j, i, r = 0;
	if (y % 400 == 0 || y % 4 == 0 && y % 100 != 0)
	  j = 1;
	else j = 0;
	
	for (i = 0; i < m; i++)
	{
		r = r + a[j][i] ;
	}  
	r = r + d;
	
	return r;			
}

int main()
{   
	int y, m, d, i, dd = 0, j;
	scanf ("%d %d %d", &y, &m, &d);
	
	if (y % 400 == 0 || y % 4 == 0 && y % 100 != 0)
	  j = 1;
	else j = 0; 
	
	if (m > 12 || m <= 0)
	{
		printf ("month is error.\n");
		return 0;
	}
	else if (d > a[j][m] || d <= 0)
	{
		printf ("day is error.\n");
		return 0;
	}
	
	for (i = 1900; i < y; i++)
	{
		if (i%400 == 0 || i%4 == 0 && i%100 != 0) dd = dd + 366;
		else									  dd = dd + 365;
	}
	
	dd = dd + findday(y, m, d);
	printf ("%d\n", dd%7);
	
	return 0;
}