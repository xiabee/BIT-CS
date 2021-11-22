#include<stdio.h>
int main()
{
	int n,year,month,day,leap,i,t,h;
	scanf("%d",&n);
	while(n--)
	{
		t=0;
		scanf("%d %d %d",&year,&month,&day);
		if(((year%4==0)&&(year%100!=0))||(year%400==0))
			leap=1;
		else
			leap=0;
		for(i=1990;i<year;i++)
		{
			if(((i%4==0)&&(i%100!=0))||(i%400==0))
			{
				t+=366;
			}
			else
			{
				t+=365;
			}
		}
		int a[]={0,31,28+leap,31,30,31,30,31,31,30,31,30,31};
		for(h=0;h<month;h++)
			t+=a[h];
		t+=day;
		
		printf("t=%d\n",t);
		if(t%5==1||t%5==2||t%5==3)                         
		printf("He was fishing on %d.%d.%d\n",year,month,day);
		else  
		printf("He was basking on %d.%d.%d\n",year,month,day);
	}
	
	return 0;
 } 
