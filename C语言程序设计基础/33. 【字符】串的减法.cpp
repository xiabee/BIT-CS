#include <stdio.h>
int main()
{
	char s[100], t[100];
	gets(s);
	gets(t);
	int i, j;
	for (i = 0; s[i] != '\0'; i++)
	{
		int ok = 1;
		for (j = 0; t[j] != '\0'; j++)
		{
			if (s[i] == t[j])
			{
	ok = 0;
	break;
			}
		}
		if (ok) printf ("%c", s[i]);
	}
	printf ("\n");
}