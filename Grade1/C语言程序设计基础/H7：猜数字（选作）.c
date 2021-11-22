#include <stdio.h> 
#include <math.h> 
int main() 
{ 
	int i,n=0; 
	while(1) 
	{ 
	scanf("%d",&i);   
	if(i==0)
		break; 
	n+=pow(2,i-1); 
	} 
	printf("%d\n",n); 
	return 0; 
} 
