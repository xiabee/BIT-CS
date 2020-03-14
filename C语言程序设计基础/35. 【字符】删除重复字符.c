#include<stdio.h>
#include<string.h>
#define N 100
int main(int argc, char *argv[])
{
	static char a[N],b[N];
	int i,j,k=0,p;
	gets(a);
	for(i=0;i<N;i++)
	{
		for(j=0,p=0;j<N;j++)
		{
			if(b[j]==a[i])
				p=1;
		}
		if(p==0)
		{
			b[k]=a[i];
			k++;
		}
	}
	puts(b);
	return 0;   
 } 
