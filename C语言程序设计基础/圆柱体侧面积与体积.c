#include<stdio.h>
#define PI  3.1415926
int main()
{
	double r,h,m,s,v;
	scanf("%lf%lf",&r,&h);
	s=2*PI*r*h;
	v=PI*r*r*h;
	printf("s=%.2lf,v=%.2lf\n",s,v);
	return 0;
 } 
