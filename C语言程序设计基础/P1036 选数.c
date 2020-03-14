#include <stdio.h>
#include <math.h>
#include <string.h>
#define MAX 40
int sort=0,n,k,a[MAX];
int sushu(int x) //是素数返回1，不是返回0
{
    int i,y;
    y=sqrt(x);
    for(i=2;i<=y;i++)
        if(x%i==0)
            return 0;
    return 1;
}
void f(int input[],int pos,int m) //f(被操作数组，所在位置，选m个数)
{
    if(m==0)
    {
        int j,sum=0;
        for(j=0;j<n;j++)
            if(input[j]==1)
                sum+=a[j];
        if(sushu(sum)==1)
            sort++;
        return;
    }
    else
    {
        int i;
        for(i=pos;i<n;i++)
        {
            if(input[i]==0)
                input[i]=1;
                f(input,i+1,m-1);
                input[i]=0;
        }
    }
    return;
}
int main()
{
    int input[MAX],i;
    scanf("%d%d",&n,&k);
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    memset(input,0,sizeof(int)*MAX);
    f(input,0,k);
    printf("%d\n",sort);
    return 0;
}
