#include<stdio.h>
int main()
{
	long int n,sum=0;
	int x;
	scanf("%d %ld",&x,&n);
	while(n--)
    {
        if(x<=5)                
            sum+=250;        
        x=x%7+1;
    }
	printf("%ld\n",sum);
	return 0;
}
