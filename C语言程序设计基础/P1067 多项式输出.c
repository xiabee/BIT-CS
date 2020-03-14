#include <stdio.h>
int main(void)
{
    int n, ratio, i, counter = 0;    // counter 是已经输出的项数
    scanf("%i", &n);
    for (i = n; i > 0; i--)
    {
        scanf("%i", &ratio);
        if (ratio == 0)    // 系数为 0 continue
            continue;
        else if (i == 1)        // 次数为 1
            if (ratio == 1)            // 系数为 1
                if (counter == 0)        // 第一项
                    printf("x");
                else
                    printf("+x");
            else if (ratio == -1)    // 系数为 -1
                printf("-x");
            else                    // 其他系数
                if (counter == 0)        // 第一项
                    printf("%ix", ratio);
                else
                    printf("%+ix", ratio);
        else if (ratio == 1)    // 次数不为 1, 系数为 1
            if (counter == 0)        // 第一项
                printf("x^%i", i);
            else
                printf("+x^%i", i);
        else if (ratio == -1)    // 次数不为 1, 系数为 -1
            printf("-x^%i", i);
        else                    // 次数不为 1, 系数不为 1 或 -1
            if (counter == 0)        // 第一项
                printf("%ix^%i", ratio, i);
            else                    // !!! 注意这里!!! 看 printf() 如何用控制字符强制输出符号!!!
                printf("%+ix^%i", ratio, i);
        counter++;
    }
    scanf("%i", &ratio);    // 对常数项的判断
    if (ratio == 0)            // 常数为 0
        if (counter == 0)        // 第一项
            printf("0\n");
        else
            printf("\n");
    else if (counter == 0)    // 第一项不输出符号
        printf("%i\n", ratio);
    else                    // 否则强制输出符号
        printf("%+i\n", ratio);
    return 0;
}
