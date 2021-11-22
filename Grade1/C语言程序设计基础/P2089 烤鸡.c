#include<stdio.h>
int ans[9000][10],m=0,num=-1,n,buff[10]={-999};
//m质量，num答案个数(后面要加回1),n为输入
void dfs(int step)
{
    int i;
    if(step==9)//或者step==10时判断是否n==m
    {
        int d=n-m;
        if(d>=1&&d<=3)
        {
            int j;
            buff[9]=d;
            num++;
            for(j=0;j<10;j++)
                ans[num][j]=buff[j];
        }        
        return ;
    }
    for(i=1;i<=3;i++)
    {
        m+=i;
        buff[step]=i;
        dfs(step+1);
        m-=i;
        buff[step]=-999;
    }
}
int main(void)
{
    int i,j;
    scanf("%d",&n);
    dfs(0);
    printf("%d\n",num+1);
    for(i=0;i<=num;i++)
    {
        for(j=0;j<10;j++)
            printf("%d ",ans[i][j]);
        printf("\n");
    }
    return 0;
}
