#include<stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
	int i,j,k,n,t,sum=0,G=0,max;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		sum=G=0;
        max=-1001;//max小于愉快度可能的最小值
		while(n--)
		{
			scanf("%d",&k);
			if(max<k)
			max=k;
		 	G=G+k>0?G+k:0;//if（G+=k>0）{G+=k;}else{0;}
			if(sum<G)
			sum=G;
		 } 
		if(max<=0)
		printf("%d\n",max);
		else
		printf("%d\n",sum);
	}
	return 0;
}
