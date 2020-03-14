#include<stdio.h>
int a[100000],top;
void change(int b,int c) //交换
{
	int t;
	t=a[b];
	a[b]=a[c];
	a[c]=t;
}
void putt(int son)
{
	if(son!=1&&a[son]<a[son/2]) //自下而上排序
	{
		change(son,son/2);
		putt(son/2);
	}
}

void gett(int father)
{
	int son,t; //自上而下排序
	if(father*2+1<=top)
	{
		if(a[father*2]<a[father*2+1]) 
			son=father*2;
		else 
			son=father*2+1;
		if(a[father]>a[son])
		{
			change(father,son);
			gett(son);
		}
	}
}

int main()
{
	int i,n;
	long long sum=0;
	scanf("%d",&top);
	for(i=1;i<=top;i++)
	{
		scanf("%d",&a[i]);
		putt(i);
	}
	n=top;
	for(i=1;i<=n;i++) //合并
	{
		if(a[2]<a[3]||a[3]==0)
		{
			a[1]=a[2]+a[1];
			a[2]=a[top];
			gett(2);
		}
		else
		{
			a[1]=a[3]+a[1];
			a[3]=a[top];
			gett(3);
		}
		sum=sum+a[1];
		a[top]=0; //删除元素
		top--;
		gett(1);
	}
	printf("%d",sum-a[2]); //输出，删除之前多加的a[1],因为a[2]=a[1],所以减去a[2]
	return 0;
}
