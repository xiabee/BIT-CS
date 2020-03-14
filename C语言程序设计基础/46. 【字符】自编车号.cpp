#include <stdio.h>
#include <string.h>
int main()
{
	char a[100];
	int tot = 0;
	scanf ("%s", a);
	if (a[4] < '0' || a[4] > '9')
		printf ("no.\n");
	else
	{
		for (int i = 0; i < 4; i++)
		{
			if (a[i] >= 'A' && a[i] <= 'Z')
	tot++;
			if (a[i] == 'O' || a[i] == 'I')
			{
	printf ("no.\n");
	return 0;
			}
		}
		if (tot >= 2)
			printf ("ok.\n");
		else printf ("no.\n");
	}
}