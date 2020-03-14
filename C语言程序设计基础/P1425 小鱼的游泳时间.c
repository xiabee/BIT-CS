#include<stdio.h>
int main()
{
	int a1,a2,b1,b2;
	scanf("%d %d %d %d",&a1,&a2,&b1,&b2);
	int c1,c2;
	c1=b1-a1;
	c2=b2-a2;
	if(c2<0)
	{
		c1--;
		c2+=60;
	}
	printf("%d %d\n",c1,c2);
	return 0;
}
