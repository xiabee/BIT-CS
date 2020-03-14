#include<stdio.h>
int n,l,yy,sum,col[100000],left[100000],right[100000],a[100000];
void print()//这样显得程序功能更加简明
{
    int i;
	if(sum<3)//因为只需要输出前三组解，所以就记个数
    {
        for(i=1;i<=yy;i++)
        printf("%d ",a[i]);//printf比cout快 printf比cout快 printf比cout快 重要的事情说三遍
        printf("\n");
        sum++;//计数器++哈哈哈哈哈
    }
    return;
}
int has(int x,int y)
{
    if(col[y]==1||left[x+y]==1||right[x-y+10000]==1)//判断一下这个地方能不能放皇后
    return 0;//不能就返回0
    else
    return 1;//能就返回1
}
void search(int x)
{
    int i;
	if(x>yy)
    {
        n++;
        print();
        return;
    }
    for(i=1;i<=yy;i++)
    if(has(x,i)==1)
    {
        a[x]=i;
        col[i]=left[x+i]=right[x-i+10000]=1;//将皇后威力所及之处都变成1
        search(x+1);
        col[i]=left[x+i]=right[x-i+10000]=0;//要是回来了，就说明这个皇后得卸掉，所以把这个皇后的威力清零
    }
}
int main()
{
	int i;
    scanf("%d",&yy);
    for(i=0;i<10000;i++)
    a[i]=col[i]=left[i]=right[i]=0;
    search(1);
    printf("%d",n);
    return 0;
}
