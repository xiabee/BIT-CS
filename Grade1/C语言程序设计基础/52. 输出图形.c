#include<stdio.h>
#include<stdlib.h>
int main()
{
	int n,j0,t;
 	char a;
 	register int i,j;
 	scanf("%d %c",&n,&a);
 	if(n==1)
	{
 		printf("%c\n",a);//只有一个字母； 
 		return 0;
 	} 
 	for(i=0;i<n;i++)//控制行操作； 
	{
     	for(j=0;j<n*2-1;j++)//控制列操作； 
		{
        	if(j<n)//左上角 
	        {
	        	if(j==i)//对角线处； 
				{
	                t=a+i;
	                while(t>90) 
						t-=26;
	                printf("%c ",t);
	            }
	            else if(j==0||i==n-1)
				{
	                t=a+3*n-3-i-j;
	                while(t>90) 
						t-=26;
	                printf("%c ",t);
	            }
	            else //剩余部分； 
					printf("  ");
			}
         	else//右上角； 
			{
            	j0=2*n-1-j-1;
            	if(j0==i)
				{
	                t=a+i;
	                while(t>90) 
						t-=26;
	                printf("%c",t);
	                if(j0!=0) 
						printf(" ");
	            }
	            else if(i==n-1||j0==0)
				{
	                t=a+3*n-3-i-j0;
	                while(t>90) 
						t-=26;
	                printf("%c",t);
	                if(j0!=0) 
						printf(" ");
	            }
            	else printf("  ");
        	}
    	}
    	printf("\n");
	}
  	return 0;
}

