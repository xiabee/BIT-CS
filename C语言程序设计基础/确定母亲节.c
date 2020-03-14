#include<stdio.h>
#include <stdlib.h>
int main()
{
	int year,day=0,a,b;
	scanf("%d",&year);
	a=(year-2000)%4;
  	b=(year-2000)/4;
	switch(a)
	{
		case 0:for(day=14;b!=0;b--)
           	switch(day)
            {
				case 14:day=9;break;
             	case 13:day=8;break;
             	case 12:case 11:case 10:case 9:case 8:
                     day+=2;break;
            }
			break;
  		case 1:for(day=13;b!=0;b--)
           switch(day)
            {
				case 14:day=9;break;
             	case 13:day=8;break;
             	case 12:case 11:case 10:case 9:case 8:
                     day+=2;break;
            }
			break;
  		case 2:for(day=12;b!=0;b--)
           switch(day)
            {
				case 14:day=9;break;
             	case 13:day=8;break;
             	case 12:case 11:case 10:case 9:case 8:
                     day+=2;break;
            }
			break;
  		case 3:for(day=11;b!=0;b--)
           switch(day)
            {
				case 14:day=9;break;
             	case 13:day=8;break;
             	case 12:case 11:case 10:case 9:case 8:
                     day+=2;break;
            }
			break;
 			}
  			printf("%d\n",day);
    return 0; 
}
