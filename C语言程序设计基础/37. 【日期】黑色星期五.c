#include<stdio.h>
#include<string.h>
int main(int argc, char *argv[])
{
	int mon,y,m,d=13,w,sum[100],i=0,y0,c=0;
	scanf("%d",&y);
	y0=y;
	for(m=1;m<=12;m++)
	{
		mon=m;
		if(m==1||m==2)
		{
			m+=12;	//公式需要； 
			y--;
		}
		w=(d+2*m+3*(m+1)/5+y+y/4-y/100+y/400)%7+1;//基姆拉尔森计算公式
		if(w<0)
		w=(w+7)%7;
		if(w==5)
		{
			sum[i]=mon;							//sum[i]记录月份； 
			i++;
		}
		if(m==13||m==14) 
		{    
            m=m-12; y++;    //还原月份； 
        }    
        if(m==12)
			break;  
	}
	 if(i>1)    
    {    
        printf("There are %d Black Fridays in year %d.\n",i,y0);    
        printf("They are:\n");    
        for(;c<i;c++)    					//已定义c=0； 
        printf("%d/%d/13\n",y0,sum[c]);   
    }    
    if(i==1)    
    {    
        printf("There is %d Black Friday in year %d.\n",i,y0);    
        printf("It is:\n");    
        for(;c<i;c++)    
        printf("%d/%d/13\n",y0,sum[c]);    
    }    
    if(i==0)    
    printf("There is no Black Friday in year %d.\n",y0);    
    return 0;    
}

