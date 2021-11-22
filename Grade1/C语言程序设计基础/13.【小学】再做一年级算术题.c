#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
  int a,b,c=0;
  char op;
  scanf("%d%c%d",&a,&op,&b);
  switch(op)
  {case 43:c=a+b;break;
   case 45:c=a-b;break;
   case 42:c=a*b;break;
   case 47:c=a/b;break;
   case 37:c=a%b;break;
  } 
  printf("%d\n",c);
  system("PAUSE");	
  return 0;
}
