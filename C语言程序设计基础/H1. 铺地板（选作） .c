#include <stdio.h>  
#include <stdlib.h>  
  
int main(int argc, char *argv[]){   
  int a[100][100],i,j,n;  
  scanf("%d",&n);  
  a[0][0]=1;  

  for(i=0,j=1;j<=n-1;j++)  
  a[i][j]=a[i][j-1]+((j%2!=0)?1:2*j);  
    
  for(i=1,j=n-1;i<=n-1;i++)  
  a[i][j]=a[i-1][j]+(((i+j)%2!=0)?1:4*n-2-2*(i+j));  
    
  for(i=1,j=0;i<=n-1;i++)  
  {  
    for(j=0;j<=n-2;j++)  
    {  
        if((j+i)%2!=0) a[i][j]=a[i-1][j+1]+1;  
        else a[i][j]=a[i-1][j+1]-1;  
    }  
  }          
     for(i=0,j=0;i<=n-1;i++)  
    {  
       for(j=0;j<=n-1;j++)  
       printf((j==n-1)?"%2d\n":"%2d ",a[i][j]) ;  
    }  
    return 0;  
}  
