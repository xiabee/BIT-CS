#include<stdio.h>
#include<stdlib.h>
int dp[100000000];
int weather[100000000];
int comp(const void*a,const void*b)
{
    return *(int*)b-*(int*)a;//快排
}
int main()
{
    int n,i;
    scanf("%d",&n);
    dp[0]=1;//边界值
    for(i=0;i<n;i++)
    {
        scanf("%d",&weather[i]);
        if(i==0)
        {
            continue;
        }
        if(weather[i]>weather[i-1])//如果成上升趋势就加一
        {
            dp[i]=dp[i-1]+1;
        }
        else//下降了，从来
        {
            dp[i]=1;
        }
    }
    qsort(dp,n,sizeof(int),comp);//排序找出最大的
    printf("%d",dp[0]);//从大到小排，大的在第一个
    return 0;
}
