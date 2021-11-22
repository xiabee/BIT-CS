#include<stdio.h>
int main()
{
   int n;
    while(scanf("%d",&n)!=-1)
    {
        if(n==1)
            printf("2\n");
        else
        {
        int dizhi=2;
        int sum=1;
        while(dizhi!=1)
        {
           if(dizhi<=n)
           {
               dizhi=dizhi*2;
           }
           else
           {
               dizhi=(dizhi-n)*2-1;
           }
           sum++;
        }
        printf("%d\n",sum);
        }
    }
}
