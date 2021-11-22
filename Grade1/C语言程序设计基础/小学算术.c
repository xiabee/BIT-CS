#include<stdio.h>
int main()
{
	int a,b,x,y,z,t,p; 
	scanf("%d%d",&a,&b);
	x=a+b;
	y=a-b;
	z=a*b;
	t=a/b;
	p=a%b;
	printf("%d+%d=%d\n",a,b,x);
	printf("%d-%d=%d\n",a,b,y);
	printf("%d*%d=%d\n",a,b,z);
	printf("%d/%d=%d\n",a,b,t);
	printf("%d%%%d=%d\n",a,b,p);
	return 0;
 }
