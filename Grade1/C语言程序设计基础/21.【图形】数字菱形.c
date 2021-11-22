#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
	int a,i,j,k,p,q;
	scanf("%d",&a);
	k=a-1;
	p=a;
	for(i=1;i<=a*2-1;i++){
	  q=a+1;
	  if(i<=a){
	    k++;p--;
      }
      else{
	    k--;p++;
      }
	  for(j=1;j<=p;j++)
	  	printf("  ");
	  for(;j<=k;j++){
        if(j<=a)
	      q--;
	    else
	      q++;
	    printf("%-2d",q);
      }
	  printf("\n");
    }
	return 0;
}
