#include<stdio.h>
int main()
{
	int a,i=1;
	scanf("%d",&a);
	for(i=1;i<=a*a;i++)
	{
	if(i%a!=0)
	{	
		printf(" %2d",i);
	}
	else
	{
		printf(" %2d\n",i);
	}
	}
return 0; 
 } 
