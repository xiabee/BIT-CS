#include<stdio.h>
int main()
	{
	char a;
	while(1)
	{
		scanf("%c",&a);
		printf("The ASCII of character '%c' is %d.\n",a,a);
		if(a=='0')
			break;	
	}
	return 0; 
} 
