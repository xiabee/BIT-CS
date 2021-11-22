#include<stdio.h>
#include<string.h>
char a[1010][21];
int main()
{
	memset(a, '\0', sizeof(a));
	int n, total = 0, i, j;
	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		scanf("%s", &a[i]);
		if (strlen(a[i]) > 10)
			total++;
		//printf("%d\n",strlen(a[i])); 
		if (strlen(a[i]) > 10)
			for (j = 0; j < i; j++)
				if (strcmp(a[i], a[j]) == 0)
				{
					total--;
					break;
				}
	}
	printf("%d\n", total);
	return 0;
}