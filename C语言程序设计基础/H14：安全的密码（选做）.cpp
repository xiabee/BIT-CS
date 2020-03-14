#include <stdio.h>
int main()
{
	int N, i, lj;
	scanf ("%d%c", &N, &lj);
	while (N--)
	{ 
		char a[30];
		gets (a);
		int tot = 0, n[5] = {0};
		for (i = 0; a[i] != '\0'; i++)
		{
			if (a[i] >= '0' && a[i] <= '9')
	n[1]++;
			else if (a[i] >= 'A' && a[i] <= 'Z')
	n[2]++;
			else if (a[i] >= 'a' && a[i] <= 'z')
	n[3]++;
			else
	 n[4]++; 
		}
		for (int j = 1; j <= 4; j++)
		{
			if (n[j] != 0)
	tot++;
		}
		if (i < 6 || tot == 1)
			printf ("Not Safe\n");
		else if (tot == 2)
			printf ("Medium Safe\n");
		else if (tot >= 3)
			printf ("Safe\n");
	}
}