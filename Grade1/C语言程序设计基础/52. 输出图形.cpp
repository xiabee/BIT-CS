#include <stdio.h>
int main()
{
	int h;
	char a;
	scanf ("%d %c", &h, &a);
	int ori = a - 'A'; 
	if (h != 1)
	{
		printf ("%c ", ori + 'A');
		for (int i = 1; i <= 2*h - 3; i++)
			printf ("  ");
		printf ("%c\n", ori + 'A');
	}
	else if (h == 1)
		printf ("%c\n", ori + 'A');

	for (int i = 2; i < h; i++)
	{
		for (int j = 1; j <= 2*h - 1; j++)
		{
			if (j == 1)
	printf ("%c ", (ori + 2*(h-1) + (h-i))%26+ 'A');
			else if (j == i)
	printf ("%c ", (ori + i - 1)%26+ 'A');
			else if (j + i == 2*h)
	printf ("%c ", (ori + i - 1)%26+ 'A');
			else if (j == 2*h - 1)
	printf ("%c\n", (ori + 2*(h-1) + (h-i))%26+ 'A');
			else printf ("  ");
		}
	}
	if (h != 1)
	{
		for (int i = 1; i <= h; i++)
		{
			printf ("%c ", (ori + 2*(h - 1) - (i - 1))%26 + 'A');
		}
		for (int i = h + 1; i <= 2*h - 1; i++)
		{
			if (i != 2*h - 1) printf ("%c ", (ori + (h-1) + (i-h)) % 26 + 'A');
			else printf ("%c\n", (ori + (h-1) + (i-h)) % 26 + 'A');
		}
	}
}