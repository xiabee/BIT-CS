#include<stdio.h>
#define N 7
int main()
{
	int t1[10]={0},t2[10]={0},x[10]={0},num[10]={0};
	int i=0,j=0,k=0,max=0,flag=0;
	for(i=0;i<N;i++)
		scanf("%d %d",&t1[i],&t2[i]);
	for(i=0;i<N;i++)
	{
		if(t1[i]+t2[i]>=10)
		{
			num[j]=i;
			j++;
			flag=1;
		}
	}
	if(flag==1)
	{
		max=0;
		for(k=0;k<j;k++)
		{
			if(x[max]<x[k])
			max=k;
		}
		printf("%d\n",num[max]+1);
	} 
	if(flag==0)
		printf("0\n");
	return 0;
}
