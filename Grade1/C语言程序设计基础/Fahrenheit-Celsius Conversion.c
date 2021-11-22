#include<stdio.h>
#include<math.h>
int main()
{
	int n,i=3;
	float a,b;
	while(i--)
	{
	scanf("%d %f",&n,&a);	
	switch(n)
	{
		
		case 1:b=(a-32.00)*5/9; 
			printf("The Centigrade is %.2f\n",b);
			break;							//摄氏度转华氏度 
		case 2:b=a*9/5+32.00;
			printf("The Fahrenheit is %.2f\n",b);
			break;							//华氏度转摄氏度
		default:printf("Wrong input!\n");							 
	} 
	}
	
	return 0;
	
 } 
