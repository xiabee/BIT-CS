#include<stdio.h>
void order(int(*p)[4]);
int main()
{ 	
	int a[3][4],i,j;
  	int(*p)[4];
   	for(i=0;i<3;i++)
    for(j=0;j<4;j++)
     	scanf("%d",&a[i][j]);
  	p=a;
  	order(p);
  	return 0;
}
void order(int(*p)[4])
{ 
	int temp,k,j,i,b[]={0,0,0};
 	for(j=0;j<3;j++)
  		for(i=0;i<4;i++)
  			b[j]+=*(*(p+j)+i);
 	for(j=0;j<2;j++)
  		for(i=j+1;i<3;i++)
  		{
			if(b[j]<b[i])
			{
				for(k=0;k<4;k++)
                {
					temp=*(*(p+i)+k);
     				*(*(p+i)+k)=*(*(p+j)+k);
     				*(*(p+j)+k)=temp;
				}
			}
  		}
  		for(j=0;j<3;j++) 
   			for(i=0;i<4;i++)
    			if(i!=3) 
					printf("%d,",*(*(p+j)+i));
    			else 
					printf("%d\n",*(*(p+j)+i));
}
