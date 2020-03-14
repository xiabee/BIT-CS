#include<stdio.h>
int main()
{
	int i,j,n;
	scanf("%d",&n);
	for(i=1;i<=n;++i) 
	{
		for(j=1;j<=n-i;++j) 
		{
			printf(" "); // n-i个空格 
		}
		if(i==1)
		{
			printf("*"); // 一个* 
		}else if(i==n)
		{
			for(j=1;j<=2*n-1;++j)
			{
				printf("*"); // 2*n-1个空格 
			}
		}else // 除了第一行与最后一行的其他行 
		{
			printf("*"); // 一个* 
			for(j=1;j<=2*i-3;++j)  
			{
				printf(" "); // 2*n-3个空格 
			}
			printf("*"); // 一个* 
		}
		printf("\n"); // 每行的换行符 
	}
}


