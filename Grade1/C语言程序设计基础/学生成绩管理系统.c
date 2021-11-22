/*学生成绩管理系统 */
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#define MAX 1000    /*Total number of students*/
#define NUM 5		/*Number of subjects*/

void ui_student();
void ui_teacher();
void ui_counsellor();
void query_stu();

void grade_stu();		/*query grades for students*/
void ranking_stu();		/*query rankings for students*/
void Input_tea();		/*input the grades for teachers*/
void grade_tea();		/*query all grades for teachers*/
void ranking_tea();		/*query all rankings for teachers*/
void rank(int i);		/*to rank the subject*/

void Input_coun();		/*to input the information of students*/
void Dis_infor();		/*to display all the information of students*/

struct student
{
	char id[20];
	char name[20];
	int score[NUM]; 
	int ave;
} stu[MAX];
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
		ch=getchar();	/*getchar twice to refresh buffer*/
		switch(ch)
		{
			case '1':grade_stu();break;
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
		ch=getchar();	/*getchar twice to refresh buffer*/
		switch(ch)
		{
			case '1':Input_tea();break;
			case '2':grade_tea();break;
			case '3':ranking_tea();break;
			default :break;
		}
	}
	while(ch!='0');
}

void ui_counsellor()
{
	printf("\n\n\t*欢迎使用学生成绩管理系统辅导员版*\n\n");
	printf("请输入功能序号：\n");
	printf("1.录入学生信息\n");
	printf("2.显示学生信息\n");
	printf("3.查询学生成绩\n");
	printf("4.显示全部排名\n");
	printf("0.退出系统\n");
	while(1)
	{
		int k;
		scanf("%d",&k); 
		if(k==0)
			break;
		switch(k)
		{
			case 1:Input_coun();break;
			case 2:Dis_infor();break; 
			case 3:grade_stu();break;
			case 4:
			{
				int j;
				for(j=0;j<NUM;j++)
					ranking_tea(j);
				break;
			}
		} 
	}
}

void grade_stu()/*query grades for students*/
{
	int j,k;
	char temp[20];
	printf("请输入学号：\n");
	scanf("%s",&temp);
	printf("您的成绩为：\n\n");
	printf("科目序号\t成绩\n");
	for(j=0;j<MAX;j++) 
		if(strcmp(temp,stu[j].id)==0)					//to find the student;
			for(k=0;k<NUM;k++)							//print his/her all grades;
				printf("%d\t%d\n",k+1,stu[j].score[k]);	//k+1:The serial number defaults to start from 1.	
}

void ranking_stu()/*query rankings for students*/
{
	int j,k,ranking;
	for(k=0;k<NUM;k++)
		rank(k);		//to rank all;
	char temp[20];
	printf("请输入学号：\n");
	scanf("%s",&temp);
	printf("您的排名为：\n\n");
	printf("科目序号\t成绩\n");
	for(k=0;k<NUM;k++)
	{
		for(j=0;j<MAX;j++) 
			if(strcmp(temp,stu[j].id)==0)					//to find the student;
				ranking=j;
		printf("%d\t%d\n",k+1,ranking);						//print the rankings;
	}
}

void Input_tea(int i)/*input the grades for teachers*/
{
	int stu_id;
	printf("请输入学生学号和成绩：\n(按0结束输入)\n\n");
	while(1)
	{
		scanf("%d",&stu_id);
		if(!stu_id)
			break;
		scanf("%d",&stu[stu_id].score[i]);
	}	
}

void grade_tea(int i)/*query all grades for teachers*/
{
	//if(counter(i)==0)	//check whether empty
		//printf("\n请先输入学生成绩！\n\n");
	int t;
	for(t=0;t<1000;t++)
		if(stu[t].score[i])
			printf("%s\t%s\t%d\n",stu[t].id,stu[t].name,stu[t].score[i]);		
}

void ranking_tea(int i)/*query all rankings for teachers and print*/
{
	int t;
	rank(i);
	for(t=0;t<MAX;t++)
		printf("%d\t%s\t%s%d\n",t+1,stu[t].id,stu[t].name,stu[t].score[i]);
}


void rank(int i)	/*to rank the certain subject*/
{
	struct student temp;
	int j,k;
	for(j=0;j<MAX;j++)
		for(k=0;k<j;k++)
			if(stu[j].score[i]>stu[k].score[i])
			{
				temp=stu[j];
				stu[j]=stu[k];
				stu[k]=temp;
			}
}

void Input_coun()	/*to input the information of students*/
{
	int j;
	printf("请输入学生  学号 姓名：\n输入“0000”退出\n\n");
	for(j=0;;j++)
	{
		scanf("%s,%s",&stu[j].id,&stu[j].name);
		if(strcmp(stu[j].id,"0000")==0)
			break;
	}
}

void Dis_infor()	/*to display all the information of students*/
{
	int j;
	printf("学号\t姓名\n");
	for(j=0;j<MAX;j++)
		if(strcmp(stu[j].id,NULL)!=0)
			printf("%s\t%s\n",stu[j].id,stu[j].name);
}
