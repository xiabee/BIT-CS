#include <stdio.h>
#include <string.h>
int main()
{
	int i,n,k=1;
	char str[1000];
	gets(str);
	n=strlen(str);
	for(i=0;i<=n/2;i++)
	if(str[i]!=str[n-i-1]) 
	{
		k=0;
		break;
	}
	k?printf("Yes\n"):printf("No\n");
	return 0;
}
