# include <stdio.h>
# include <string.h>
int main()
{
    char n,o,b[20][9],p,y[9];
    int strbig(char*,char*);
    scanf("%d",&n);                       //输入n个正整数(n≤20)
    for(o=0,p=n;o-n;o++)
        scanf("%s",b[o]);               //保存在字符串数组b中
    while(--p)                           //利用冒泡排序法
        for(o=n-1;o>n-p-1;--o)           //将数组b中的数从“大”到“小”排序
            if(strbig(b[o],b[o-1]))       //即每当遇到比b[o-1]更“大”的数b[o]时
            {
                strcpy(y,b[o-1]);       //便以y作为临时字符串变量
                strcpy(b[o-1],b[o]);
                strcpy(b[o],y);           //使二者进行交换
            }
    do                                   //按照排列好的顺序依次输出各数
        printf("%s",b[p++]);           //即输出它们可以拼接成的最大数
    while(p-n);
    return !puts("");
}

int strbig(char *str1,char *str2)       //判断数str1是否“大于”数str2
{
    short k=strlen(str1),l,m=0;           //数str1和数str2的长度分别为k和l
    if(k==(l=strlen(str2)))               //若两数的长度相等
        return strcmp(str1,str2)>0;       //则直接由函数strcmp给出判断结果
    do                                   //否则便使两数左对齐，依次比较对应位
        if(str1[m%k]>str2[m%l])           //只要发现str1的某一位比str2的相应位大
            return 1;               //则说明数str1比数str2“大”
        else
            if(str1[m%k]<str2[m%l])       //只要发现str1的某一位比str2的相应位小
                return 0;           //则说明数str1比数str2“小”
    while(++m%k || m%l);               //使两数分别首尾相接，直至均回到开头为止
    return 0;                       //如果跳出了循环，则说明两数“相等”
}
