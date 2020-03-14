# include <stdio.h>
# define min(b,d) b<d?b:d
# define max(f,g) f>g?f:g
# define Reduce (volume[z]-volume[z+4])/(price[z+4]-price[z])
# define profit(p) (price[p]+subsidy-price[0])*volume[p]            //商品利润=(售价+补贴(-税金)-成本)*销售量
# define maximum for(z=0;profit(z+1)>=profit(z);++z)                //商品在以某价位出售时可以获得最大利润
int main()
{
    int expect,price[23],volume[23]={0},z=0,reduce,subsidy=0;        //政府通过对某商品给予补贴或收取税金的方式
    scanf("%i",&expect);                                            //使其在政府预期价expect(元)上获得最大利润
    do                                                                //该商品的成本为price[0](元)
        scanf("%i %i",price+z,volume+z);                            //以price(元)的单价出售时的销售量为volume
    while(price[z++]>=0);                                            //输入负数时代表所有的价位和销量均输入完毕
    scanf("%i",&reduce);                                            //售价比最高价位每高1元，销量将减少reduce
    if(expect>=price[z-2])                                            //如果预期价不小于最高价位
        for(z-=2;volume[z++]>=0;volume[z]=volume[z-1]-reduce)        //就继续计算对应的单价和销量，直到销量为负
            price[z]=price[z-1]+1;                                    //即每当price增加1，volume便会减少reduce
    else                                                            //如果预期价比最高价位要小
    {                                                                //就在已知售价中找到预期价或其所在的区间
        for(z--;price[--z]>expect;volume[z+3]=volume[z])            //将大于预期价的所有售价及所对应的销量后移
            price[z+3]=price[z];                                    //空出的位置用于补充预期价附近的价位和销量
        if(price[z-1]!=expect-1 || price[z+1]!=expect+1)            //当预期价附近的价位未知时
        {
            price[z+1]=expect-1;                                    //补充比预期价低1元的价位
            price[z+2]=expect;                                        //补充与预期价相等的价位
            price[z+3]=expect+1;                                    //补充比预期价高1元的价位
            volume[z+1]=volume[z]-Reduce*(price[z+1]-price[z]);        //在已知的相邻价位间销售量的变化是线性的
            volume[z+2]=volume[z]-Reduce*(price[z+2]-price[z]);        //相邻价位间售价每高1元，销量将减少Reduce
            volume[z+3]=volume[z]-Reduce*(price[z+3]-price[z]);        //即每当price增加1，volume便会减少Reduce
        }
        while(price[++z]-expect<2)                                    //当补充的数据与已知的数据发生矛盾时
        {                                                            //则以已知的数据为准，对补充的数据进行修正
            price[z]=max(price[z-1],price[z]);                        //使数组price中的售价按由低到高的顺序排列
            volume[z]=min(volume[z-1],volume[z]);                    //使数组volume中的销量按由多到少的顺序排列
        }                                                            //从而确保后续的计算不会出现错误
    }
    maximum;                                                        //该商品获得最大利润时的售价为price[z](元)
    if(price[z]>expect)                                                //若此售价price[z]大于政府预期价expect
        while(price[z]>expect)                                        //则政府有必要对该商品给予补贴subsidy(元)
        {                                                            //从而使price[z]不再大于expect
            subsidy++;                                                //subsidy为正数代表政府对该商品给予补贴
            maximum;                                                //计算给予补贴后该商品获得最大利润时的售价
        }                                                            //给予的补贴必须为整数，并且要尽可能少
    else                                                            //若此售价price[z]小于政府预期价expect
        while(price[z]<expect)                                        //则政府有必要对该商品收取税金subsidy(元)
        {                                                            //从而使price[z]不再小于expect
            subsidy--;                                                //subsidy为负数代表政府对该商品收取税金
            maximum;                                                //计算收取税金后该商品获得最大利润时的售价
        }                                                            //收取的税金必须为整数，并且要尽可能少
    if(price[z]==expect)                                            //若政府能够使该商品在预期价上获得最大利润
        return !printf("%d\n",subsidy);                                //则输出subsidy的值(保证其绝对值尽可能小)
    return !puts("NO SOLUTION");                                    //否则输出“NO SOLUTION”
}
