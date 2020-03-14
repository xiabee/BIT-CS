#include<stdio.h>
#include<string.h>
char trans(char a[3][3],char b[3][3])//定义四种花色的大小 和 J Q K A  
{
	int i;
	for(i=0;i<3;i++)
	{
		switch(a[i][0])
		{
			case 'H':a[i][0]=4;break;
			case 'S':a[i][0]=3;break;
			case 'D':a[i][0]=2;break;
			case 'C':a[i][0]=1;break;
			default:return 'e';
		}
		switch(b[i][0])
		{
			case 'H':b[i][0]=4;break;
			case 'S':b[i][0]=3;break;
			case 'D':b[i][0]=2;break;
			case 'C':b[i][0]=1;break;
			default:return 'e';
		}
		switch(a[i][1])
		{
			case 'J':a[i][1]=11;break;
			case 'Q':a[i][1]=12;break;
			case 'K':a[i][1]=13;break;
			case 'A':a[i][1]=14;break;
		}
		switch(b[i][1])
		{
			case 'J':b[i][1]=11;break;
			case 'Q':b[i][1]=12;break;
			case 'K':b[i][1]=13;break;
			case 'A':b[i][1]=14;break;
		}
		if(a[i][1]=='1'&&a[i][2]=='0')
			a[i][1]=10;
		else if(a[i][1]<49||a[i][1]>57)
			return 'e';
		if(b[i][1]=='1'&&b[i][2]=='0')
			b[i][1]=10;
		else if(b[i][1]<49||b[i][1]>57)
			return 'e';
	}
 return 0;
 } 
int cmp(char s[3][3],char t[3][3])//比较大小 
{
	int i;
	for(i=0;i<3;i++)
	{
		if(strcmp(s[i][1],t[i][1])==0)
			continue;
		else
			return strcmp(s[i][1],t[i][1]);
	}
	return 0;
	} 
void exc(char s[3],char t[3])//备用函数，用于交换 
{
	char a[3];
	strcpy(a,s);
	strcpy(s,t);
	strcpy(t,a);
	}
char queue(char s[3][3],char t[3][3])
{
	/*if(strcmp(s[0],s[1])<0)
		exc(s[0],s[1]);
	else if(strcmp(s[0],s[1])==0)
		return 'e';
	if(strcmp(s[1],s[2])<0)
		exc(s[1],s[2]);
	else if(strcmp(s[1],s[2])==0)
		return 'e';
	if(strcmp(s[0],s[1])<0)
		exc(s[0],s[1]);
	if(strcmp(t[0],t[1])<0)
		exc(t[0],t[1]);
	else if(strcmp(t[0],t[1])==0)
		return 'e';
	if(strcmp(t[1],t[2])<0)
		exc(t[1],t[2]);
	else if(strcmp(t[1],t[2])==0)
		return 'e';
	if(strcmp(t[0],t[1])<0)
		exc(t[0],t[1]);
	return 0;*/ 
	int i,j;
	for(i=0;i<3;i++)
	{
		
		if(s[i][1]<s[i][j+1])
			exc(s[i][j],s[i][j+1]);
	 } 
	 for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		if(t[i][j]<t[i][j+1])
			exc(t[i][j],t[i][j+1]);
	}
	return 0; 
}
void transR(char s[3][3],char t[3][3])//换回四种花色； 
{
	int i;
	for(i=0;i<3;i++)
	{
		switch(s[i][0]) 
		{
			case 4:s[i][0]='H';break;
			case 3:s[i][0]='S';break;
			case 2:s[i][0]='D';break;
			case 1:s[i][0]='C';break;
		}
		switch(t[i][0]) 
		{
			case 4:t[i][0]='H';break;
			case 3:t[i][0]='S';break;
			case 2:t[i][0]='D';break;
			case 1:t[i][0]='C';break;
		}
		switch(s[i][1])
		{
			case 11:s[i][1]='J';break;
			case 12:s[i][1]='Q';break;
			case 13:s[i][1]='K';break;
			case 14:s[i][1]='A';break;
			case 10:s[i][1]='1';break;
		}
		switch(t[i][1])
		{
			case 11:t[i][1]='J';break;
			case 12:t[i][1]='Q';break;
			case 13:t[i][1]='K';break;
			case 14:t[i][1]='A';break;
			case 10:t[i][1]='1';break;
		}
	}
}
int main()
{
	char a[3][3],b[3][3],win=0;
	int c;
	scanf("%s%s%s%s%s%s",&a[0],&a[1],&a[2],&b[0],&b[1],&b[2]);
	win=trans(a,b);
	if(win==0)//检验输入是否合法； 
	{
		win=queue(a,b);//排序； 
		if(win==0)
		{
			c=cmp(a,b);
			transR(a,b);
			if(c>0)
				win='A';
			else if(c<0)
				win='B';
			else
				win='X';
			printf("Winner is %c!\nA: %s %s %s\nB: %s %s %s\n",win,a[0],a[1],a[2],b[0],b[1],b[2]);
		}
		else if(a==b)
			printf("Draw!\nA: %s %s %s\nB: %s %s %s\n",win,a[0],a[1],a[2],b[0],b[1],b[2]);
		else printf("Input Error!\n");
	}
	else printf("Input Error!\n");
}
 
