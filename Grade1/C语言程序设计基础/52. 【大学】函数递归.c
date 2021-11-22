
#include <stdio.h>  
int main()  
{  int n,s, findf( int );  
   scanf("%d", &n);  
   s = findf(n);  
   printf("%d\n", s);  
   return 0;  
}
int findf(int n)
{
	int s;
	if(n>=0&&n<=4) s=1;
	else if(n>4&&n%2==0) s=findf(n-1)+findf(n-3);
	     else if(n>4&&n%2!=0) s=findf(n-2)+findf(n-4);
	          else s=-1;
    return s;
}
