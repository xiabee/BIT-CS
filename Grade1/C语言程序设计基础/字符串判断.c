#include<stdio.h>
#include<string.h>
#define M 100
#define N 20

char *find(char *p,int n)//找到最后一串； 
{
	char *q=p;
	while(*(q+1))
		q++;
	q-=n-1;
	return q;
}
int main()
{
	char a[M]={0},b[N]={0},*p;
	gets(a);
	gets(b);
	p=find(a,strlen(b));
	if(strcmp(b,p)==0)
		printf("yes\n");
	else
		printf("no\n");
	return 0;
}
