#include<stdio.h>
#include<string.h>
int main()
{
	int m,n;
	scanf("%d%d",&m,&n);//mÊÇÐÐÊý£» 
	int i,j,k,x;
	
	for(i=0;i<m;i++)
	{
		for(j=0;j<m-i;j++)
		{
			if(j==0)
			{
				x=n+i;
				while(x>9)
					x%=10;
				printf("%d",x);
			}
				
			else if(j==m-i-1)
			{
				x=2*m+n-2-i;
				while(x>9)
					x%=10;
				printf("%d\n",x);
			}
			else
				printf(" ");
		}
	}
	return 0;
}
