#include<stdio.h>
int main() {
	int c,m,i,j;
	scanf("%d %d",&c,&m);
	if(c==1) {
		printf("%d",m);
		return 0;
	}else {
		for(i=1;i<=c;++i) {
			for(j=1;j<=i-1;++j)
				printf(" ");
			if(i==1) {
				for(int k=1;k<=(3*c-2+1)/2;++k)
					printf("%d",(m+k-1)%10);
				for(int k=(3*c-2)/2;k>=1;--k)
					printf("%d",(m+k-1)%10);
			}else
			if(i==c) {
				for(int k=1;k<=(c+1)/2;++k)
					printf("%d",(c+k+m-2)%10);
				for(int k=c/2;k>=1;--k)
					printf("%d",(c+m+k-2)%10);
			}else {
				printf("%d",(m+i-1)%10);
				for(int k=1;k<=3*c-2*i-2;++k)
					printf(" ");
				printf("%d",(m-1+i)%10);
			}
			printf("\n");
		}
	}
}
