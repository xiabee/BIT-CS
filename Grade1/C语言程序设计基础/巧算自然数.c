#include<stdio.h>
int fun(int n,int i);
int main()
{
	int n,t;
	scanf("%d",&n);
	printf("%d,",n);
	fun(n,1);	
}
int fun(int n,int i)
{
	int a=n;
	if(a%2==0)
		a/=2;
	else
		a=3*a+1;
	i++;
	if(a!=1)
	{
		printf("%d,",a);
		return(fun(a,i));
	}
	else
	{
		printf("1\n");
		printf("step=%d\n",i);
		return 0;
	}
			
}
