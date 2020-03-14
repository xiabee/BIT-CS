#include <stdio.h>
#include <stdlib.h>
int main(int argc, char *argv[]) 
{
	int n;
	double s;
	double sum(int n);
	scanf("%d",&n);
	s=sum(n); 
	if(n==1)
	    printf("sum=1.000000\n");
	else
	    printf("sum=%.6f\n",s);
	return 0;
}
double sum(int n)
{
	double s;
	if(n==1) 
		s=1;
	else 
		s=sum(n-1)+1/(float)n;
    return s;
}
