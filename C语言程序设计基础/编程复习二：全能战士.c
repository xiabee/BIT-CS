#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{ int n,n1,n2,n3,n12,n23,n31,n123;
  scanf("%d %d %d %d %d %d %d",&n,&n1,&n2,&n3,&n12,&n23,&n31);
  n123=n-n1-n2-n3+n12+n23+n31;
  printf("%d\n",n123);
  system("PAUSE");	
  return 0;
}
