#include <stdio.h>  
#include <stdlib.h>    

int main() 
{  
    int min,max,a,a1,a2,a3,a4,counter=0,t=0;  
    for(;;)
	{  
      scanf("%d  %d",&min,&max);  
      if(min==0&&max==0)  
        break;  
      else if(min<=999||max>9999)  
        printf("Error\n");  
      else{  
        for(a=min,counter=0;a<=max;a++){  
          if(a%2!=0) 
		  continue;  
          t=a;  
          a1=t%10;t=t/10;  
          a2=t%10;t=t/10;  
          a3=t%10;t=t/10;  
          a4=t%10;  
          if(a4==a3||a3==a2||a2==a1||a1==a3||a1==a4||a2==a4) 
		  continue;  
          else 
		  {  
            counter++;  
            printf("%-6d",a);  
          } 
		  
        }  
        printf("\ncounter=%d\n",counter);  
      }  
	}  
    return 0;  
}  

