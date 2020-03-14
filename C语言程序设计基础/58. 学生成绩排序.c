#include<stdio.h>
#include<string.h>
static struct student
{
	char name[30];
	int len,score;
}m[100],t1;

int main()
{
	int i,j,n;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		for(j=0,getchar();;j++)
		{
			scanf("%c",&m[i].name[j]);
			if(m[i].name[j]==44)
				break;
		}
		m[i].len=strlen(m[i].name);
		scanf("%d",&m[i].score);
	}
	for(i=1;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			if(m[j].score<m[j+1].score)
			{
				t1=m[j];
				m[j]=m[j+1];
				m[j+1]=t1;
			}
		}
	}
	for(i=0;i<n;i++)
	{
		for(j=0;m[i].name[j]!='\0';j++)
			printf("%c",m[i].name[j]);
		printf("%d\n",m[i].score);
	}
	return 0;
 } 
