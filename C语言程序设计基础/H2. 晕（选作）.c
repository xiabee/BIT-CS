#include <stdio.h>   
int main()
{
   int a[10][10]={0},i,j=0,k,n,s,b,c=0;  
  scanf("%d",&n);
  for(i=0;i<n;i++)  
    a[0][i]=i+1;  
	s=a[0][--i];  
    s++;  
  for(k=1;k<n;k++)
  {
    b=n-k;  
    if(j<n/2)
	{
	  for(j++;c<b;j++,s++,c++) 
        a[j][i]=s;
	    j--;
	    c=0;
	}  
    else
	{
	  for(j--;c<b;j--,s++,c++)
        a[j][i]=s;
	    j++;c=0;
	}  
    if(i<n/2)
	{
	  for(i=i+1;c<b;i++,s++,c++)
        a[j][i]=s;
	    i--;
		c=0;
    }  
    else
	{
	  for(i=i-1;c<b;i--,s++,c++)
	    a[j][i]=s;
        i++;
	    c=0; 
	}  
  }  
  for(j=0;j<n;j++)
  {
    for(i=0;i<n;i++)
	  printf("%3d",a[j][i]);
	  printf("\n");
  }       
} 
