#include<stdio.h>
int a[200],b[100];

void exchange(int n) 
{
	int i;
	for(i=0;i<n;i++)
		b[i]=a[i+n];
	for(i=n-1;i>0;i--)
		a[2*i+1]=a[i];
	for(i=0;i<n;i++)
		a[2*i]=b[i];
}
int flag(int n)
{	
	int x[200];
	int s;int flag;int i;
	for(s=1;s<=n;s++)
    {	
    	x[s]=i;
        if(x[s]==a[s])
        {
            return 0;
            break;
        }
    }
}
int main()
{
	int m,n,i;
	int flag(int);
	void exchange(int);
	scanf("%d",&n);
	for(i=0,m=n*2;i<m;i++) 
	a[i]=i;
	i=0;
	do
	{
		exchange(n); 
		i++;
	}
	while(flag(m));
	printf("%d\n",i);
	return 0;
}
