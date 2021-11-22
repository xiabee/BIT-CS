#include<stdio.h>
int main()
{
	char a,b;
	scanf("%c",&a);
	if(a>=65&&a<97)
	{
		b=a+32; 
		printf("%c\n",b); 
	}
	else if(a>=97&&a<=122)
	{
		b=a-32;
		printf("%c\n",b);
	}
	else
	{
		printf("%c\n",a);
	}
return 0;	
 } 
