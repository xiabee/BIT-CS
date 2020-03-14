#include<stdio.h>
int count(int n)
{
   	if(n==1)
		return 1;
   	else if(n==2)
	   	return 2;
   	else if(n%2==1)
	   	return count(n-1);
   	else 
	   	return count(n/2)+count(n-1);     
}
int main()
{
  	int n;
  	scanf("%d",&n);
  	printf("%d\n",count(n));
 	return 0;
}
