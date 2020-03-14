#include<stdio.h>
int main()
{
	char a[256];
	int i,n;
	gets(a);
	n=strlen(a);
	for(i=n-1;i>=0;i--)
		printf("%c",a[i]);
	printf("\n");
	return 0;
}
