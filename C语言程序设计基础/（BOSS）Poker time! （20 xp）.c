#include<stdio.h>
#include<string.h>
char trans(char s[3][3],char t[3][3])//定义四种花色的大小 
{
	int i;
	for(i=0;i<3;i++)
	{
		if(s[i][0]=='H')
			s[i][0]=4;
		else if(s[i][0]=='S')
			s[i][0]=3;
		else if(s[i][0]=='D')
			s[i][0]=2;
		else if(s[i][0]=='C')
			s[i][0]=1;
		else
			return 'e';
		if(t[i][0]=='H')
			t[i][0]=4;
		else if(t[i][0]=='S')
			t[i][0]=3;
		else if(t[i][0]=='D')
			t[i][0]=2;
		else if(t[i][0]=='C')
			t[i][0]=1;
		else
			return 'e';
		if(s[i][1]=='J')
			s[i][1]=11;
		else if(s[i][1]=='Q')
			s[i][1]=12;
		else if(s[i][1]=='K')
			s[i][1]=13;
		else if(s[i][1]=='A')
			s[i][1]=14;
		else if(s[i][1]=='1'&&s[i][2]=='0')
			s[i][1]=10;
		else if(s[i][1]<49||s[i][1]>57)
			return 'e';
		
		if(t[i][1]=='J')
			t[i][1]=11;
		else if(t[i][1]=='Q')
			t[i][1]=12;
		else if(t[i][1]=='K')
			t[i][1]=13;
		else if(t[i][1]=='A')
			t[i][1]=14;
		else if(t[i][1]=='1'&&t[i][2]=='0')
			t[i][1]=10;
		else if(t[i][1]<49||t[i][1]>57)
			return 'e';
	}
	return 0;
}
void exc(char s[3],char t[3])
{
	char a[3];
	strcpy(a,s);
	strcpy(s,t);
	strcpy(t,a);
}
char queue(char s[3][3],char t[3][3])
{
	if(strcmp(s[0],s[1])<0)
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
	return 0;
}
int cmp(char s[3][3],char t[3][3])
{
	int i;
	for(i=0;i<3;i++)
	{
		if(strcmp(s[i],t[i])==0)
			continue;
		else
			return strcmp(s[i],t[i]);
	}
	return 0;
}
void transR(char s[3][3],char t[3][3])
{
	int i;
	for(i=0;i<3;i++)
	{
		if(s[i][0]==4)
			s[i][0]='H';
		if(s[i][0]==3)
			s[i][0]='S';
		if(s[i][0]==2)
			s[i][0]='D';
		if(s[i][0]==1)
			s[i][0]='C';
		if(t[i][0]==4)
			t[i][0]='H';
		if(t[i][0]==3)
			t[i][0]='S';
		if(t[i][0]==2)
			t[i][0]='D';
		if(t[i][0]==1)
			t[i][0]='C';
		if(s[i][1]==11)
			s[i][1]='J';
		if(s[i][1]==12)
			s[i][1]='Q';
		if(s[i][1]==13)
			s[i][1]='K';
		if(s[i][1]==14)
			s[i][1]='A';
		if(t[i][1]==11)
			t[i][1]='J';
		if(t[i][1]==12)
			t[i][1]='Q';
		if(t[i][1]==13)
			t[i][1]='K';
		if(t[i][1]==14)
			t[i][1]='A';
		if(s[i][1]==10)
			s[i][1]='1';
		if(t[i][1]==10)
			t[i][1]='1';
	}
}
int main()
{
	char a[3][3],b[3][3],win=0;
	int c;
	scanf("%s%s%s%s%s%s",&a[0],&a[1],&a[2],&b[0],&b[1],&b[2]);
	win=trans(a,b);
	if(win==0)
	{
		win=queue(a,b);
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
		else printf("Input Error!\n");
	}
	else printf("Input Error!\n");
}
