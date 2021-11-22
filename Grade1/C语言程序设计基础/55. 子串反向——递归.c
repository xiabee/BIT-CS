/* PRESET CODE BEGIN - NEVER TOUCH CODE BELOW */

#include <stdio.h>
#include <stdlib.h>
void reverse( );
int main( )
{	char str[100];
	int start, end;
	gets(str);
	scanf("%d%d", &start, &end);
	reverse( str, start, end );
	printf("%s\n", str);
	return 0;
}

/* PRESET CODE END - NEVER TOUCH CODE ABOVE */

#include <string.h>
void reverse(char str[],int start,int end){
    char t;
    int n;
    n=strlen(str);
    if(end>n-1) end=n-1;
    if(start<end){
        t=str[start];
        str[start]=str[end];
        str[end]=t;
        reverse(str,start+1,end-1);
    }
}
