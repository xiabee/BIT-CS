#include <stdio.h>
#include <string.h>
int main()
{
	char a[5][20];
	int i;
	for (i = 0; i < 5; i++)
	{
		scanf ("%s", a[i]);
	}
	for (i = 1; i <= 4; i++)
	{
		for (int j = 0; j + 1 < 5; j++)
		{
			if (strcmp(a[j], a[j+1]) < 0)
			{
	char temp[20];
	strcpy(temp, a[j]);
	strcpy(a[j], a[j+1]);
	strcpy(a[j+1], temp);
			}
		}
	}
	for (i = 0; i < 5; i++)
		printf ("%s\n", a[i]);
}