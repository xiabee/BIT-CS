#include <stdio.h>
int main()
{
	char c[1000];
	gets(c);
	int a[1000] = {0}, w = 0, r = 0;
	for (int i = 0; c[i] != '\0'; i++)
	{ 
		int temp = 0;
		if (c[i] >= '0' && c[i] <= '9')
		{
			while (c[i] >= '0' && c[i] <= '9')
			{
	temp = temp * 10 +( c[i] - '0');
	i++;
			}
		// i--;
			a[w++] = temp;
		}
		else
		{
			if (c[i] == '+' || c[i] == '-' || c[i] == '*' || c[i] == '/')
			{
	switch (c[i])
	{
	 case '+': r = a[w-1] + a[w-2];
		 a[w-1] = r;
		 break;
	 case '-': r = a[w-2] - a[w-1];
		 a[w-1] = r;
		 break;
	 case '*': r = a[w-1] * a[w-2];
		 a[w-1] = r;
		 break;
	 case '/': r = a[w-2] / a[w-1];
		 a[w-1] = r;
		 break;				   
	}
	for (int i = w-2; i - 1 >= 0; i--)
	 a[i] = a[i-1];
			}
		}
	}
	printf ("%d\n", r);
	
}