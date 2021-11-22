# include "stdio.h"
# define M 10000                                    //M为地毯数上限
# define cover_x x>=a[o] && x<=a[o]+g[o]            //cover_x为x方向上的覆盖条件
# define cover_y y>=b[o] && y<=b[o]+k[o]            //cover_y为y方向上的覆盖条件
short main()
{
    int n,o,a[M],b[M],g[M],k[M],x,y,top=-2;            //当所求点无地毯覆盖时输出-1
    scanf("%d",&n);                                    //编号为1—n的n张矩形地毯依次铺设
    for(o=0;o<n;o++)
        scanf("%d%d%d%d",&a[o],&b[o],&g[o],&k[o]);    //每张地毯左下角的坐标为(a,b)，其长度和宽度分别为g和k
    scanf("%i%i",&x,&y);                            //所求点的坐标为(x,y)
    for(o=0;o<n;o++)
        if(cover_x && cover_y)                        //如果某地毯覆盖所求点
            top=o;                                    //就将该地毯的“编号”(比实际编号少1)赋给top
    printf("%d\n",top+1);                            //输出覆盖所求点最上面那张地毯的编号
    return 0;
}
