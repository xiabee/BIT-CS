#include<stdio.h>
//#include<stdlib.h>
int main(int argc, char *argv[])
{
	int n,m,sum;
	int addsum(int n,int m);
	scanf("%d %d",&n,&m);
	sum=addsum(n,m);
	printf("The sum from %d to %d is %d.\n",n,m,sum);
	return 0;
}
addsum(int n,int m)
{
	int sum=0;
	if(n<=m) 
		sum=addsum(n+1,m)+n;
	else 
		sum=0;
	return sum;
}
