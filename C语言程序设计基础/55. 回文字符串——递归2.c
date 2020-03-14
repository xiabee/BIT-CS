#include<stdio.h>
#include<math.h>
#include <string.h>
int hanshu(char *p)
{
	char *q=p;
	while(*q!='\0')
		q++;
	if(q==p)
		return 1;
		q--;
	if(*p==*q)
	{	
		*q='\0';
		return hanshu(p+1);
	}
	else
		return 0;
}
int main()
{
	char str[100];
	gets(str);
	if(hanshu(str))
		printf("Yes\n");
	else
		printf("No\n");
}
