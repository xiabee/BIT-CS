#include <stdio.h>
int main()
{
	char a[60], b[60];
	gets(a);
	char first = a[0];
	int tot = 0, m = 0; // tot 个数 
	for (int i = 1; a[i] != '\0'; i++)
	{
		if (a[i] >= '0' && a[i] <= '9')
		{
			b[tot++] = a[i];
		}
		else if (a[i] == 'e' || a[i] == 'E')
		{ i++;
			while (a[i] == ' ')
			{
	i++;
			}
			int sign = 1;
			if (a[i] == '-')
			{
	sign = -1;
	i++; 
			}
			while (a[i] >= '0' && a[i] <= '9')
			{
	m = m * 10 + a[i] - '0';
	i++;
			}
			m = m * sign;
			i--;
		}
	}
	
	if (m >= 0)
	{
		printf ("%c", first);
		for (int i = 0; i < m && i < tot; i++) // 整数部分 
			printf ("%c", b[i]);
		if (m > tot)
		{
			int dlt = m - tot;
			for(int i = 1; i <= dlt; i++)
	printf ("0");
			printf (".00000000");
			printf ("\n");
			
		}
		else if (m <= tot)
		{
			printf (".");
			for (int i = m; i < tot && i < m + 8; i++)
			{
	printf ("%c", b[i]);
			} 
			if (tot < m + 8)
			{
	int dlt = 8 - (tot - m);
	for (int i = 1; i <= dlt; i++)
	 printf ("0");
	printf ("\n");
			}
			else 
	printf ("\n");
		} 
	}
	else if (m < 0 && -m < 9)
	{
		printf ("0.");
		for (int i = 1; i <= -m - 1; i++)
			printf ("0");
		printf ("%c", first);
		int dlt = 8 - (-m - 1) - 1;
		for (int i = 0; i < tot && i < dlt; i++)
			printf ("%c", b[i]);
		for (int i = 1; i <= 7 - (-m - 1) - tot; i++)
			printf ("0");
		printf ("\n");
	}
	else if (-m >= 9)
		printf ("0.00000000\n");
}