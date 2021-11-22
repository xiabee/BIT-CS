#include <stdio.h>
#include <math.h>

void main()
{
	int a, b, c;
	float dlt, x1, x2;

	scanf ("%d %d %d", &a, &b, &c);

	if (a == 0)  
	{ 
		if (b != 0) printf ("x=%.6f\n", (float)-c/b);
		else		printf ("Input error!\n");  
	}

	else 
	{
		(float) dlt = b*b*1.0 - 4.0*a*c;
		if (dlt == 0)   
		{
			x1 = -b/(2*a);
			printf ("x1=x2=%.6f\n", x1);
		}
		else if (dlt > 0)
		{
			x1 = (-b + sqrt(dlt))/(2*a);
			x2 = (-b - sqrt(dlt))/(2*a);
			printf("x1=%.6f\nx2=%.6f\n", x1, x2);
		}
	 
		else if (dlt < 0)
		{ 

			if (b == 0)
			{
	 x1 = (-b + sqrt(-dlt))/(2*a);
	 x2 = (-b - sqrt(-dlt))/(2*a);
	 printf("x1=%.6fi\nx2=%.6fi\n", x1, x2);
			}

			else{

			float s;

			(float) s = -b/(2.0*a);

			x1 = sqrt(-dlt)/(2*a);
			x2 = -sqrt(-dlt)/(2*a);
			printf("x1=%.6f+%.6fi\nx2=%.6f%.6fi\n",s,x1, s, x2);}
		}
	}
}