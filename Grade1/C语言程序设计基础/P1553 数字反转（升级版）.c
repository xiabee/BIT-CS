#include<stdio.h>
#include<string.h>
int main()
{
	int chang,d,i,e=0,j;
	char size[600];
	gets(size);
	chang=d=strlen(size);
	for(i=0;i<chang;i++)
	    if(size[i]=='/'||size[i]=='.'||size[i]=='%')
	        d=i;//这个相信大家都懂，这只是看他的方位 
	for(i=d-1;i>=0;i--)
	{
	    if(e==0&&size[i]=='0') continue;
	    e+=1; 
	    printf("%c",size[i]);
	}//这个就是简单的把符号前的反转 
	    if(e==0&&i==-1) 
		{
			printf("0");
		}
	    e=0;
	    printf("%c",size[d]);// 如果前面没有数字就输出0 
	if(d!=chang-1||d!=chang)
	{
	//因为这个题目就'/'有点坑，分母前面不能有0 
	    if(size[d]=='/')
		{
	        for(i=chang-1;i>d;i--)
			{
	            if(e==0&&size[i]=='0') continue;
	            break; 
	        }
	        for(j=i;j>d;j--)
	        printf("%c",size[j]);
	    return 0;
	    }
		else
		{
	    for(i=d+1;i<chang;i++)
		{
	        if(e==0&&size[i]=='0'){size[i]=' ';continue;}
	        e+=1;
	    }
	    for(i=d+1;i<=chang;i++)
		{
	        if(size[i]=='0') continue;
	        if(i==chang&&size[chang-1]==' ') size[chang-1]='0';
	    }
	
	//剩下的就是整理然后输出，只不过我这里有点取巧，把'0'换成了' 
	    for(i=chang-1;i>d;i--)
	        printf("%c",size[i]);
	    return 0;}
	}
}
