/* PRESET CODE BEGIN - NEVER TOUCH CODE BELOW */  
 
#include<stdio.h>  
int f(int x); //需要你编写的函数  
int main() {  
    int x;  
    scanf("%d",&x);  
    printf("%d\n",f(x));  
    return 0;  
}  
  
/* PRESET CODE END - NEVER TOUCH CODE ABOVE */ 
int f(int x)
{
	if(x==1)
		return 5;
	if(x==2)
		return 1;
	else
		return (f(x-2)+f(x-1)+3);
}
