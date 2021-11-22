#include<stdio.h>
#include<string.h>
int main()
{
	char a[200];
	int i,n;
	gets(a);
	n=strlen(a);
	for(i=0;i<n;i++)
	{
		if(a[i]=='n')
		{
			if(a[i-1]!='n')
				printf("\n");
		}
		else
			printf("%c",a[i]);
			
	}
	if(a[n-1]!='n')
		printf("\n");		
	return 0;
 } 
