#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{//system("mode con cols=200 lines=300");

 int n,j0,t;
 char a;
 register int i,j;
 scanf("%d %c",&n,&a);
 if(n==1){
 	printf("%c\n",a);
 	return 0;
 } 
 for(i=0;i<n;i++){
     for(j=0;j<n*2-1;j++){
         if(j<n)
             if(j==i){
                 t=a+i;
                 while(t>90) t-=26;
                 printf("%c ",t);
             }
             else if(j==0||i==n-1){
                      t=a+3*n-3-i-j;
                      while(t>90) t-=26;
                      printf("%c ",t);
                  }
                  else printf("  ");
         else{
             j0=2*n-1-j-1;
             if(j0==i){
                 t=a+i;
                 while(t>90) t-=26;
                 printf("%c",t);
                 if(j0!=0) printf(" ");
             }
             else if(i==n-1||j0==0){
                      t=a+3*n-3-i-j0;
                      while(t>90) t-=26;
                      printf("%c",t);
                      if(j0!=0) printf(" ");
                  }
                  else printf("  ");
         }
     }
     printf("\n");
  }

  return 0;
}
