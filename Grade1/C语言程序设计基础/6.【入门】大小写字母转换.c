#include <stdio.h>
#include <stdlib.h>
int main(int argc, char *argv[])
{
  char a;
  scanf("%c",&a);
  if (a>=65&&a<=90) a=a+32;
  else if(a>=97&&a<=122) a=a-32;
  printf("%c\n",a); 
  system("PAUSE");	
  return 0;
}
