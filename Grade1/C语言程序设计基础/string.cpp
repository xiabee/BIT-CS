#include<string.h>
#include<stdio.h>
/*int strlen(char str[]); 
	//返回str的长度
char[] strcat(char str1[],char str2[]); 
	//将str2接到str1后，返回str1 
char[] strncat(char str1[],char str2[],unsigned int maxsize); 
	//将str2中最多maxsize个字符接到str2后，返回str1 
char[] strcpy(char str1[],char str2[]);
	//将str2覆盖掉str1，返回str1 
int strcmp(char str1[],char str2[]);
	/*比较str1与str2
	  当str1<str2,返回负数
	  当str1=str2,返回0
	  当str1>str2,返回正数*/ 
int main() {
	char s1[100]="nicetocyou",s2[100]="c100goodluck";
	printf("%d\n",strlen(s1));
	printf("%s\n",strcat(s1,s2));
	printf("%s\n",strncat(s1,s2,4));
	printf("%s\n",strcpy(s1,s2));
	printf("%d %d\n",strcmp(s1,s2),strcmp(s1,s1));
}

