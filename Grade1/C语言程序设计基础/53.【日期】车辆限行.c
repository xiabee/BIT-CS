#include<stdio.h>
int days(int year,int month,int day)
{
	int leap=0;
	int ping[13]={0,31,59,90,120,151,181,212,243,273,304,334,365};
	int run[13]={0,31,60,91,121,152,182,213,244,274,305,335,366};
	int i,sum=0;
	if(year==2012)  
	{
		sum=sum-99+ping[month-1]+day;
		return sum;
	} 
	else
	{
	   	for(i=2013;i<=year;i++)
      	if((i%4==0&&i%100!=0)||i%400==0) 
		  	sum+=366;
      	else 
		  	sum+=365;
		if((year%4==0&&year%100!=0)||year%400==0) 
		{
			leap=1;
			sum=(sum-99+run[month-1]+day-1);
		}
	   	else 
	   		sum=(sum-99+ping[month-1]+day);
		return sum;
	}
}

int sec(int n)
{
	if(n+5>=10) 
		return n-5;
	else 
		return n+5;
} 
int main()
{
	int cyc[5][5]={3,4,5,1,2,2,3,4,5,1,1,2,3,4,5,5,1,2,3,4,4,5,1,2,3};
	int year,month,day,sum;
	int time;
	while(scanf("%d %d %d",&year,&month,&day)!=EOF)
	{
		sum=days(year,month,day)+1;
		time=sum/91;
		time%=5;
		if((sum-1)%91%7==6||(sum-1)%91%7==5) 
			printf("Free.\n");
		else 
			printf("%d and %d.\n",cyc[time][(sum-1)%91%7],sec(cyc[time][(sum-1)%91%7]));
//	printf("%d",sum);
	}
	return 0;
}

