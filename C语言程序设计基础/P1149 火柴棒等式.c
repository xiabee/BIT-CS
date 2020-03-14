# include <stdio.h>
# define max 1000                                            //宏定义加数上限
int match[10]={6,2,5,5,4,5,6,3,7,6};                        //数组match代表数字0—9对应的火柴棒数
int total (int n)                                            //函数total返回某自然数的总火柴棒数
{
    int temp=0;
    do
    {
        temp+=match[n%10];
        n/=10;
    }
    while(n);
    return temp;
}
int main()
{
    int number,A,B,equation=0;                                //等式的两个加数分别为A和B
    scanf("%d",&number);                                    //输入火柴棒的总数
    for(A=0;A<max;++A)
        for(B=0;B<max;++B)
            if(total(A)+2+total(B)+2+total(A+B)==number)    //加号和等号分别需要2根火柴棒
                equation++;                                    //所有的火柴棒刚好拼出一个等式
    printf("%i\n",equation);                                //输出可拼出不同等式的数量
    return 0;
}
