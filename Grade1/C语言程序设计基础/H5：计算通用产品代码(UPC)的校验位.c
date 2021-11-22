#include<stdio.h> 
int main() 
{
int a,b,c; 
	int b1,b2,b3,b4,b5; 
	int c1,c2,c3,c4,c5; 
	int d1,d2,d3,d4; 
	scanf("%d\n%d\n%d",&a,&b,&c); 
		b1=b/10000;
		b2=(b/1000)%10;
		b3=(b/100)%10;
		b4=(b/10)%10;
		b5=b%10; 
		c1=c/10000;
		c2=(c/1000)%10;
		c3=(c/100)%10;
		c4=(c/10)%10;
		c5=c%10; 
		d1=a+b2+b4+c1+c3+c5;
		d2=b1+b3+b5+c2+c4;
		d3=(3*d1+d2-1)%10;
		d4=9-d3; 
	printf("%d\n",d4); 
return 0;
} 

