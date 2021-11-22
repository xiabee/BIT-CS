# include <stdio.h>
# define gap ('A'-1)            //字母A—Z分别代表数字1—26
int main()
{
    char comet[7],team[7],*p;
    int num_c=1,num_t=1;
    scanf("%[A-Z]\n%[A-Z]",&comet,&team);
    for(p=comet;*p;p++)
        num_c*=*p-gap;            //彗星数num_c为彗星名中各字母所代表的数字之积
    for(p=team;*p;p++)
        num_t*=*p-gap;            //小组数num_t为小组名中各字母所代表的数字之积
    if(num_c%47==num_t%47)        //若彗星数除以47的余数与小组数除以47的余数相等
        puts("GO");                //则输出“GO”，表示此小组会被该彗星带走
    else
        puts("STAY");            //否则输出“STAY”，表示此小组不会被该彗星带走
    return 0;
}
