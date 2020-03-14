#include<stdio.h>
int main()
{
	int n,x,i,count=0,b,c;
	scanf("%d %d",&n,&x);
	for(i=1;i<=n;i++)
	{
		b=i;
		while(b!=0)
		{
			c=b%10;
            b=b/10;
            if(c==x) 
				count++;
		}
	}
	printf("%d\n",count);
	return 0;
}
