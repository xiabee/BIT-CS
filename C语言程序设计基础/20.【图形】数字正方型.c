#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
	int n,m,i;
	scanf("%d",&n);
	for(m=1,i=1;m<=n*n;m++){
	  printf("%3d",m);
	  if(i==n){
	    printf("\n");
	    i=1;
      }
      else
        i++;
    }
	return 0;
}
