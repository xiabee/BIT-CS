#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
	int n,m=0,s=0;
	scanf("%d",&n);
	do{
	  m++;
	  s+=m;
    }while(s<n);
	printf("%d\n",m);
	return 0;
}
