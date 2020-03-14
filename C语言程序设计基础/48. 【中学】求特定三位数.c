#include<stdio.h>
#include <stdlib.h>
int main(int argc, char *argv[])
{
	int a,m,n[9]={1,2,3,4,5,6,7,8,9},x[9],t,temp,sum;
	int i,j,k,p,flag=0,f;
	scanf("%d",&a);
	x[0]=a;
	x[3]=a*2;
	x[6]=a*3;
	if(a>3) flag=0;
	else for(i=0;i<9;i++)
	{
		if(i==x[0]-1||i==x[3]-1||i==x[6]-1) 
			continue;
		else for(j=1;j<9;j++)
		{
			if(j==x[0]-1||j==x[3]-1||j==x[6]-1)
				continue;
			else
			{
				m=a*100+n[i]*10+n[j];
				if(m*3>999) 
					continue;
				else 
				{
					x[0]=a;
					x[1]=n[i];
			        x[2]=n[j];
			        x[3]=m*2/100;
			        x[4]=m*2%100/10;
			        x[5]=m*2%10;
			        x[6]=m*3/100;
			        x[7]=m*3%100/10;
			        x[8]=m*3%10;
				    for(k=0,sum=0;k<9;k++)
					{
				        sum+=x[k];
				    }
				    for(k=0;k<8;k++)
					{
				   	    t=k;
				    	for(p=k+1;p<9;p++)
						{
				    		if(x[t]>x[p]) 
								t=p;
				   	    }
				     	if(t!=k)
						 {
				   	    	temp=x[t];
				   	    	x[t]=x[k];
				   	    	x[k]=temp;
				   	    }
				    }
				    for(k=0,f=1;k<8;k++)
					{
				        if(x[k]>=x[k+1]) 
							f=0;
				    }
				    if(sum==45&&f==1)
					{
				    	flag=1;
				    	printf("%d,%d,%d\n",m,m*2,m*3); 
					}
				}
			}
	    }
	}
	if(flag==0) 
		printf("0,0,0\n");
	return 0;
}
