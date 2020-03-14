#include<stdio.h>
#include <math.h>
int main()
	{
	int m,h;
	float a,a1,a2;
	scanf("%d%d",&h,&m);
	a1=h%12*30+0.5*m;	//时针每走1小时是30度，1分钟走0.5度
	a2=6*m;	//分针每走1分钟是6度
	a=fabs(a1-a2);	//夹角为二者之差的绝对值 
		if(a>180)
		{
		a=360-a;
		}
		else
		{
		a=a;
		}
			if(m>9)
			{
			printf("At %d:%d the angle is %.1f degrees.\n",h,m,a);
 			} 
			else
			{
			printf("At %d:0%d the angle is %.1f degrees.\n",h,m,a);
			}	
return 0;
}
