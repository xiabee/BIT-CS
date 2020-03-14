#include<stdio.h>
#include<math.h>
int main()
{
	int divisor(int a,int b);
	int a,b,c,d;
	scanf("%d,%d",&a,&b);
	c=divisor(a,b);
	d=a*b/c;
	printf("最大公约数：%d\n最小公倍数：%d\n",c,d);
 } 
int divisor(int a,int b)//更相减损术； 
{
	while(a!=b)
	{
		if(a>b)
			a=a-b;
		else
			b=b-a;
	}
	return(a);
 } 
