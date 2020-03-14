#include<stdio.h>
#define integer 2147483648U
int main() 
{
	printf("%u",integer);
	printf("\012");
	printf("size of int : %d",sizeof(integer));
	printf("\xa");
}
