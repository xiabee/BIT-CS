#include <stdio.h>
#include <stdlib.h>

int main()
{ int a,n,max,i,j;
  scanf("%d",&a);
  max=a;
  for(i=a;i>2;i--)
  { n=1;
    for(j=2;j<i;j++)
      if(i%j==0)
      n=0;
    if(n==1) 
    {printf("The max prime number is %d.\n",i);
     return 0;
    }

  } 
  
  system("PAUSE");	

}
