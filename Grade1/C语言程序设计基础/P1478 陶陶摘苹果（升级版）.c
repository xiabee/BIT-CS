#include<stdio.h>
#define swap {w=y[v+1];y[v+1]=y[v];y[v]=w;}
int main()
{
    short n,s,a,b,x[5001],y[5001],u,v,w,number=0;
    scanf("%hd %hd",&n,&s);                            //树上共有n个苹果，陶陶的总力气为s
    scanf("%hd %hd",&a,&b);                            //凳子高a，陶陶的手可以够到的最大高度为b
    for(u=0;u<n;u++)
        scanf("%hd %hd",&x[u],&y[u]);                //对于序号为u的苹果，其高度为x[u]，消耗的力气为y[u]
    while(u--)
        if(a+b<x[u])                                //当陶陶无法摘到序号为u的苹果时
            y[u]=s+1;                                //该苹果消耗的力气也应超出陶陶的总力气
    while(++u<n)
        for(v=0;v<n-u-1;v++)
            if(y[v]>y[v+1])
                swap                                //将所有苹果按照消耗的力气从小到大进行排序
    for(w=0;w<n && s>=0;w++)                        //陶陶剩余的力气不应小于0
        if((s-=y[w])>=0)
            number++;
    printf("%hd\n",number);                            //输出陶陶最多可以摘到的苹果数number
    return 0;
}
