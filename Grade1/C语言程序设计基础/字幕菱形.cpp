#include <stdlib.h>
#include <stdio.h>

main( )
{ char c;
  int i,j,n,flog;
  printf("\nPlease Enter char_below & rows:");
  scanf("%c %d",&c,&n);
  for(i=1;i<=2*n-1;i++)
    {for(j=abs(n-i);j>=1;j--)
       printf(" ");
     if(i!=1) flog=0;
     else flog=1;
     printf("%c",(c+2*(2*n-1-i)-flog-'A'+26*n)%26+'A');
     for(j=1;j<=2*n-3-2*abs(n-i);j++)
       printf(" ");
     if(i!=2*n-1&i!=1)
       printf("%c\n",(c-1+2*(2*n-1-i)-'A'+26*n)%26+'A');
     else printf("\n");
    }
  system("pause");
  return 0;
}
