#include<stdio.h>
struct stu
{	
	double sum;//sum用于记录加权后的成绩，
	int Chi,math,Eng,id,sum1;//sum1用于记录未加权成绩； 
}a[301];
int main(void)
{
	struct stu temp;
	int n,i,j;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d%d%d",&a[i].Chi,&a[i].math,&a[i].Eng);
		a[i].id=i+1;//编号； 
	}
	for(i=0;i<n;i++)
	{
		a[i].sum=a[i].Chi+a[i].Eng+a[i].math+(double)a[i].Chi/100;//直接给语文加权；
		a[i].sum1=a[i].Chi+a[i].Eng+a[i].math;
	}
	for(i=0;i<n;i++)//排序 
		for(j=0;j<i;j++)
			if(a[i].sum>a[j].sum)//相等时直接是小号在前； 
			{
				temp=a[i];
				a[i]=a[j];
				a[j]=temp;
			}
	for(i=0;i<5;i++)
		printf("%d %d\n",a[i].id,a[i].sum1);
	return 0;
}
