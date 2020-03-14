#include <stdio.h>	
#include <string.h>	
int main()	
{	
	int a[13] = {0};  
	int tmp;	 
	for (int i = 0; i < 10; ++i)	
		scanf("%d", &a[i]);	
	
	for (int i = 0; i < 10; i++)	
	{	
		for (int j = 0; j + 1 < 10 - i; j++)	
		{	
			if(a[j]>a[j+1])	
			{	
				tmp = a[j];	
				a[j] = a[j+1];	
				a[j+1] = tmp;	
			}	
		}	
	}	
	printf("Canceled Max Score:%d\n", a[9]);	
	printf("Canceled Min Score:%d\n", a[0]);	
	printf("Average Score:%d\n", (a[1]+a[2]+a[3]+a[4]+a[5]+a[6]+a[7]+a[8])/8);	
}