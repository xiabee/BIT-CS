//求方程ax^2+bx+c=0的根
#include <stdio.h>
#include <math.h>
int main()
{	
	float a,b,c,dis,x1,x2;	
	printf("请输入a,b,c的值： ");	
	scanf("%f %f %f",&a,&b,&c);	
	dis=b*b-4*a*c;	
	if(dis<0)	
	{		
	printf("该函数无实根。\n");		
	return 0;
	}
	else if(dis==0)	
	{		
	x1=x2=(-b)/(2*a);		
	printf("该函数有两个相等的实根：\n");	
	}	
	else 	
	{		
	x1=(-b+sqrt(dis))/(2*a);	
	x2=(-b-sqrt(dis))/(2*a);	
	printf("该函数有两个不等的实根：");	
	}
		
	printf("x1=%f x2=%f\n",x1,x2);	
return 0;
 }

