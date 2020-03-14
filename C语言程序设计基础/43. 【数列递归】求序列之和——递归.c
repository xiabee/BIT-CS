#include<stdio.h>
#include<stdlib.h>
int main(int argc, char *argv[])
{
	int n;
	float sum(int n);
	scanf("%d",&n);
	if(n==1)
	    printf("1\n");
	else
	    printf("%f\n",sum(n));
	return 0;
}
float sum(int n)
{
	float s;
	if(n==1) 
		s=1;
	else if(n%2==0) 
		s=sum(n-1)+1/(float)n;
	else 
		s=sum(n-1)-1/(float)n;
    return s;
}
