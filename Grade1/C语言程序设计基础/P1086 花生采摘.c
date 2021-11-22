#include<stdio.h>
#include<stdlib.h>
int a[51][51];
int main()
{
    int n,m,k;
    int time,max,sum;
    int i,j;
    int x1,y1,x2,y2;
    int t;
    scanf("%d%d%d",&n,&m,&k);
    for(i=1;i<=n;i++)
     	for(j=1;j<=m;j++)
      	scanf("%d",&a[i][j]);
    time=k;
    x1=y1=0;
    sum=0;
    while(1)
    {
        max=t=0;
        for(i=1;i<=n;i++)
        	for(j=1;j<=m;j++)
            	if(a[i][j]>max) 
				{
					max=a[i][j]; 
					x2=i; 
					y2=j;
				}
        if(x1==0&&y1==0) 
			y1=y2;
        if(time-(abs(x1-x2)+abs(y1-y2)+x2+1)>=0)
        {
            sum+=a[x2][y2];
            time-=abs(x1-x2)+abs(y1-y2)+1;
            a[x2][y2]=0;
            x1=x2; 
			y1=y2;
        }
        else 
			break;
        for(i=1;i<=n;i++)
          	for(j=1;j<=m;j++)
           	{
		   		if(a[i][j]!=0) 
				t++;
			}
        if(t==0) 
		   	break;
    }
    printf("%d",sum);
    return 0;
}
