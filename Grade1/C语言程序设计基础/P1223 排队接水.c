#include<stdio.h>
int w[100000001],o[100000001];
void qsort(int l,int r);
int main()
{
	int n,i,s=0;
    double j=0.0;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        scanf("%d",&w[i]);
        o[i]=i;
    }
    qsort(1,n);
    for(i=n;i>=1;i--)
    {
        printf("%d ",o[i]);
        j=j+s;
        s=s+w[i];
    }
    printf("\n");
    printf("%.2f",j*1.0/n);
}

void qsort(int l,int r)
{
	int i,j,k,t;
	i=l;
	j=r;
	t=w[(l+r)/2];
	while(i<=j)
	{
		while(w[i]>t)
			i++;
		while(w[j]<t)
			j--;
		if(i<=j)
        {
            k=w[i]; w[i]=w[j];    w[j]=k; 
            k=o[i]; o[i]=o[j];    o[j]=k; 
        	i++;j--;
        }
	}
	if(l<j)
		qsort(l,j);
    if(i<r)
		qsort(i,r);
}
