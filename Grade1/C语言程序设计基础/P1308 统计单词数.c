#include <stdio.h>
#include <string.h>
int main() 
{
    char a[11], b[1000001];
    gets(a);
    gets(b);
    strcat(a," "); 
    strcat(b," ");//在ab后各加一个" "，减小配对的难度 
    int i, s, n=0, l, j, ss=0, k, rec;
    for (i = 0; a[i] != '\0'; i++) 
	{
        if (a[i] >= 'a')
            a[i] -= 'a' - 'A';
    }
    for (i = 0; b[i] != '\0'; i++) 
	{
        if (b[i] >= 'a')
            b[i] -= 'a' - 'A';
    } //统一ab的大小写 
    for (i = 0; b[i] != '\0'; i++) 
	{
        if (b[i] == ' ') 
		{
            s=1;
            for (j = n,k = 0; j <= i, a[k] != '\0'; j++, k++) 
			{
                if(b[j] == a[k]) 
                    s*=1;//用s来记录各个位能否对应，如果结果是1就正确，一位不对s就变成0 
				else 
                     s*=0;
            }
            if (s == 1) 
                ss++; //如果每次都对就增加符合的次数 
            if (ss == 1 && s==1) 
                rec = n; //记录第一次符合的位数 
            n=i;
            n++;
        }
    }
    if (ss == 0) 
	{
        ss = -1;
        printf("%d", ss);
    } else if (ss >= 1) 
        printf("%d %d", ss, rec);
    return 0;
}
