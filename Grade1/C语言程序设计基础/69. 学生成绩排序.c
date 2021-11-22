#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*大家参加了期末考试，成绩出来后老师要对 n 个学生进行成绩汇总和排序。
要求程序按成绩降序进行排序。
在排序过程中对于成绩相同的学生，要按照输入数据的顺序进行排列。
例如：有5名学生的成绩：
zhang1,90
zhang2,91
zhang3,99
zhang4,91
zhang5,98

则排序结果应该为：
zhang3,99
zhang5,98
zhang2,91
zhang4,91
zhang1,90

请注意例题中“zhang2”和“zhang4”的排列顺序。

输入：
    第一行为将要输入的学生数量n
    从第二行起后面连续 n 行数据，每行为一名学生的姓名
	（长度不超过20个字符，不包括空格），考试成绩（int）

输出：排序后的结果。每行为一名学生的姓名和成绩。*/

int main(int argc, char *argv[]) {
	static struct student{
		char name[30];
		int len,score;
	}m[100],t1;
	int n;
	register int i,j;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		for(j=0,getchar();;j++){
			scanf("%c",&m[i].name[j]);
			if(m[i].name[j]==44) break;
		}
		m[i].len=strlen(m[i].name);
		scanf("%d",&m[i].score);
	}
	for(i=1;i<n;i++){
		for(j=0;j<n-i;j++){
		    if(m[j].score<m[j+1].score){
		    	t1=m[j];
			    m[j]=m[j+1];
			    m[j+1]=t1;
	    	}
	    }
	}
	for(i=0;i<n;i++){
		for(j=0;m[i].name[j]!='\0';j++){
			printf("%c",m[i].name[j]);
		}
		printf("%d\n",m[i].score);
	}
	return 0;
}
