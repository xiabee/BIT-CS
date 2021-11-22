#include<stdio.h>
int zhi(int x)
{
    int i;
    for(i=2;i*i<=x;i++)
    if(x%i==0)
    return 0;
    return 1;
}
//判断质数的自定义函数
int main()
{
    int i,j,n;
    scanf("%d",&n);
    if(zhi(n-4))
    {
    	printf("2 2 %d",n-4);
        return 0;
	}//特殊情况：前两个数都是2
    for(i=3;i<=n;i++)
    	for(j=3;j<=n;j++)//枚举
	    {
	      if(zhi(i)&&zhi(j)&&zhi(n-i-j))    //判断质数
	        {
	            printf("%d %d %d",i,j,n-i-j);
	            return 0;
	        }
	    }
}
