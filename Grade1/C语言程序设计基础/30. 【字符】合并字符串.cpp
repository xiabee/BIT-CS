#include <stdio.h>
#include <string.h>
int main()
{
	char a[50], b[50];
	gets(a);
	gets(b);
	
	int l1 = strlen(a);
	int l2 = strlen(b);
	int i=0, j=0;
	strcat(a, b);
	a[l1 + l2] = '\0';
	for (i = 1; i <= l1 + l2; i++)
	{
		for (j = 0; j + 1< l1 + l2; j++)
		{
			if (a[j+1] <= a[j])
			{
	int temp;
	temp = a[j+1];
	a[j+1] = a[j];
	a[j] = temp;
			}
		}
	}
	printf ("%s\n", a);
	
}