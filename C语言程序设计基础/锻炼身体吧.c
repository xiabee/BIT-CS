#include<stdio.h>
#include<math.h>
int main()
{
	int a,b,c,N,i=0;
	scanf("%ld",&N);
		for(c=1;c<=N;c++)
		{
			for(b=1;b<=c;b++)
			{
				for(a=1;a<=b;a++)
				{
				if(c*c==a*a+b*b)
			i++;
			else
			i=i;
				}
			}
		}		
		printf("%ld",i);
	return 0;
 } 
