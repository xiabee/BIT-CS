#include <stdio.h>

int main(){
  int a1,a2,b1,b2,c1,c2,x1,x2,x3,y1=0,y2=0,y3=0;
  scanf("%d %d %d",&a1,&b1,&c1);
  scanf("%d %d %d",&a2,&b2,&c2);
  for(x1=1;x1<b1;x1++)
  switch(x1)
  {case 1: case 3: case 5:case 7:case 8:case 10:case 12:y1=y1+31;break;
   case 4:case 6:case 9:case 11:y1=y1+30;break;
   default:y1=y1+28+((a1%4==0&&a1%100!=0)||a1%400==0);
  }
  for(x2=a1;x2<a2;x2++)
      y2=y2+365+((x2%4==0&&x2%100!=0)||x2%400==0);
  for(x3=1;x3<b2;x3++)
  switch(x3)
     {case 1: case 3: case 5:case 7:case 8:case 10:case 12:y3=y3+31;break;
      case 4:case 6:case 9:case 11:y3=y3+30;break;
      default:y3=y3+28+((a1%4==0&&a1%100!=0)||a1%400==0); 
    }
  printf("%d days\n",y2+y3+c2-y1-c1);
}

