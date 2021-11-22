/*下面给出的程序的功能是将输入的字符串反向，
例如输入字符串“abcdefg”，输出"gfedcba"。

主函数中读入一个字符串，然后调用reverse函数将字符串反向，
最后输出反向后的字符串。

函数原型：reverse（char *str, int i, int j )，其中s为字符串的首地址，
i、j是以字符串中心对称的两个字符的下标，i在前、j在后。
reverse函数采用了递归算法。

程序中存在着错误，请改错后提交。

#include <stdio.h>
void reverse( char *str, int i, int j )
{   
    char temp;
    if( i < j )
    {
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;
        reverse( str, i+1, j-1 );
    }
    return;
}
int main()
{  
    int n=0;
    char s[100];
    gets(s);
    while( s[n] != '\0' )
        n++;
    reverse( s, 0, n ); 
    puts(s);
    return 0;
}*/
#include <stdio.h>
void reverse(char *str,int i,int j)
{   
    char temp;
    if( i < j )
    {
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;
        reverse( str, i+1, j-1 );
    }
    return;
}
int main()
{  
    int n=0;
    char s[100];
    gets(s);
    while( s[n] != '\0' )
        n++;
    reverse( s, 0, n-1 ); 
    puts(s);
    return 0;
}
