#include <stdio.h>
#include <string.h>
#include <stdlib.h> 
int cmp(char *a, char *b)
{
	int len1 = strlen(a), len2 = strlen(b);
	if (len1 > len2) return 1;
	else if (len1 < len2) return -1;
	else if (len1 == len2)
	{
		return strcmp(a, b);
	}
}
int main()
{
	int N,i,j;
	char * num[10005];
	char a[10005][25]; 
	scanf ("%d", &N);
	for (i = 0; i < N; i++)
	{
		char tempnum[10005];
		scanf ("%s %s", a[i], tempnum);
		num[i] = (char*)malloc(strlen(tempnum) + 1);
		strcpy(num[i], tempnum);
	} 
	for (i = 0; i < N - 1; i++)
	{
		for (j = 0; j + 1 < N - i; j++)
		{
			if (cmp(num[j], num[j+1]) < 0)
			{
	char * temp;
	temp = num[j];
	num[j] = num[j+1];
	num[j+1] = temp;
	
	char temp2[25];
	strcpy(temp2, a[j]);
	strcpy(a[j], a[j+1]);
	strcpy(a[j+1], temp2);
			}
			else if (cmp(num[j], num[j+1]) == 0)
			{
	if (strcmp(a[j], a[j+1]) > 0)
	{
	 char temp2[25];
	 strcpy(temp2, a[j]);
	 strcpy(a[j], a[j+1]);
	 strcpy(a[j+1], temp2);	 
	}
			}
		}
	}
	for (i = 0; i < N; i++)
		printf ("%s\n", a[i]);

	
}
