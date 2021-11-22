#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
	int i,j,k=0,p=0;
	static char a[100],b[100];
	scanf("%s",b);
	
	for(i=0;i<=99;i++){
		for(j=0,p=0;j<=99;j++)
		    if(a[j]==b[i]) p=1;
		if(p==0) {
		    a[k]=b[i];k++;
	    }
    }
    
	puts(a);
	return 0;
}
