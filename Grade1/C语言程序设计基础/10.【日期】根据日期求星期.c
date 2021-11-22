#include <stdio.h>  
#include <stdlib.h>  
  
int main(int argc, char *argv[]) {  
    int year,month,day,i,t;  
    scanf("%d %d %d",&year,&month,&day);  
    if(year%400==0||(year%4==0&&year%100!=0))  
      t=1;  
    else  
      t=0;  
    for(i=1;year>1900;year--)  
        if(year%400==0||(year%4==0&&year%100!=0)){  
          i+=2;  
        }  
        else  
          i+=1;  
    switch(month){  
      case 1:i+=day-1-t;break;  
      case 2:i+=day+30-t;break;  
      case 3:i+=day+58;break;  
      case 4:i+=day+89;break;  
      case 5:i+=day+119;break;  
      case 6:i+=day+150;break;  
      case 7:i+=day+180;break;  
      case 8:i+=day+211;break;  
      case 9:i+=day+242;break;  
      case 10:i+=day+272;break;  
      case 11:i+=day+303;break;  
      case 12:i+=day+333;break;  
    }     
    i=i%7;  
    printf("%d\n",i);  
    return 0;  
}  

