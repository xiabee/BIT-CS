#include<stdio.h>
int main() {
	int n,m,sum=0;
	scanf("%d",&n);
	for(int i=1;i<=n;++i) {
		for(int j=1;j<=n;++j) {
			if(i%j==0)
				sum++;
		}
	}
	\\printf("%d\n",sum);
}
