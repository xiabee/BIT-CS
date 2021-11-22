#include<stdio.h>
#include<string.h>
int main()
{
	int n,a[100],t=0,m=0,s=0,i;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",a+i);
		t+=a[i];
	}
	t/=n;
	for(i=0;i<n;i++)
	{
		a[i]-=t;
		s+=a[i];
		if(s!=0)
			m++;
	}
	printf("%d\n",m);
	return 0;
}
