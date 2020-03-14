#include<iostream>
#include<cstring>
using namespace std;
char name[10][20];
int money[10];
int n;
int getNameNum(char *s)
{
    int i;
    for(i=0;i<n;i++)
        if(!strcmp(name[i],s)) return i;
    return -1; //cannot find the name
}
int main()
{
    scanf("%d\n",&n);
    int i,j;
    for(i=0;i<n;i++)
    {
        gets(name[i]);
        money[i]=0;
    }
    int childNum,o_money;
    char tmp[20],giver[20];
    for(i=0;i<n;i++)
    {
        gets(giver);
        scanf("%d%d\n",&o_money,&childNum);
  	    money[getNameNum(giver)]-=o_money;
        if(childNum==0)
        {
            continue;
            money[getNameNum(giver)]+=o_money;
        }
        money[getNameNum(giver)]+=o_money%childNum;
        for(j=0;j<childNum;j++)
        {
            gets(tmp);
            money[getNameNum(tmp)]+=o_money/childNum;
        }
    }
    for(i=0;i<n;i++)
        printf("%s %d\n",name[i],money[i]);
    return 0;
}

