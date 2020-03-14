#include <stdio.h>
int main()
{
	int n, x, y;
	char a[100][100] = {' '}, c;
	scanf("%d %c", &n, &c);
	int ori = c - 'A';
	int ori2 = ori;

	for (x = n, y = 1; x >= 1; x--, y++)
	{
		a[x][y] = ori%26 + 'A';
		ori++;
	}
		x++;

	for (y; y <= 2 * n - 1; y++)
	{
		a[1][y] = ori % 26 + 'A';
		ori++;
	}
	

	for (x = x + 1; x <= n; x++, y++)
	{
		a[x][y] = ori % 26 + 'A';
		ori++;
	}
	x--, y--;

	for (int y = 2, i = 1; y <= 3 * n - 3; y++, i++)
	{
		a[n][y] = (ori2 + i) % 26 + 'A';
	}

	for (int j = 1; j <= n; j++)
	{
		for (int i = 1; i <= 2 * n + j - 2; i++)
		{
			if (a[j][i] >= 'A' && a[j][i] <= 'Z') printf("%c", a[j][i]);
			else printf(" ");
		}
		printf ("\n");
	}




}