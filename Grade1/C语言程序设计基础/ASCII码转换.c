#include<stdio.h>
#include<ctype.h>
#define YES 1
#define NO 0
int htoi(char s[])
{
    int hexdigit, i, inhex, n;
    i = 0;
    if (s[i] == '0')
    {
        ++i;
        if (s[i] == 'x' || s[i] == 'X')
            ++i;
    }
    n = 0;
    inhex = YES;
    for ( ; inhex == YES; ++i)
    {
        if (s[i] >= '0' && s[i] <= '9')
            hexdigit = s[i] - '0';
        else if (tolower(s[i]) >= 'a' && tolower(s[i]) <= 'z')
            hexdigit = s[i] - 'a' + 10;
        else
        	inhex = NO;
        if (inhex == YES)
            n = 16 * n + hexdigit;
    }
    return n;
}

int main()
{
    printf("请输入16进制ASCII码：\n");
	printf("输入“exit”退出\n");
	while(1)
	{
		int n;
		char ascii;
		char s[100];
		scanf("%s", s);
		n=htoi(s);
		printf("The char of %3d is:%c\n",n,(char)n);
		if(s[0]=='e'&&s[1]=='x'&&s[2]=='i'&&s[3]=='t')
			break;
	}
	//printf("char is %s\n", s);
    //printf("integer is %d\n", htoi(s));
    return 0;
}
