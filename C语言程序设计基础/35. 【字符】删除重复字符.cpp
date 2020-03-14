#include <stdio.h>
int main()
{
	char a[150];
	gets(a);
	for (int i = 0; a[i] != '\0'; i++)
	{ 
		int ok = 1;
		for (int j = 0; j < i; j++)
		{
			if (a[i] == a[j])
			{
	ok = 0;
	break;
			}
		}
		if (ok)
			printf ("%c", a[i]);
	}
	printf ("\n"); 
}