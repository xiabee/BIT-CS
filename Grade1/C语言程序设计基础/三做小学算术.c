#include <stdio.h>  
#include <stdlib.h>  
int main() 
{  
	int a,b,c=0,e=1;  
    char op='!',t;  
    for(a=0,b=9,t=0;t!=61;)
		{  
      		scanf("%c",&t);  
      		if(t>=48&&t<=57)
	  		{  
        	if(b>t-48)b=t-48;  
        	if(a<t-48)a=t-48;  
      		}  
      		else if(t!=44&&t!=61)
			  {  
               op=t;  
               switch(t)
			   {  
                  case 42:c=a*b;break;  
                  case 43:c=a+b;break;  
                  case 45:c=a-b;break;  
                  case 47:if(b==0)  
                        	e=0;  
                          else  
                            c=a/b;  
                          break;  
                  case 37:if(b==0)  
                            e=0;  
                          else  
                            c=a%b;  
                          break;  
               }  
      }  
    }  
    if(e==0)  
      printf("Error!\n");  
    else  
      printf("%d%c%d=%d\n",a,op,b,c);  
    return 0;  
}  
