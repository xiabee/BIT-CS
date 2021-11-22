#include<stdio.h>
#include <string.h>
int oo(char x)//字母判断函数 
{
	if(x<='z'&&x>='a'||x<='Z'&&x>='A')return 1;
	else return 0;
}
int main()
{
	char a[100],b[5000][80];//a文本每一行，b压缩字符储存数列 
	int N=1;
	while(gets(a))
	{
		int i,j;
		for(i=0;a[i]!='\0';i++)
		{
			char c[80];//c字符暂存数列 
			for(j=0;j<80;j++)c[j]='\0';
				j=0;
			if(oo(a[i]))
			{
				while(oo(a[i]))
				{
					c[j]=a[i];
					i++;
					j++;
				}
				i--;
				int g=1;
				for(j=1;j<5000;j++)//查找单词是否在b中 
				{
					if(strcmp(c,b[j])==0)
					{
						printf("%d",j);
						g=0;
						break;
					}
				}//是则输出数字
				if(g)
				{
					printf("%s",c);
					strcpy(b[N],c);
					N++;
				}//否则输出单词，并存储至b 
			}
			else printf("%c",a[i]);
		}
		printf("\n");
	}
	return 0;
}
