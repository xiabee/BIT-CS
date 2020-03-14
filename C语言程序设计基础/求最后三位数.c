#include<stdio.h>
#include<math.h>
int main()
	{
	int a,b,n,i;
	scanf("%d %d",&a,&n);
	a%1000;
	if(n==0)
	printf("The last 3 numbers is 1.\n");
	else if(n==1)
	printf("The last 3 numbers is %d.\n",a);
	else
	{
	b=a;
	for(i=1;i<n;i++)
	{
		b=b*a;
		b=b%1000;
	}
	
		printf("The last 3 numbers is %.3d.\n",b);
	
	}
	return 0; 
	}
