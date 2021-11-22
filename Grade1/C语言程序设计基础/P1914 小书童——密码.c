#include <stdio.h>
int main()
{
    char in[100]; 
    int n, j; 
    scanf("%d%s", &n, in); //∂¡»Î 
    for(j = 0; in[j] != '\0'; j++)
        putchar((in[j]-'a'+n)%26+'a'); 
}
