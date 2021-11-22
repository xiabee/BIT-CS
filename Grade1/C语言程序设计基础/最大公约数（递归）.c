#include <stdio.h>
#include <stdlib.h>
int main(int argc, char *argv[]) 
{
	int n,m,gcd; 
	int GCD(int n, int m);
	scanf("%d %d",&n,&m);
	gcd=GCD(n,m);
	printf("%d\n",gcd);
	return 0;
}
int GCD(int n, int m)
{
	int gcd;
	if(m<=n&&n%m==0) 
		gcd=m;
	else if(n<m) 
		gcd=GCD(m,n);
	else 
		gcd=GCD(m,n%m);
    return gcd; 
}
