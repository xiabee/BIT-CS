#include<stdio.h>
#include<string.h>
int leap(int n);
int main()
{
	int n,date=0,i,j,k;
	scanf("%d",&n);
	int ans_week[7]={0};
	const month[2][12]={{31,28,31,30,31,30,31,31,30,31,30,31},{31,29,31,30,31,30,31,31,30,31,30,31}};
	for(i=1900;i<1900+n;i++)//loop of year; 
		for(j=0;j<12;j++)//loop of month;
			for(k=0;k<month[leap(i)][j];k++)//loop of day;
			{
				date++;
				if(k==13)//The 13th day;
					ans_week[date%7]++;
			}
	printf("%d %d %d %d %d %d %d",ans_week[0],ans_week[1],ans_week[2],ans_week[3],ans_week[4],ans_week[5],ans_week[6]);//Sat Sun Mon Tue Wed Thu Fri
}

int leap(int n)
{
	int t=0;
	if((n%4==0)&&(n%100!=0)||(n%400)==0)
		t++;
	return(t);
}
