#include<stdio.h>
int main()
{
    int i,j,k,p,a1,a2,a3,a4,m=1,flag;
    scanf("%d%d%d%d",&a1,&a2,&a3,&a4);
    A: for(i=0;i<=5;i++)
    { 
        for(j=0;j<=5-i;j++) 
        { 
            for(k=0;k<=5-i-j;k++) 
            { 
                for(p=0;p<=5-i-j-k;p++) 
                { 
                    flag=1; 
                    if(a1*p+a2*k+a3*j+a4*i==m)
                    { 
                        flag=0; 
     	                m++; 
                        goto A; 
                    } 
                } 
            } 
        } 
    } 
    if(flag==1) 
	printf("The max is %d.\n",m-1);
    return 0;
} 

