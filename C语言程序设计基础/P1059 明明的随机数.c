#include<stdio.h>
int main()
{
	int n1,i,j,a[100],b[100],temp;
	scanf("%d",&n1);
	for(i=0;i<n1;i++)
		scanf("%d",&a[i]);
	for(i=0;i<n1;i++)
		for(j=0;j<i;j++)
			if(a[i]<a[j])
			{
				temp=a[i];
				a[i]=a[j];
				a[j]=temp;			
			}
	for(i=0,j=0;i<n1;i++)
	{
		if(a[i]!=a[i+1])
		{
			b[j]=a[i];
			j++;
		}
	}
	printf("%d\n",j);
	for(i=0;i<j;i++)
		printf("%d ",b[i]);
	printf("\n");
	return 0;
 } 
