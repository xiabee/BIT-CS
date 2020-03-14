#include<stdio.h>
int main()
{
  	int i,j,k,a[10]={0},x,y,z,t=0;
  	scanf("%d%d%d",&x,&y,&z);
  	for(i=1;i<987;i++)
  	{
      	if(x*i<=987) 
      	{
         	a[x*i%10]++;
        	a[x*i/10%10]++;
          	a[x*i/100]++;
      	}
    	if(y*i<=987)
    	{
     		a[y*i%10]++;
       		a[y*i/10%10]++;
       		a[y*i/100]++;
    	}
   		if(z*i<=987)
   		{
        	a[z*i%10]++;
       		a[z*i/10%10]++;
       		a[z*i/100]++;
   		}
      	for(j=1;j<=9;j++)
       		if(a[j]==0)
         		break;
      	if(j>=10)
       	{
           	printf("%d %d %d\n",x*i,y*i,z*i);
           	t=1;
       	}
      	for(j=1;j<=9;j++)
        	a[j]=0;
   	} 
	if(t==0)
		printf("No!!!");
 	return 0;
}
