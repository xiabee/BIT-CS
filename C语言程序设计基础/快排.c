#include<stdio.h>
int t[200001];
void merge_sort(int a[],int l,int r)
{
    int mid;
    if(l==r)return;
    mid=(l+r)/2;
    merge_sort(a,l,mid);
    merge_sort(a,mid+1,r);
    //分离
    int p=l,j=mid+1,i=l;
    while(i<=mid&&j<=r)
    {
        if(a[i]<a[j])
        t[p++]=a[i++];
        else
        t[p++]=a[j++];
    }
    while(i<=mid)t[p++]=a[i++];
    while(j<=r)t[p++]=a[j++];
    //合并
    for(i=l;i<=r;i++)
    a[i]=t[i];
}//赋值
int main()
{
    int b[200001]={0},s=0,n,i,a[200001];//记得定大一点
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
    }
    merge_sort(a,1,n);//较快的排序
    for(i=1;i<=n;i++)
printf("%d ",a[i]);//输出
}
