#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main(int argc, char *argv[])
{ float x,x1,x2,d,i,a,b,c;
  scanf("%f%f%f",&a,&b,&c);
  d=b*b-4*a*c;
  if(a==0&&b==0)
    printf("Input error!\n");
  else if(a==0)
  {if(c==0)
  x=c/b;
  else
  x=-c/b;
  printf("x=%f\n",x);
  }
       else if(d==0)
       {if(b==0)
       x=b/2/a;
       else
       x=-b/2/a;
       printf("x1=x2=%f\n",x);
       }
            else if(d>0)
            {x1=(-b+sqrt(d))/2/a;
            x2=(-b-sqrt(d))/2/a;
            printf("x1=%f\nx2=%f\n",x1,x2);
            }
                 else if(b==0)
                 {i=sqrt(-d)/2/a;
                 printf("x1=%fi\nx2=-%fi\n",i,i);
                 }
                      else
                      {x=-b/2/a;
                      i=sqrt(-d)/2/a;
                      printf("x1=%f+%fi\nx2=%f-%fi\n",x,i,x,i);
                      }
  system("PAUSE");	
  return 0;
}
