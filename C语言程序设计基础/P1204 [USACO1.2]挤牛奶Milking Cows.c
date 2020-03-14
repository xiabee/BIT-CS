#include<stdio.h>
#include<string.h>
struct time
{
	int start;
	int end;
}a[5000];
int main()
{
	int n,i,j;
	int maxon=0,maxoff=0;//挤牛奶时间于不挤牛奶时间； 
	int now,then;
	struct time temp;
	scanf("%d",&n);
	for(i=0;i<n;i++)
		scanf("%d %d",&a[i].start,&a[i].end);//读入；
	for(i=0;i<n;i++)
		for(j=0;j<i;j++)
			if(a[i].start<a[j].start)//开始时间从小到大排序； 
			{
				temp=a[i];
				a[i]=a[j];
				a[j]=temp;		
			} 
	for(i=0;i<n;i++)
	{
		now=a[i].start;
		then=a[i].end;
		
	}
	
 } 
