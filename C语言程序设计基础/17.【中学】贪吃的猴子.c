#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
	int n,p;
	scanf("%d",&n);
	if(n==1)
	  printf("The monkey got 1 peach in first day.\n");
	else{
	  for(p=1;n!=1;n--)
	    p=(p+n-1)*2;
	  printf("The monkey got %d peaches in first day.\n",p); 
	}
	return 0;
}
