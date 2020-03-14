#include <stdio.h>
#include <string.h>
int panhuiwen(char s);

int main()
{
 char s[20];
 gets(s);
 if(panhuiwen(s)==1)
 printf("Yes\n");
 else
 printf("No\n");
 return 0;
} 

int panhuiwen(char s)
{
 int i,n;
 char a[20];
 n=strlen(s);
 if(n<2)
 return 1;
 else
 {
 if(s[1]!=s[n-1])
 return 2;
 else
 {
 	for(i=1;i<n,i++)
	a[i-1]=s[i];
    return huiwen(a);
 }
 }
}
