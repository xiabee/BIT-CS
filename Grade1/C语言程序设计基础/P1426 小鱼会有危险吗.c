#include <math.h>
#include <stdio.h> 
int main()
{
    double s,x,distance=0;                //小鱼从A处开始往前游，已游过的距离为distance(米)
    unsigned time=0,safe=2;                //已游过的时间为time(秒)
    scanf("%lf %lf",&s,&x);                //在A处前方s(米)的地方有一个探测器，能探测到前后x(米)的范围
    while(distance<=s+x && safe)
    {
        safe-=distance>=s-x;            //如果小鱼在连续的两秒过后均处于探测范围之内就会有危险
        distance+=7*pow(0.98,time++);    //小鱼第一秒能游7米，此后每一秒游的距离是前一秒的98%
    }
    return !puts(safe?"n":"y");            //如果小鱼有危险，则输出“y”，否则输出“n”
}
