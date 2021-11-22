#include<stdio.h>
int duck(int n)
{
	int sum;
	if(n==7)
	sum=2;
	else
	sum=(duck(n+1)+1)*2;
	return(sum);
}
int main()
{ 
	int i;
	printf("sum=%d\n",duck(0));
	for(i=1;i<7;i++)
		printf("sell=%d,",2*(duck(i+1)+2));
	printf("sell=4,\n");
	return 0;
}
