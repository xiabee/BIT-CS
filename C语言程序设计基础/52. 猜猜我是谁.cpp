#include <stdio.h>
#include <stdlib.h>
int main()
{
	FILE * p1;
	char name[20], a[100];
	int n, m = 1, flag = 0;
	gets(name);
	scanf ("%d", &n);
	if ((p1 = fopen(name, "r")) == NULL)
	{
		printf ("File Name Error.\n");
		exit(0);
	}
	while(!feof(p1))
	{
		fgets(a, 20, p1);
		if(m == n)
		{
			printf ("%s", a);
			flag = 1;
			break;
		}
		m++;
	}
	if (!flag)
		printf ("Line No Error.\n");
		
	fclose(p1);
	}