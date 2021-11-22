#include <stdio.h>
int dy = 0;
int is_black(int y, int m)
{ 
	int dm = 13;
	int tab[2][13] = {{0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
	   {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31} };
	int j = y % 400 == 0 || y % 4 == 0 && y % 100 != 0;
	
	for (int i = 0; i < m; i++)
		dm = dm + tab[j][i];
		
	dm = dy + dm;
	if (dm % 7 == 5) return 1;
	else return 0;
	  
}
int main()
{
	int y, m, tot = 0, a[12], i = 0;
	scanf ("%d", &y);
	
	for (i = 1900; i < y; i++)
	{
		if (i % 400 == 0 || i % 4 == 0 && i % 100 != 0)  dy = dy + 366;
		else dy = dy + 365;
	}
	i = 0;
	for (m = 1; m <= 12; m++)
	{
		if(is_black(y, m))
		{
			tot++;
			a[i++] = m;
		}
	}
	if (tot != 1)
	{
		printf ("There are %d Black Fridays in year %d.\n", tot, y);
		printf ("They are:\n");
		for (i = 0; i < tot; i++)
			printf ("%d/%d/13\n", y, a[i]);  
	}
	else if (tot == 1)
	{
		printf ("There is %d Black Friday in year %d.\n", tot, y);
		printf ("It is:\n");
		for (i = 0; i < tot; i++)
			printf ("%d/%d/13\n", y, a[i]);   
	}

	
}