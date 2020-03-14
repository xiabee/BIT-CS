#include<stdio.h> 
#include<math.h>
double a,b,c,d;
double f(double x)
{
	return a*sin(x)*sin(x) + b*cos(x)*cos(x) + 
		    	c*sin(x) + d*cos(x);
}
int main()
{
	double L,R,i;
	scanf("%d%d%d%d%lf%lf",&a,&b,&c,&d,&L,&R);
	double ans=f(1);
	for(i=L; i<=R; i+=0.1)
		ans= f(i)>ans ? f(i) : ans;
	printf("%.1lf\n",ans);
	return 0;
}


