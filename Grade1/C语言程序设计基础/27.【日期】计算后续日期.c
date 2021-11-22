#include <stdio.h>
#include <stdlib.h>
int main(int argc, char *argv[]) 
	{
	int year,month,day,n,l=0,p=0;
	scanf("%d %d %d",&year,&month,&day);
	scanf("%d",&n);
	n+=day-1;
    day=1;
	do
	{
	if((year%4==0&&year%100!=0)||year%400==0) l=1;
	else l=0;
    switch(month)
	  {case 1:case 3:case 5:case 7:case 8:case 10:case 12:p=31;break;
   	   case 4:case 6:case 9:case 11:p=30;break;
	   case 2:p=28+l;break;
	  }
	if(n>p-1){
	  month++;
	  n-=p;
	}
    else{
	  day+=n;
	  n=0;
	}
	if(month>=13) {
	  month%=12;
	  year++;
    }
    }while(n!=0);
	printf("%d.%d.%d\n",year,month,day);
	return 0;
}
