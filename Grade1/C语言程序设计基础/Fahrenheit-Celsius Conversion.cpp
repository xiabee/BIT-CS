#include <stdio.h>   
int main()  
{  
	int a = 3, i = 0;  
	int num[4] = {0};  
	float in[4] = {0};  
	while(a--)  
	{  
		scanf("%d %f", &num[i], &in[i]);  
		i++;  
	}  
	for (int j = 0; j < i; j++)  
	{  
		if(1==num[j])  
			printf("The Centigrade is %.2f\n", (in[j]-32)/1.8);  
		else if(2==num[j])   
			printf("The Fahrenheit is %.2f\n", (in[j]*1.8)+32);  
		else  
			printf("Wrong input!\n");  
	}  
}