#include<stdio.h>  
#include<string.h>  
int main()  
{  
	char a[50];	
	gets(a);  
	int l = strlen(a);  
	printf("Hi,there,");  
	for(int i = 0; i < l; i++)  
		printf("%c", a[i]);  
	printf("!\n");  
}