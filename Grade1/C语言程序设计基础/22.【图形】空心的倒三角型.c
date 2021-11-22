#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
	int h,i,j,b;
	scanf("%d",&h);
	for(i=1;i<=2*h-1;i++)
	  printf("*");
	printf("\n");
	for(j=2;j<=h;j++){
	  for(b=1;b<=2*h-j;b++)
	    if(b==j||b==2*h-j)
	      printf("*");
	    else
	      printf(" ");
	printf("\n");
    }
	return 0;
}
