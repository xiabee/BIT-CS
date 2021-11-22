#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
	int a,b,c,d,i,j,p,q,m,flog;
	scanf("%d%d%d%d",&a,&b,&c,&d);
	for(m=1,flog=1;flog==1;m++){
		flog=0;
		for(i=0;i<=5&&flog==0;i++){
			for(j=0;j<=5-i&&flog==0;j++){
				for(p=0;p<=5-i-j&&flog==0;p++){
					for(q=0;q<=5-i-j-p&&flog==0;q++){
						if(m==a*i+b*j+c*p+d*q){
							flog=1;
						}
					}
				}
			}
		}
	}
	printf("The max is %d.\n",m-2); 
	return 0;
}
