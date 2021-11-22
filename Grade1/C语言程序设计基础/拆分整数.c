/* PRESET CODE BEGIN - NEVER TOUCH CODE BELOW */  
#include <stdio.h>  
int main()   
{  
   int n, count( );  
   scanf("%d",&n);  
   printf("%d\n", count (n, n-1));    
   return 0;  
}  

int count( int n,int m )   
{   
	if(m<1||n<1)
		return 0;
	if(m==1||n==1)
		return 1;
	if(n<m)
		return(count(n,n));
	if(n==m)
		return(count(n,m-1)+1);
	else
		return(count(n-m,m)+count(n,m-1));		
}     
  
/* PRESET CODE END - NEVER TOUCH CODE ABOVE */  
