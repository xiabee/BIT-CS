#include <stdio.h>

/*一个正整数可以拆分成若干个正整数的和。例如正整数4，可以有4种拆分方法：
    4=3+1、4=2+2、4=2+1+1，4=1+1+1+1
用 n 表示待拆分的正整数，用 m 表示从 n 中拆出的最大正整数，则计算对正整数 n 共有多少种拆分方法可以下列递归公式：
              0     ( 当 n < 1 或 m < 1 时 ) 
              1                             ( 当 n = 1 或 m = 1 时 ) 
  count(n,m)= count(n, n)                   ( 当 n < m 时 ) 
              count(n, m-1) + 1             ( 当 n=m 时 ) 
              count(n-m, m) + count(n, m-1) ( 其他情况 )
编写递归函数，计算一个正整数有多少种拆分方法。

参数说明：n 待拆分的正整数，m 表示从 n 中拆出的最大正整数；
函数返回值是拆分方法数。
例如输入：4， 输出：4*/ 

int main() 
{
   int n,count();
   scanf("%d",&n);
   printf("%d\n",count(n,n-1));	
   return 0;
}

int count( int n, int m )  
{  if(n<1||m<1) return 0;
   else if(n==1||m==1) return 1;
        else if(n<m) return count(n,n);
             else if(n==m) return count(n,m-1)+1;
                  else return count(n-m,m)+count(n,m-1);
}

