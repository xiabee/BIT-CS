#include <stdio.h>
#include <stdlib.h>
int main(int argc, char *argv[])
{ 
	int n,i;
	scanf("%d",&n);
	for(;n>1;n=n/i)
		for(i=2;i<=n;i++)
		{	 
			if(n%i==0) 
			{
				printf("%d\n",i);
				break;
			}
		}
	//system("PAUSE"); 
	return 0;
} 
