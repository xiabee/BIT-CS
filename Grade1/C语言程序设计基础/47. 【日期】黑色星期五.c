#include <stdio.h>    
#include <stdlib.h>    
int main(int argc, char *argv[]) {    
    int mon,y,m,d=13,sm[100],w,i=0,y0,c=0;    
    scanf("%d",&y);    
    y0=y;    
        
    for(m=1;m<13;m++)    
    {    
        mon=m;    
        if(m==1||m==2) {m=m+12;y--;}       
        w=((d+2*m+3*(m+1)/5+y+y/4-y/100+y/400)%7)+1;      
        if(w<0) w=(w+7)%7;        
        if(w==5)     
        {    
            sm[i]=mon;    
            i++;    
        }    
        if(m==13||m==14) {    
            m=m-12; y++;    
        }    
        if(m==12) break;    
    }    
    if(i>1)    
    {    
        printf("There are %d Black Fridays in year %d.\n",i,y0);    
        printf("They are:\n");    
        for(;c<i;c++)    
        printf("%d/%d/13\n",y0,sm[c]);    
    }    
    if(i==1)    
    {    
        printf("There is %d Black Friday in year %d.\n",i,y0);    
        printf("It is:\n");    
        for(;c<i;c++)    
        printf("%d/%d/13\n",y0,sm[c]);    
    }    
    if(i==0)    
    printf("There is no Black Friday in year %d.\n",y0);    
    return 0;    
} 
