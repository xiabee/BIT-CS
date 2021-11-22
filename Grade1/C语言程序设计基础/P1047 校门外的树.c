#include<stdio.h>
int main()
{
    int i,j,L,a[2],b[10001]={0},M,count=0;
    scanf("%d%d",&L,&M);
    for(i=1;i<=M;i++)
	{
        for(j=0;j<2;j++)
            scanf("%d",&a[j]);
        for(j=0;j<=L;j++)
            if(j>=a[0]&&j<=a[1]) 
				b[j]=1;
    }
    for(i=0;i<=L;i++)
        if(b[i]==0) 
			count++;
    printf("%d",count);
     return 0;
}
