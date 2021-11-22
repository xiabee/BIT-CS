#include <stdio.h>
#include <stdlib.h>
static int x[100];
int i=0;
int main() 
{
	int f(int m,int n,int sum);
	int m0,n0,sum=0;
	scanf("%d %d",&m0,&n0);
	f(m0,n0,sum);
	printf("%d\n",i);
	return 0;
}

int f(int m,int n,int sum)
{
	int a;
	if(n==0)
	{
		if(m==sum) i++;
	}
	else for(x[n]=0;x[n]<=(m-sum)/n;x[n]++)
	{
		     a=sum+n*x[n];
		     f(m,n-1,a);
	}
}
