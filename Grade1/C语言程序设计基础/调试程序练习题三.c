#include <stdio.h>

int a[100];

int game(int n, int m, int k)            //递归大家做游戏
{                                                 //n:小孩总数，m：从下标为 m 的小孩开始报数，k:报数值
    int i, j=0, count = 0, g;             //j:当前报数值
    do
    {
        if(a[m]!=0)                           //报数小孩不能为空
        {
            j++;
            if( j == k )                        //报数到退出值
                a[m] = 0;                     //该小孩退出队
            m++;                             //报数
            if( m >= n )                     //当前报数者超出范围
                m=0;                         //循环到队首
        }
        else
            while( a[m] == 0 )           //跳过已出队者
            {
                m++;
                if(m>=n)
                    m=0;
            }
    }while( j <k );                         //报数一次，退出一个小孩
    for(i=0;i<n;i++)                       //统计还在队内的小孩个数
        if(a[i]!=0)
        {
            g=i+1;
            count++;
        }
    if( count == 1 )                        //剩一个小孩结束递归
        return(g);                             //返回队中最后一人编号
    while(a[m]==0)                        //计算下次开始报数小孩
    {
        m++;
        if(m>=n)
            m=0;
    }
    return(game(n,m,k));                 //递归调用报数函数
}

int main()
{
    int i,n,r;
    scanf("%d%d",&n,&r);                                    //输入小孩总数，报数值    
    for(i=0;i<n;i++)
        a[i]=i+1;                                                    //给小孩编号
    printf("The left child is NO %d.\n",game(n,0,r)); //从第一个小孩开始报数
    return 0;
}
