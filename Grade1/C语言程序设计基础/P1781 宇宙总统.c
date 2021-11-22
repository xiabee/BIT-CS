#include<stdio.h>
#include<string.h>
int main()
{
    char s[21][102],max[102];
    int len1,len2,n,maxn,i;
    scanf("%d",&n);
    scanf("%s",s[1]);
    maxn=1;
    len1=strlen(s[1]);
    strcpy(max,s[1]);
    for(i=2;i<=n;i++)
    {
        scanf("%s",s[i]);
        len2=strlen(s[i]);
        if(len1==len2)
        {
        if(strcmp(s[i-1],s[i])>0)
            continue;
        if(strcmp(s[i-1],s[i])<0&&i<n)
        {
            len1=strlen(s[i]);
            maxn=i;
            strcpy(max,s[i]);
        }
        }
        else
        if(len1>len2)
			continue;
        else
        {
            len1=strlen(s[i]);
            maxn=i;
            strcpy(max,s[i]);
        }
    }
    printf("%d\n%s",maxn,max);
    return 0;
}
