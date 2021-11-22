/*计算给定字符串的无重复字符的最长子串*/
#include<stdio.h>
#include<string.h>
#include <time.h>
#include <ctype.h>
#define N 100
char del(char c);
int main(int argc, char *argv[])
{
	
	char a[N]={0},b[N]={0};
	int i,j,k=0,p,n,m,t=0;
	gets(a);
	n=strlen(a);
	A:for(i=t;i<n;i++)
	{	
		for(j=t,p=0;j<n;j++)
		{
			if(b[j]==a[i])
				p=1;
		}
		if(p==0)
		{
			b[k]=a[i];
			k++;
		}
	}						//求出无重复的第一个子串； 
	for(i=0;i<n;i++)
	{
		a[i]=b[i];
	}		
	m=strlen(a);
	puts(a);
	t++;
		if(t!=n)
			goto A;	
		return 0;   
 } 
