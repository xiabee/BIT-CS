#include <stdio.h>
int main()
{
    int n,a[11],i,j,t,v;
    scanf("%d",&a[0]);			//输入第一个数
    for (i=1;i<9;++i)
	{			//剩下的八个
        scanf("%d", &a[i]);
    }
    n=9;
    for(i=0;i<n;++i)	//选择排序
	{						
        t=i;
        for(j=i+1;j<n;++j)
		{
            if(a[t]>a[j])
				t=j;
        }
        if(t!=i)
		{
        	v=a[t],a[t]=a[i],a[i]=v;
        }
    }
    scanf("%d",&v);//要插入的数
    for (i=n-1;i>=0;--i)
	{
        if(a[i]>v)
		{
            a[i+1]=a[i];
        }
        else 
			break;
    }
    ++i;//插入位置
    a[i]=v;
    n++;
    for (i=0;i<n;++i)
	{//输出
        if(i==0)
		printf("%d",a[i]);
        else printf(",%d",a[i]);
    }
    printf("\n");
    return 0;
}
