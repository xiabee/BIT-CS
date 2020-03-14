#include<stdio.h>
#include<string.h>
int main()
{
	long  int a[100]={1};
	int i;
	for(i=0;;i++)
	{
		scanf("%ld",&a[i]);
		if(a[i]==0)
			break;
	}
	int j;
	for(j=i-1;j>=0;j--)
		printf("%d ",a[j]);
	printf("\n");
	return 0;
}
