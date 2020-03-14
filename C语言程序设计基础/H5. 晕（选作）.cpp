#include <stdio.h>
int main()
{
	int n, a[100][100] = {0}, tot = 1;
	scanf ("%d", &n);
	a[0][0] = 1;
	int x = 0, y = 0;
	while (tot < n*n)
	{
		while(y + 1 < n && a[x][y+1] == 0) a[x][++y] = ++tot;
		while(x + 1 < n && a[x+1][y] == 0) a[++x][y] = ++tot;
		while(y - 1 >= 0 && a[x][y-1] == 0) a[x][--y] = ++tot;
		while(x - 1 >= 0 && a[x-1][y] == 0) a[--x][y] = ++tot;
	}
	for (int j = 0; j < n; j++)
	{
		for (int i = 0; i < n; i++)
			printf ("%3d", a[j][i]);
		printf ("\n");
	}
	
}