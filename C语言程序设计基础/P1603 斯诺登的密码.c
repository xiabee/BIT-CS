# include <stdio.h>
# include <string.h>
struct
{
    char *number;                                        //number为数字所对应的英文单词
    short mod;                                            //mod为该数字的平方对100求余后的结果
}
chart[19]={"a",1,"one",1,"two",4,"three",9,"four",16,"eleven",21,"eighteen",24,"fifteen",25,"five",25,
            "six",36,"twelve",44,"seven",49,"sixteen",56,"nineteen",61,"eight",64,"thirteen",69,
            "nine",81,"seventeen",89,"fourteen",96};    //定义各数字与其平方求余结果的对应表chart
int main()
{
    char word[6][28],s,m=-1,t=0;                        //输入含有6个英文单词的句子
    for(s=0;s-6;scanf("%s ",word[s++]));                //将其拆分为单词后保存在数组word中
    for(;++m<19;)                                        //按顺序逐个检验对应表chart中的英文单词
        for(s=6;s>=0;s--)                                //判断其是否在句子中出现
            if(!strcmp(chart[m].number,word[s]))        //如果句子中出现了该单词(数字)
                t=printf(t?"%02d":"%d",chart[m].mod);    //则输出其平方求余后的结果，保证组合数最小
    return !puts(t?"":"0");                                //若对应表中的单词均未出现，则无法组合，输出0
}
