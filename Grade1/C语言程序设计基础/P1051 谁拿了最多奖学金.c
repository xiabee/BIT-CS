#include<stdio.h>
struct stu
{
	char name[51];
	int scr,tal,doc,mon;
	char den,wes;
}a[101];//定义结构体 
int main(void)
{
	int i=0,n=0,s=0,max=0,maxid=0;
	scanf("%d",&n);
	for(i=0;i<n;i++)
		a[i].mon=0;//奖学金归零；
	for(i=0;i<n;i++)
		scanf("%s %d %d %c %c %d",&a[i].name,&a[i].scr,&a[i].tal,&a[i].den,&a[i].wes,&a[i].doc);
	for(i=0;i<n;i++)//计算奖学金；
	{
		if ((a[i].scr>80)&&(a[i].doc>=1)) 
			a[i].mon=a[i].mon+8000;
	    if ((a[i].scr>85)&&(a[i].tal>80)) 
			a[i].mon=a[i].mon+4000;
	    if (a[i].scr>90) 
			a[i].mon=a[i].mon+2000;
	    if ((a[i].scr>85)&&(a[i].wes=='Y')) 
			a[i].mon=a[i].mon+1000;
	    if ((a[i].tal>80)&&(a[i].den=='Y')) 
			a[i].mon=a[i].mon+850;
	}
	for(i=0;i<n;i++)
	{
		if(a[i].mon>max)
		{
			max=a[i].mon;
			maxid=i;
		}
		s+=a[i].mon;
	}
	printf("%s\n",a[maxid].name);//输出
  	printf("%d\n",a[maxid].mon);
  	printf("%d\n",s);
  	return 0;
 } 
