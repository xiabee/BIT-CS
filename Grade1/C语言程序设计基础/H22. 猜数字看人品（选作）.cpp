#include <stdio.h>
#include <string.h>
int main()
{ 
	int x = 1, y = 10, n, dh = 0;
	char temp[20], low[] = "too low", high[] = "too high", right[] = "right on";
	char gar;
	while (scanf("%d%c", &n,  &gar))
	{
		gets(temp);
		if (n == 0)
			return 0;
		else if (strcmp(temp, right) == 0)
		{
			if ( n > y || n < x || x > y)
			{
	printf ("Tom is dishonest\n");
	x = 1, y = 10;
	dh = 0;
			}
			else if (n >= x && n <= y)
			{
	printf ("Tom may be honest\n");
	x = 1, y = 10;	 
			}
		}
		else if(!dh)
		{ 
			
			if (strcmp(temp, low) == 0 && n >= x)
	x = n + 1;
			else if (strcmp(temp, high) == 0 && n <= y)
	y = n - 1;
			
			if (x > y)
	dh = 1;
		}
	}
}