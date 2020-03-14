#include<stdio.h>
#define N 10
void main()
{
	int sum = 0,i;
	double avg,b;
	int a[N];
	int max,min;
	for(i=0;i<10;i++)
	{
		scanf("%d",&a[i]);
		if(i==0)//只有第一次赋值max=min=a[0]
		{
			max = a[0];
			min = a[0];
		}
		if(max<a[i])
			max = a[i];
		if(min>a[i])
			min = a[i];
		sum = sum+a[i];
	}
	b = sum-max-min;
	avg = (int)(b/(N-2));
	printf("Canceled Max Score:%d\n",max);
	printf("Canceled Min Score:%d\n",min);
	printf("Average Score:%.0lf\n",avg);//保留整数 
}

