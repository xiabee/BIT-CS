#include <stdio.h>       
#include <stdlib.h>       
       
int main(int argc, char *argv[]) {       
 int y,m,d,y0,m0,d0,ny,nm,counter,sum,ycounter=0,flag1=0;       
         
   for(counter=0;1;counter++)       
 {       
      scanf("%d %d %d",&y,&m,&d);       
        if(counter==1) break;       
        y0=y,m0=m,d0=d;       
    }       
    if(leap_year(y0)) flag1=1;else flag1=2;       
    ny=y-y0,nm=m-m0;       
    for(y0++;y0<y;y0++)       
    {       
        if(leap_year(y0)) ycounter++;       
    }       
    sum=(ny-ycounter-1)*365+ycounter*366;       
    if(ny==0&&nm==0) {printf("%d days\n",sum=d-d0);return 0;}       
           
    switch(m0)       
    {       
        case 1:case 3:case 5:case 7:case 8:case 10:case 12: sum+=31-d0; break;       
     case 4:case 6:case 9:case 11: sum+=30-d0; break;       
       case 2: if(flag1==1) sum+=29-d0;       
               else sum+=28-d0; break;       
    }       
    if(ny==0&&nm!=0)       
    {       
       for(m0++;m0<m;m0++)       
     {       
          if(m0==1||m0==3||m0==5||m0==7||m0==8||m0==10) sum+=31;       
         if(m0==4||m0==6||m0==9||m0==11) sum+=30;       
           if(m0==2)       
          {       
              if(flag1==1) sum+=29;       
              else sum+=28;       
          }       
      }       
      sum+=d+365;       
        printf("%d days\n",sum);       
       return 0;       
    }       
    for(m0++;m0<=12;m0++)       
       {       
          if(m0==1||m0==3||m0==5||m0==7||m0==8||m0==10||m0==12) sum+=31;       
         if(m0==4||m0==6||m0==9||m0==11) sum+=30;       
           if(m0==2)       
          {       
              if(flag1==1) sum+=29;       
              else sum+=28;       
          }       
      }       
      sum+=d;       
    for(m--;m>=1;m--)       
    {       
     if(m==1||m==3||m==5||m==7||m==8||m==10||m==12) sum+=31;       
            if(m==4||m==6||m==9||m==11) sum+=30;       
           if(m==2)       
           {       
              if(flag1==1) sum+=29;       
              else sum+=28;       
          }       
    }       
    printf("%d days\n",sum);   
   return 0;       
}
