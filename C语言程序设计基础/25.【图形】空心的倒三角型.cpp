#include <stdio.h>
int main()
{
	int h, space1, space2, j, i;
	scanf ("%d", &h);
	for (j = 1; j <= h; j++)
	{   
		space1 = j - 1;
		space2 = 2*h-1-2-2*space1;
		if (j == 1)
		{
			for (i = 1; i <= 2*h-1; i++) printf ("*");
			printf ("\n");
		}
		else if (j > 1 && j < h)
		{
			for (i = 1; i <= space1; i++) printf (" ");
			printf ("*");
			for (i = 1; i <= space2; i++) printf (" ");
			printf ("*\n");
		}
		else if (j == h)
		{
			for (i = 1; i <= space1; i++) printf (" ");
			printf ("*\n");
		}
		
	}
}