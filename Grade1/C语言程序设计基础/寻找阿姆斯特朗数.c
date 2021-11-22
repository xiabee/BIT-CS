/*Ñ°ÕÒ°¢Ä·Ë¹ÌØÀÊÊı*/
#include<stdio.h>
#include<math.h>
int main()
{
	int n,i,M,m,a,b,c,d,e,f;
	scanf("%d",&n);
	switch(n)
	{
	case 1:printf("1\n2\n3\n4\n5\n6\n7\n8\n9\n");break;
	case 2:printf("No output.\n");break;
	case 3:printf("153\n370\n371\n407\n");break;
	case 4:{m=1000;M=9999;
	        for(i=m;i<=M;i++)
			{
			a=i%10;
			b=(i%100-a)/10;
			c=(i%1000-i%100)/100;
			d=(i%10000-i%1000)/1000;
			if(a*a*a*a+b*b*b*b+c*c*c*c+d*d*d*d==i) printf("%d\n",i);
			}};break;
	case 5:{m=10000;M=99999;
	        for(i=m;i<=M;i++)
			{
			a=i%10;
			b=(i%100-a)/10;
			c=(i%1000-i%100)/100;
			d=(i%10000-i%1000)/1000;
			e=(i%100000-i%10000)/10000;
			if(a*a*a*a*a+b*b*b*b*b+c*c*c*c*c+d*d*d*d*d+e*e*e*e*e==i) printf("%d\n",i);
			}};break;
	case 6:{m=100000;M=999999;
	        for(i=m;i<=M;i++)
			{
			a=i%10;
			b=(i%100-a)/10;
			c=(i%1000-i%100)/100;
			d=(i%10000-i%1000)/1000;
			e=(i%100000-i%10000)/10000;
			f=(i%1000000-i%100000)/100000;
			if(a*a*a*a*a*a+b*b*b*b*b*b+c*c*c*c*c*c+d*d*d*d*d*d+e*e*e*e*e*e+f*f*f*f*f*f==i) printf("%d\n",i);
			}};break;
	default:printf("No output.\n");break;
	};
	return 0;
}
