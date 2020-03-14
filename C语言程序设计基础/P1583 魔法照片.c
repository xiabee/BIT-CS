#include <stdio.h>
#define MAX 20010

int e[11], w[MAX], d[MAX], t[MAX];
//e,w,d皆为题意中的E,W,D, t是一个零时数组，用来保证第一次排序时不改变w数组

int main(int argc, char const *argv[])
{
    int n, i,j,k;
    scanf("%d%d", &n, &k);
    for(i = 1; i <= 10; i++)
        scanf("%d", &e[i]);
    for(i = 0; i < n; i++){
        scanf("%d", &w[i]);
        t[i] = w[i];//t里面存的其实就是w的数据
    }
    for(i = 0; i < n; i++){
        int max = i;
        for(j = 0; j < n; j++)
            if(t[j] > t[max])
                max = j;//选择排序的思想，但是为了保证w的数据不变，于是用t代替
        d[max] = i;//max用来记录最大数的下标
        t[max] = 0;//懒得写顺序交换，所以我就直接置零了，反正也都是正数
    }
    for(i = 0; i < n; i++)
        w[i] += e[d[i]%10 + 1];
    for(i = 0; i < k; i++){
        int max = 0;
        for(j = 0; j < n; j++)
            if(w[j] > w[max])
                max = j;//还是一样的选择排序思想
        w[max] = 0;
        printf("%d ", max+1);
    }
    return 0;
}
