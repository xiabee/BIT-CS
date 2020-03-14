#include<stdio.h>
#define N 30
int main()
{
	int i,j,n,m,a[N],b[N],p,k,sum=0;
	scanf("%d %d",&n,&m);					//输入龙头数与勇士人数； 
	if(n>m)									
	{
		printf("bit is doomed!\n");			//龙头数大于勇士人数时，北理工GG； 
		return 0;
	}
	for(i=0;i<n;i++)						//龙头数小于等于勇士人数时 
		scanf("%d",&a[i]);					//用a[N]记录龙头直径； 
	for(i=0;i<m;i++)
		scanf("%d",&b[i]);					//用b[N]记录勇士身高； 
	for(i=0;i<n-1;i++)
	{
		p=i;
		for(j=i+1;j<n;j++)
		{
			if(a[p]>a[j])
				p=j;
		}
		if(p!=i)
			k=a[p],a[p]=a[i],a[i]=k;
	}										//a[N]排序； 
	for(i=0;i<m-1;i++)
	{
		p=i;
		for(j=i+1;j<m;j++)
		{
			if(b[p]>b[j])
				p=j;
		}
		if(p!=i)
			k=b[p],b[p]=b[i],b[i]=k;
	}										//b[N]排序； 
	for(i=0,j=0;i<m;i++)
	{
		if(j==n)
			break;
		if(a[j]<=b[i])						//能够砍下的龙头； 
		{
			j++;
			sum+=b[i];
		}

	}
	if(j!=n)								//龙头剩余； 
		printf("bit is doomed!\n");
	else
		printf("%d\n",sum);
	return 0;
}
