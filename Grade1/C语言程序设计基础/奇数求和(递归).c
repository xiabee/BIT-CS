#include<stdio.h>
int sum(int n);
int main()
{	
	int n,c;
	scanf("%d",&n);
	c=sum(n);
	printf("%d\n",c);
	return 0;	
}
int sum(int n)
{ 
	int b; 
	if(n>1) 
		return(sum(n-1)+2*n-1);
	if(n==1)
		return 1;
}
