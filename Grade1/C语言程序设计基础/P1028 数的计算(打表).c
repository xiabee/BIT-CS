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
  	int i;
  	printf("a[1000]={");
	for(i=1;i<1000;i++)
  		printf("%d,",count(i));
  	printf("}");
 	return 0;
}
