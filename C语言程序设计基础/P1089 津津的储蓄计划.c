#include<stdio.h>
int main()
{
    int i,month,left=0,save=0,sum,plan,flag=0;
    for(month=1;month<=12;month++)
    {    
		left+=300;
        scanf("%d",&plan);
        left = left - plan;
        if(left<0)
        {    
			flag=1;
            break;
        }
        else
        {i = left/100;
         save += (100*i);
         left -= (100*i);
        }
    }
    if(flag)
        printf("-%d",month);
    else
    {    
		sum=((1.2*save) + left);
        printf("%d",sum);
    }
    return 0;
}
