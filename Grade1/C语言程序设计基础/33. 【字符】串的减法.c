#include<stdio.h>
#include<string.h>
#define N 80
int main(int argc, char *argv[])
{
	static char s[N],t[N],u[N];
	int i,j,k=0,p;
	gets(s);
	gets(t);
	for(i=0;i<N;i++)
	{
		for(j=0,p=0;j<N;j++)
		{
			if(s[i]==t[j])
				p=1;
		}
		if(p==0)
		{
			u[k]=s[i];
			k++;
		}
	}
	puts(u);
	return 0;   
 } 
