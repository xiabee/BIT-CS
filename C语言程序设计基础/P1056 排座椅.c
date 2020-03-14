#include <stdio.h>
#define min(x,y) (x<y?x:y)
int main()
{
    short M,N,row[999]={0},column[999]={0},K,L,D,i,X[2000],Y[2000],P[2000],Q[2000];        
    scanf("%hd %hd %hd %hd %hd",&M,&N,&K,&L,&D);        
    void passageway(short[],short,short);                //函数passageway用于给出开辟通道的最优方案
    for(i=0;i<D;i++)                                    //每对相邻的爱说话的两个同学
        scanf("%hi%hi%hi%hi",&X[i],&Y[i],&P[i],&Q[i]);    
    while(i--)                                            //对于每对相邻的爱说话的两个同学
        if(X[i]==P[i])                                    
            column[min(Y[i],Q[i])-1]++;                    
        else                                            //当他们位于同一列的相邻行时
            row[min(X[i],P[i])-1]++;                    
    passageway(row,K,M);                                //输出需要开辟的K条横向通道的位置
    passageway(column,L,N);                                //输出需要开辟的L条纵向通道的位置
    return 0;
}
void passageway(short _[],short way,short all)            //way为要求开辟的通道数，all为座位总行/列数
{
    short t,passage=0,limit=0;                            //limit为开辟通道所需的爱说话同学的对数下限
    while(passage!=way)                                    //当下限limit设定不合适时
        for(t=passage=0,limit++;t<all;t++)                //增加下限limit，重新计算此时开辟的通道数
            passage+=_[t]>=limit;                        //使其恰好等于要求开辟的通道数
    for(t=0;way;t++)                                    //当下限limit设定合适时
        if(_[t]>=limit)
            printf(--way?"%d ":"%d",t+1);                //输出开辟的各条通道的位置
    puts("");                                            //换行
}

