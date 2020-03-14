#include <stdio.h>  // 1 0 X 9 8 7 6 5 4 3 2
#include <string.h>
int main()
{
	char c[] = {'1', '0', 'X', '9', '8', '7', '6', '5', '4', '3', '2'};
	int b[] = {7, 9, 10, 5, 8, 4, 2, 1, 6, 3, 7, 9, 10, 5, 8, 4, 2}, N, lj;
	scanf ("%d%c", &N, &lj);
	while (N--)
	{
		char a[25];
		gets(a);
		int len = strlen(a), sum = 0;
		if (len == 18)
		{
			for (int i = 0; i < 17; i++)
	sum = sum + b[i] * (a[i] - '0'); 
			char y = c[sum % 11];
			if (y == a[17])
	printf ("Valid\n");
			else printf ("Invalid\n");
		}
		else if (len == 15)
		{
			int bs = (a[12] - '0') * 100 + (a[13] - '0') * 10 + (a[14] - '0');
			for (int i = 14; i >= 6; i--)
			a[i + 2] = a[i];
			if (bs >= 996 && bs <= 999)
			{
	a[6] = '1';
	a[7] = '8';	
			}
			else
			{
	a[6] = '1';
	a[7] = '9';	
			}
			for (int i = 0; i < 17; i++)
	sum = sum + b[i] * (a[i] - '0'); 
			char y = c[sum % 11];	
			a[17] = y;
			a[18] = '\0';
			printf ("%s\n", a);
		}
		else
			printf ("Invalid\n"); 
	}
}