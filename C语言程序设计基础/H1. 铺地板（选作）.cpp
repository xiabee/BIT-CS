#include <stdio.h>
#include <string.h>

int a[100][100];
int main()
{ 
	memset(a, 0, sizeof (a));
	int n, i, j, tot = 2;
	scanf ("%d", &n);
	int x = 2, y = 1;
	a[1][1] = 1;a[2][1] = 2;
	while (tot < n*n)
	{ 
		if (y == 1)
		{ //printf ("¨L %d %d %d\n", tot, x, y);
			while ( x-1 >= 1 && a[x-1][y+1] == 0) //  ¨L + ¡ý 
			{
	a[--x][++y] = ++tot;
			}
			if (x == 1 && y + 1 <= n) 
			a[x][++y] = ++tot;
			else if (y == n) 
			a[++x][y] = ++tot; 
		}
		
		if (x == 1)
		{ //printf ("¨J %d %d %d\n", tot, x, y);
			while ( y-1 >= 1 && a[x+1][y-1] == 0) //¨J + ¡ú 
			{
	a[++x][--y] = ++tot;
			}
			if (y == 1 && x + 1 <= n)
			a[++x][y] = ++tot;
			else if (x == n)
			a[x][++y] = ++tot;   
		} 
		
		if (x == n)
		{ //printf ("¨L %d %d %d\n", tot, x, y);
			while (y + 1 <= n && a[x-1][y+1] == 0)
			{
	a[--x][++y] = ++tot;
			}
			if (y==n)
			a[++x][y] = ++tot;
		} 
		
		if (y == n)
		{ //printf ("¨J %d %d %d\n", tot, x, y);
			while (x+1 <= n && a[x+1][y-1] == 0)
			{
	a[++x][--y] = ++tot;
			}
			if (x == n)
			a[x][++y] = ++tot;
		}
	}
	for (j = 1; j <= n; j++)
	{
		for (i = 1; i <= n; i++)
		{ 
			if (i == n) printf ("%2d", a[i][j]);
			else printf ("%2d ", a[i][j]);
		}
		printf ("\n");
	}
}