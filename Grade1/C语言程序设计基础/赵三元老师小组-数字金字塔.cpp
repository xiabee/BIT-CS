#include <stdio.h>
int main()
{
	int n, i, j;
	scanf ("%d", &n);
	for (i = 1; i <= n; i++)
	{
		int space1 = (n - i) * 2, tot = 1, chu = 1;
		int gs = 2 * i - 1;
		for (j = 1; j <= space1; j++)
			printf (" ");
		for (j = 1; j <= gs; j++)
		{ 
			if (j <= gs / 2 + 1)
	printf ("%2d",tot++);
			else if (j > gs / 2 + 1)
			{
	if (chu) 
	{
	 tot = tot - 2;
	 printf ("%2d", tot--);
	 chu = 0;
	}
	else
	 printf ("%2d", tot--);
			}
		}
		printf ("\n");
	}
}