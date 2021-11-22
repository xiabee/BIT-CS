#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
	int i,j,h,k=0;
	char a,b;
	scanf("%c%d",&a,&h);
	for(j=1;j<=2*h-1;j++){
	  if(j<=h)
	    k++;
	  else
	    k--;
	  b=a+k-1;
	  for(i=1;i<=h+k-1;i++)
	    if(i==h+k-1||i==h-k+1)
	      printf("%c",b);
	    else
	      printf(" ");
	  printf("\n");
	}
	return 0;
}
