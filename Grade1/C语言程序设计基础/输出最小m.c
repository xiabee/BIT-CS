#include<stdio.h>
int main()
{
	int m=0,n,x=0;
	scanf("%d",&n);
	while(x<n)
	{
	m++;
	x=m*(m+1)/2;
	}
	printf("%d\n",m);
return 0;
 } 
