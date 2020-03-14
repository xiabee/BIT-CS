#include<stdio.h>
#include<math.h>
int main()
{
	int a,b,c;
	double x1,x2,d;
	scanf("%d%d%d",&a,&b,&c);
	
	if(a==0)
	{
		
		if(b==0)
		{
			printf("Input error!\n");
		}
		else
		{
			
			x1=(-(double)c)/(double)b;
			if(x1==0)
			{
				x1=0.0;
			}
			if(x2==0)
			{
				x2=0.0;
			}
			printf("x=%.6f\n",x1);
		}
	}
	else
	{
		d=b*b-4*a*c;
	
		if(d<0)
		{
			x1=-(double)b/2/a;
			x2=(sqrt(-d))/2/a;
			if(x2==0)
			{
				x2=0.0;
			}
			if(x1==0)
			{
				printf("x1=%.6fi\nx2=-%.6fi\n",x2,x2);
			}
			else
			{
				printf("x1=%.6f+%.6fi\nx2=%.6f-%.6fi\n",x1,x2,x1,x2);
			}
		}
		else
		{
			x1=(-b+sqrt(d))/2/a;
			x2=(-b-sqrt(d))/2/a;
			if(d==0)
			{
				if(x1==0)
				{
					x1=0.0;
					x2=0.0;
				}
				printf("x1=x2=%.6f\n",x1);
			}
			else
			{
				if(x1==0)
				{
					x1=0.0;
				}
				if(x2==0)
				{
					x2=0.0;
				}
				printf("x1=%.6f\nx2=%.6f\n",x1,x2);
			}
		} 
		
	}
	return 0;
}
