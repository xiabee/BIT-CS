#include<stdio.h>
#include<stdlib.h>
struct ade
{
	int no;
	int am;
	int bm;
	int cm;
};//定义ade 
struct ade N[3]=
{{1,90,80,70},{2,85,75,95},{3,88,84,65}};//定义结构； 
int main()
{
	char s[300];
	int i=0,k,m;
	for(i=0;i<3;i++)//输入，验证输入为数字还是"max"; 
	{
		scanf("%c",&s[i]);
		if(s[i]=='\n')
			break;
	}
	if(s[0]=='m')//如果输入为"max"; 
		printf("2");
	else if(s[0]=='1'||s[0]=='2'||s[0]=='3')
	{
		
		k=N[(int)(s[0]-'1')].am+N[(int)(s[0]-'1')].bm+N[(int)(s[0]-'1')].cm;//求和； 
		m=k/3;
		printf("%d",m);
	}
	else
		printf("0");
	return 0;
}
