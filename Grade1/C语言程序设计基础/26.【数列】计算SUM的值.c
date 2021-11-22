#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
	int i,n;
	double t,sum=0;
	scanf("%d",&n);
	for(i=1;i<=n;i++){
	  t=i;
	  sum+=1/t;
    }
	printf("sum=%f\n",sum);
	return 0;
}
