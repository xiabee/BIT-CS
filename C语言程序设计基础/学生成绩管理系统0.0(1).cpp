/*学生成绩管理系统 */
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

void ui_student();
void ui_teacher();
void ui_counsellor();
void query_stu();
struct student
{
	char id[20];
	char name[20];
	int score[5]; 
	int ave;
} stu[1000];
char ch,id_1[20];//id_1  学生自己输入的学号 
int i;//老师科目编号 
int main() 
{
	char password[20];
	printf("\t*欢迎使用学生成绩管理系统*\n\n");
	while(1)
	{
		printf("请输入您的密码:");
		gets(password);
		if(strcmp(password,"123456")==0)
		{
			ui_student();
			break;
		}
		else if(strcmp(password,"666666")==0)
		{
			ui_teacher();
			break;
		}
		else if(strcmp(password,"000000")==0)
		{
			ui_counsellor();
			break;
		}
		else
		printf("密码错误，请重新输入\n\n");
	}
}
void ui_student()		/*学生界面功能*/ 
{
	printf("\n\n\t*欢迎使用学生成绩管理系统学生版*\n\n");
	printf("请输入您的学号：");
	gets(id_1);
	printf("1.查询全部成绩\n");
	printf("2.查询排名\n");
	printf("0.退出系统\n");
	do
	{
		printf("请输入要使用的功能编号："); 
		ch=getchar();
		switch(ch)
		{
			case '1': grade_stu();break;
			case '2':ranking_stu();break;
		}
	}
	while(ch!='0');
}
void ui_teacher()
{
	printf("\n\n\t*欢迎使用学生成绩管理系统教师版*\n\n");
	printf("请输入您的科目编号：");
	scanf("%d",&i); 
	printf("1.录入学生成绩\n");
	printf("2.查询全部成绩\n");
	printf("3.查询排名\n");
	do
	{
		printf("请输入要使用的功能编号："); 
		ch=getchar();
		switch(ch)
		{
			case '1':;break;
			case '2':;break;
		}
	}
	while(ch!='0');
}
void ui_counsellor()
{
	printf("\n\n\t*欢迎使用学生成绩管理系统辅导员版*\n\n");
}


