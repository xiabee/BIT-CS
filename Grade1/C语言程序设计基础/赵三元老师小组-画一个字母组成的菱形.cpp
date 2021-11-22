#include <stdio.h>
int main()
{
	int n, i, j;
	char c;
	scanf ("%c,%d", &c, &n);
	int s = c - 'A';
	for (i = 1; i <= n; i++)
	{
		int space1 = n - i;
		int space2 = 2*i - 3;
		for (j = 1; j <= space1; j++)
			printf (" ");
		if (i == 1)
			printf ("%c\n", s + 'A');
		else
		{ 
			printf ("%c", s%26 + 'A');
			for (j = 1; j <= space2; j++)
	printf (" ");
			printf ("%c\n", s%26 + 'A');
		}
		s++;
	}
	i = i - 2;
	s = s - 2;
	for (; i >= 1; i--)
	{
		int space1 = n - i;
		int space2 = 2*i - 3;
		for (j = 1; j <= space1; j++)
			printf (" ");
		if (i == 1)
			printf ("%c\n", s + 'A');
		else
		{ 
			printf ("%c", s%26 + 'A');
			for (j = 1; j <= space2; j++)
	printf (" ");
			printf ("%c\n", s%26 + 'A');
		}
		s--;
	}
}