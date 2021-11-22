#include <stdio.h>
int main()
{
	char a;
	int h;
	scanf ("%c %d", &a, &h);
	int temp = a - 'A';
	int i, j;
	
	for (i = 1; i <= h; i++)
	{
		int space1 = h - i;
		int space2 = (i - 1)*2 - 1;
		int zm =  (temp++)%26 + 'A';
		for (j = 1; j <= space1; j++)
			printf (" ");
		printf ("%c", zm);
		if(i == 1)  printf ("\n");
		else 
		{
			for (j = 1; j <= space2; j++)
	printf (" ");
			printf ("%c\n", zm);
		}
	}
	temp = temp - 2;
	for (i = i - 2; i >= 1; i--)
	{
		int space1 = h - i;
		int space2 = (i - 1)*2 - 1;
		int zm =  (temp--)%26 + 'A';
		for (j = 1; j <= space1; j++)
			printf (" ");
		printf ("%c", zm);
		if(i == 1)  printf ("\n");
		else 
		{
			for (j = 1; j <= space2; j++)
	printf (" ");
			printf ("%c\n", zm);
		}
	} 
}