#include <math.h>
#include <stdio.h>
#define score printf("%d:%d\n",win,lost)    //score为输出比分的格式
char progress[75000];                        //乒乓球的比赛记录被保存在数组progress中
int main()
{
    void results();
    scanf("%[^E]",progress);                //输入E时表示比赛记录到此结束
    results();                                //调用函数results，输出11分制下的比赛结果
    printf("\n");                            //空一行
    results();                                //调用函数results，输出21分制下的比赛结果
    return 0;
}
void results()                                //函数results用于计算并输出比赛结果
{
    static short point=1;                    //比赛分制为point
    auto int b,win,lost;                    //华华的得分为win，对手的得分为lost
    point+=10;                                //首次调用该函数时为11分制，再次调用时为21分制
    for(win=lost=b=0;progress[b];b++)
    {
        switch(progress[b])
        {
            case 'W' : win++;  break;        //输入W时代表该球华华得分
            case 'L' : lost++;                //输入L时代表该球对手得分
        }
        if(win>=point || lost>=point)        //当华华或对手的得分达到比赛分制
            if(abs(win-lost)>=2)            //且双方的分差不小于2分时
            {
                score;                        //该局比赛结束，输出这一局比赛的结果
                win=lost=0;                    //比赛进入下一局，比分清零
            }
    }
    score;                                    //输出当前这一局的比分
    return;
}
