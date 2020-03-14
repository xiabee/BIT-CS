#include <stdio.h>
#include <string.h>
 
int main(void)
{
    char buf[2000], tmp[10], str[50];
    char *p1 = buf, *p2;
    int i = 0;
 
    gets(buf);                          // 获取键盘输入
     
    while ((p2 = strchr(p1, ' '))) {    // 循环查找空格
        memset(tmp, 0, sizeof(tmp));    // tmp临时数组清0
        strncpy(tmp, p1, p2 - p1);      // 截取一个数字到临时数组tmp中
        str[i++] = strtol(tmp, NULL, 10);   // 字符转化为数字,并存到str中
        p1 = p2 + 1;                        // 指针指向下一组数字
    }   
 
    str[i++] = strtol(p1, NULL, 10);        // 最后一个数字找不到空格
    str[i] = 0;                             // 结束处置0
 
    printf("str = %s\n", str);              // 打印得到的字符吕
 
    return 0;
}
