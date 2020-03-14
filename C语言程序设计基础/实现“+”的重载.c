#include<stdio.h>
#include<string.h>
#include<math.h>
#define N 10000
int main(int argc,char *argv)
{
	char a[2][N]={0};
	int c[N]={0};
	int k1=0,k2=0,flag=0,i;
	while((a[1][k1]=getchar())!='+')
	{
		if(a[1][k1]<'0'||a[1][k1]>'9')
		flag=1;							//flag=1表示输入为字符串 
		k1++;
	}
	scanf("+");
	while((a[2][k2]=getchar())!='\n')
	{
		if(a[2][k2]<'0'||a[2][k2]>'9') 
		flag=1;							//flag=1表示输入为字符串 
		k2++;
	}
	if(flag==1)							//如果是字符串，直接输出
	{
	for(i=0;i<k1;i++) 
		printf("%c",a[1][i]);
	for(i=0;i<k2;i++) 
		printf("%c",a[2][i]);
	printf("\n");
	}
	else								
	{
		int p=0,q=0,sum=0;
		sscanf(a[1],"%d",&q);
		sscanf(a[2],"%d",&p);
		sum=p+q;
	printf("%d\n",sum);	
	}
	return 0;
}
	 
