#include <stdio.h>
int main()
{
	int t,n,i,j,k,l,temp,a[10000][2];
	float s=0;
	scanf("%d",&t);
	for(i=0;i<t;i++)
	{
		scanf("%d",&n);
		s=0;
		for(j=0;j<n;j++) 
			scanf("%d %d",&a[j][0],&a[j][1]);
		for(j=0;j<n;j++)
		{
			for(k=0;k<n;k++)
			{
				if(k==j) 
					continue;
			for(l=0;l<n;l++)
			{
				if(l==k||l==j) 
				continue;
				temp=(a[k][0]-a[j][0])*(a[l][1]-a[j][1])-(a[k][1]-a[j][1])*(a[l][0]-a[j][0]);
				if(s<temp) 
				s=temp;
			}
		}
	}
	printf("%.1f\n",s/2);
	}
	return 0;
} 
