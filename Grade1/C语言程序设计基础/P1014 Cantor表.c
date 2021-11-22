#include<stdio.h>
int main()
{
    int n,j;
    scanf("%d",&n);
    j=1;
    while (n-j>0)
        n=n-j++;//判断是在第几斜行
    if (j%2==0) //记得mod 2是0与是一不同
        printf("%d/%d",n,j-n+1);//是0是往↙的，第n项为n/j-n+1
    else 
		printf("%d/%d",j-n+1,n);//是1是往↗的，第n项为j-n+1/n(与mod2=0的相反)
    return 0;
}
