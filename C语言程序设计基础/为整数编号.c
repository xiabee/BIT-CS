#include <stdio.h>  
struct nn  
{  int no;     
   int num;     
};  
  
typedef struct nn DATA;   
int number( char * , DATA []); 
int main( )  
{     
   DATA b[100];    
   char sa[500];    
   int i, n;    
   gets( sa );   
   n = number( sa, b );   
   for ( i=0; i<n; i++ )   
       printf("%d %d\n", b[i].num, b[i].no );   
   return 0;  
}  
   
int number( char * str, DATA a[] )
{
	int i,j,k,num=0,f[100]={0};
  	DATA c[100],t;
  	for(i=0;str[i]!='\0';i++)
	{
  		if(str[i]==' ') 
			continue;
  		else 
		{
			if(str[i+1]>=48&&str[i+1]<=57)
			{
  				if(str[i+2]>=48&&str[i+2]<=57)
				{
  					a[num].num=(str[i]-48)*100+(str[i+1]-48)*10+(str[i+2]-48);
  					c[num].num=a[num].num;
  					i=i+2;
  					num++;
  				}
  			else
			{
  				a[num].num=(str[i+1]-48)*10+(str[i+2]-48);
  				c[num].num=a[num].num;
  				i=i+1;
  				num++;
  			}
  			
  		}
  		else
		{
  		  a[num].num=str[i]-48;
		  c[num].num=a[num].num;
		  num++;
  		}

  		}
  	}
	for(i=0;i<num-1;i++)
	{
	  	k=i;
	  	for(j=i+1;j<num;j++)
		{
	  		if(c[k].num>c[j].num) 
				k=j;
	  	}
	  	if(k!=i)
		{
	  		t=c[k];
	  		c[k]=c[i];
	  		c[i]=t;
	  	}
	} 
	for(i=0;i<num;i++)
	{
	  	c[i].no=i+1;
	}
	for(i=0;i<num;i++)
	{
	  	for(j=0;j<num;j++)
		{
	  		if(a[i].num==c[j].num&&f[j]==0)
			{
	  			a[i].no=c[j].no;
	  			f[j]=1;
	  			break;
	  		}
	  	}
	  }
	  return num;
  }
