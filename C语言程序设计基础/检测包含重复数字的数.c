#include<stdio.h>
int a[5]={0};
void divide(int x)
{
	a[4]=x%10;
	x/=10;
	a[3]=x%10;
	x/=10;
	a[2]=x%10;
	x/=10;
	a[1]=x%10;
	x/=10;
	a[0]=x%10;
	int i;
	for(i=0;i<5;i++)
	{
		if(a[i]==0)
			a[i]=-1;
		else
			break;
	}
	return;
}
int judge()
{
	int i,j;
	for(i=0;i<4;i++)
	{
		for(j=i+1;j<5;j++)
		{
			if(a[i]!=-1&&a[i]==a[j])
				return 1;
		}
	}
	return 0;
}
int main()
{
	int m,n,i,j,count=0;
	scanf("%d%d",&m,&n);
	for(i=m;i<=n;i++)
	{
		divide(i);
		j=judge();
		if(j)
		{
			count++;
			if(count==1)
				printf("%d",i);
			else
				printf(",%d",i);
		}
	}
	if(count)
		printf("\n");
	else
		printf("No output\n");
	return 0;
}
