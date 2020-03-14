#include<stdio.h>
int huiwen(char* str)
{
	static int num=0;
	char *q=str;
	while(*q!='\0')
		q++;
	q--;
	if(q-str<0)
		return num;
	if(*str!=*q)
		return -1;
	else 
	{
		char temp=*q;
		*q='\0';
		int result=huiwen(str+1);
		*q=temp;
		if(result!=-1)
			return ++num;
		else
			return -1;
	}
}
int main()
{
	char chs[1000];
	scanf("%s",chs);
	printf("%d\n",huiwen(chs));
	return 0;
}
