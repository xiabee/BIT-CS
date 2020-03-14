#include<stdio.h>
int fa,fb;
int p[55];
int main()
{
    int N,Na,Nb,na[1000],nb[1000],i,j;
    scanf("%d%d%d",&N,&Na,&Nb);

    p[0]=p[11]=p[22]=p[33]=p[44]=2;
    p[20]=p[30]=p[31]=p[42]=p[43]=1;
    for(i=1;i<5;++i)
        for(j=0;j<i;++j)
            p[j*10+i]=!p[i*10+j];//对折，赢变输，输变赢

    for(i=0;i<Na;i++)
        scanf("%d",&na[i]);//甲出手周期

    for(i=0;i<Nb;i++)
        scanf("%d",&nb[i]);//乙出手周期

    for(i=0;i<N;i++)
    {
        int a=i%Na,b=i%Nb;//到甲的周期的a个动作和乙周期的第b个动作
        int k=p[na[a]*10+nb[b]];//判断
        if(k==0)
            fa++;//表甲赢+1
        if(k==1)
            fb++;//乙赢+1
    }
    printf("%d %d",fa,fb);
    return 0;
} 
