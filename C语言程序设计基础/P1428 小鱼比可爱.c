#include<stdio.h>
#include<string.h>
int main()
{
	int n,a[100]={0},b[100]={0},i,j;
	scanf("%d",&n);
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	for(i=0;i<n;i++)
	{
		for(j=0;j<i;j++)
		{
			if(a[j]<a[i])
				b[i]++;
		}
	}
	for(i=0;i<n;i++)
		printf("%d ",b[i]);
	printf("\n");
	return 0;
}
