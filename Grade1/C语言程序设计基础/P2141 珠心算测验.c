#include <stdio.h>
#include <stdlib.h>
int main()
{
    int i, j, k, n, b, m;
    int a[100];
    scanf("%d", &n);    //输入数据个数
    for(i=0; i<n; i++)  //循环输入正整数值
    {
        scanf("%d", &a[i]);
    }
    b = 0;
    for(i=0; i<n-1; i++)   //冒泡排序
    {
        for(j=i+1; j<n; j++)
        {
            if(a[i] > a[j])
            {
                b = a[i];
                a[i] = a[j];
                a[j] = b;
            }
        }
    }
    m = 0;
    for(i=2; i<n; i++)  //遍历a[i]
    {
        for(j=0; j<i-1; j++)    //二层循环，控制j从第0个数据开始到i-1遍历a[i]
        {
            for(k=j+1; k<i; k++)    //三层循环，从k=j+1开始遍历到i
            {
                if(a[j]+a[k] == a[i])   //比较如果i前有两个不同数据之和等于a[i]则m+1
                {
                    m++;
                    goto skip;  //如果有一个符合条件的就用goto跳出多重循环，不用再比较其余的啦
                }
            }
        }
        skip: ;
    }
    printf("%d\n", m);
    return 0;
}
