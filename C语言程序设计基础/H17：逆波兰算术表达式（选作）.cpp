#include <stdio.h>
int main()
{
	int a[1000] = {0}, p = 0, r = 0;
	char b[1000];
	gets(b);
	for (int i = 0; b[i] != '\0'; i++)
	{ 
		if (b[i] >= '1' && b[i] <= '9')
		{ 
			int temp = 0;
			while (b[i] >= '0' && b[i] <= '9')
			{
	temp = temp * 10 + b[i] - '0';
	i++;
			}
			a[p++] = temp;
		}
		if (b[i] == '*' || b[i] == '+' || b[i] == '-' || b[i] == '/')
		{
			switch (b[i])
			{
	case '*': r = a[p-2] * a[p-1];
		a[p-1] = r;
		break;
	case '-': r = a[p-2] - a[p-1];
		a[p-1] = r;
		break;
	case '+': r = a[p-2] + a[p-1];
		a[p-1] = r;
		break;
	case '/': r = a[p-2] / a[p-1];
		a[p-1] = r;
		break;
			}
			for (int j = p - 2; j - 1 >= 0; j--)
			{
	a[j] = a[j-1];
			}
		}
	}
	printf ("%d\n", r);
}