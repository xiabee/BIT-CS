#include <stdio.h>
#include <stdlib.h>
#define N 10
int main(int argc, char *argv[]) {
	static int mark[N],i,j,num[N];
	int p,m,k;
	for(i=0;i<N;i++) scanf("%d",&mark[i]);
    for(i=0;i<=N-1;i++){
    	p=i;
    	for(j=i+1;j<=N-1;j++)
    	  if(mark[p]<mark[j]) p=j;
    	num[i]=p+1;
		if(p!=i){
    		m=mark[p];
    		mark[p]=mark[i];
    		mark[i]=m;
    	}
    }
    printf("%d\n",num[0]);
	for(k=0;k<N-1;k++){
		if(mark[k]==mark[k+1]) printf("%d\n",num[k+1]);
		else break;
	}
	return 0;
}
