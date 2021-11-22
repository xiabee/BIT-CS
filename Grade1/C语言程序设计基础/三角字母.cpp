#include<stdio.h>
char charAdd(char ch) 
{
	return ch = (ch+1-'A')%26+'A';
}
char charMinus(char ch) 
{
	return ch = (ch-1-'A'+26)%26+'A';
}
int main() 
{
	int i,j,n,ch;
	scanf("%d %c",&n,&ch);
	for(i=1;i<=n;++i) 
	{
		for(j=1;j<=n-i;++j)
			printf(" "); // n-i个左侧空格 
		if(i==1) { //第一行 
			printf("%c",ch); // 一个字母 
			ch=charAdd(ch); 
		}
		else if(i==n) //最后一行 
		{
			for(j=1;j<=n-1;++j) { //升序输出 
				printf("%c",ch);
				ch=charAdd(ch);
			}
			printf("%c",ch); // 中间的字母 
			ch=charMinus(ch); // 调整字母 
			for(j=n-1;j>=1;--j) { //降序输出 
				printf("%c",ch);
				ch=charMinus(ch);
			}
		}else //中间行 
		{
			printf("%c",ch); // 左边那个字母 
			for(j=1;j<=2*i-3;++j)
				printf(" "); // 2*i-3个空格 
			printf("%c",ch); // 右边那个字母 
			ch=charAdd(ch);
		}
		printf("\n");
	}
}


