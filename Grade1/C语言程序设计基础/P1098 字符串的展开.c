# include <stdio.h>
# define upper(ch) ch>='a' && ch<='z'?ch-'a'+'A':ch                     
signed main()
{
    char abbr[101],*c;
    short p1,p2,p3,L,l,R;
    scanf("%hd %hd %hd",&p1,&p2,&p3);                                 
    scanf("%s",abbr);                                                 
    putchar(*(c=abbr));                                                 
    while(*++c)                                                         
        if(*c!='-' || (L=*(c+1)-*(c-1))<=0 || *(c-1)=='-' || L>25)     
            putchar(*c);                                             
        else                                                         
            for(l=p3==1?1:L-1;l && l<L;l-=p3*2-3)                     
                for(R=p2;R;--R)                                         
                    switch(p1)                                         
                    {                                                 
                        case 1: putchar(*(c-1)+l); break;             
                        case 2: putchar(upper(*(c-1)+l)); break;     
                        case 3: putchar('*');                         
                    }
    return !printf("\n");
}
