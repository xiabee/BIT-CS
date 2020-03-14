#include <stdio.h>
#include <stdlib.h>

/*请使用递归算法计算正整数n和m的最大公约数GCD(n,m)。

　　     = m                   当m<=n 且 n mod m =0
GCD(n,m) = GCD(m,n)            当n<m时
         = GCD(m, n mod m)     其他

输入：n和m
输出：n和m的最大公约数*/

int main(int argc, char *argv[]) {
	int n,m,gcd; 
	int GCD(int n, int m);
	scanf("%d %d",&n,&m);
	gcd=GCD(n,m);
	printf("%d\n",gcd);
	return 0;
}
int GCD(int n, int m){
	int gcd;
	if(m<=n&&n%m==0) gcd=m;
	else if(n<m) gcd=GCD(m,n);
	     else gcd=GCD(m,n%m);
    return gcd; 
}
