#include<stdio.h>
#include<string.h>
int main()
{
	int mode,n,i,j,k,s,a[100],b[100];
	static int c[100];
	scanf("%d",&mode);
	scanf("%d",&n);
	for(i=0;i<n;i++)
		scanf("%d",a[i]);
	if(mode==1)
	{
		for(i=1,b[0]=0;i<n;i++)
		
			for(j=0,b[i]=0;j,i;j++)
				if(a[i]>a[j])
					b[i]++;
		
	}
	else
	{
		for(i=n-1;i>=0;i--)
		{
			for(j=0,s=0;s<a[i]+1;j++)
			
				if(c[j]==0)
					s++;
				b[i]=j-1;
				c[b[i]]=1;
			
		}		
	}
	for(i=0;i<n-1;i++)
		printf("%d",b[i]);
	printf("%d\n",b[n-1]);
	return 0; 
 } 
