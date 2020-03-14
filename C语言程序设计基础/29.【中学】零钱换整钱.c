#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
	int n,a,b,c,flag=0;
	scanf("%d",&n);
	for(a=0;a<=100*n;a++){
		for(b=0;b<=8*n-a*2/25;b++){
			c=10*n-b/2-a/10;
			if(6*a==5*b&&3*b==4*c){
			    printf("%d,%d,%d\n",a,b,c);
			    flag=1;
			    goto k;
			}
		}
	}
k:	if(flag==0)
	    printf("No change.\n");
	return 0;
}
