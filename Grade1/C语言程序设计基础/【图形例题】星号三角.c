#include<stdio.h>
int main()
{
	int n,i,j;
	scanf("%d",&n);
	for(i=0;i<n-1;i++)//´òÓ¡Ç°n-1ÐÐ 
	{
		for(j=0;j<n-1+i;j++)
		{
			if(j==n-i-1)
				printf("*");
			else
				printf(" ");
		}
		printf("*\n");
	}
	for(i=0;i<2*n-1;i++)
		printf("*");
	printf("\n");
	return 0;
}
