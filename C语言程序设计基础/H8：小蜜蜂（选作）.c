#include <stdio.h>
#include <stdlib.h>
#define N 30
//大数加法 
char *plus(char *s1, char *s2)  
{  
    char *s=(char*) malloc(sizeof(char*)*N);  
    int i=0;  
    int t=0;              //进位  
    for(;s1[i]!='\0'&&s2[i]!='\0';)  
    {  
        s[i]=(s1[i]-'0'+s2[i]-'0'+t)%10+'0';  
        t=(s1[i]-'0'+s2[i]-'0'+t)/10;  
        i++;  
    }  
    //x1>x2  
    for(;s1[i]!='\0';)  
    {  
        s[i]=(s1[i]-'0'+t)%10+'0';  
        t=(s1[i]-'0'+t)/10;  
        i++;  
    }  
    //x2>x1
    for(;s2[i]!='\0';)  
    {  
        s[i]=(s2[i]-'0'+t)%10+'0';  
        t=(s2[i]-'0'+t)/10;  
        i++;  
    }  
    //如果还有进位  
    if(t==1)  
    {  
        s[i++]='1';  
    }  
    s[i]='\0';  
    return s;
}  
  
//输出  
void print(char *s)  
{     
    //先找到\0的位置，然后逆序输出  
    int i=0;  
    for(;s[i]!='\0';i++);
    i--;
    for(;i>= 0;i--)
	{  
        printf("%d",s[i]-'0');  
    }
    printf("\n");
}

int main()  
{  
    int a = 1, b = 100;  
  
    scanf("%d %d", &a, &b);  
    getchar();  
      
    int count=b-a;  
    int i;  
    
    char *s1=(char*)malloc(sizeof(char) *N);  
    char *s2=(char*)malloc(sizeof(char) *N);  
    char *s=(char*)malloc(sizeof(char) *N);  
  
    //初始化
    for (i=0;i<N;i++) 
	{  
        s1[i]='\0';  
        s2[i]='\0';  
        s[i]='\0';  
    }
  
    //给x1和x2赋初值  
    s1[0]='0'; 
    s2[0]='1';
  
    //斐波那契数列，叠加  
    for(i=1;i<=count;i++)  
	{
        s=plus(s1,s2);  
        s1=s2;  
        s2=s;  
    }  
    
    print(s);  
    return 0;   
}  

