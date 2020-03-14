#include<stdio.h>
int main()
{
	int a[10],max,i,count=0;
	for(i=0;i<10;i++)
		scanf("%d",&a[i]);
	scanf("%d",&max);
	for(i=0;i<10;i++)
	{
		if(a[i]<=max+30)
			count++;
	}
	printf("%d\n",count);
	return 0; 
 } 
