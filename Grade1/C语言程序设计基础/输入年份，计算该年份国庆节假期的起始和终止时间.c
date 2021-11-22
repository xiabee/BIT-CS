/*输入年份，计算该年份国庆节假期的起始和终止时间*/ 
#include<stdio.h>
int main(int argc,char *argv)
{
	int year,month=10,day=1,t,i;
	scanf("%d",&year); 
	for(i=1;year>1900;year--)  
        if(year%400==0||(year%4==0&&year%100!=0))	
			i+=2;  
		 else  
        	i+=1; 
	i+=day+272;					//1900年1月1日到10月1日增加的天数 ；
	i%=7;						//计算星期；
	switch(i)
	{
		case 0:printf("09.30-10.06\n");break;
		case 1:printf("10.01-10.07\n");break;
		case 2:printf("09.30-10.06\n");break;
		case 3:printf("09.29-10.05\n");break;
		case 4:printf("09.28-10.04\n");break;
		case 5:printf("09.27-10.03\n");break;
		case 6:printf("10.01-10.07\n");break;	
	}
	return 0; 	
}
