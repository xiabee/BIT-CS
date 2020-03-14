#include<stdio.h>
int main()
{
	double a;
    scanf("%lf",&a);
    if (a<=150)
        printf("%.1lf\n",a*0.4463);
    else if(a>=151 && a<=400)
        printf("%.1lf\n",150*0.4463+(a-150)*0.4663);
    else 
        printf("%.1lf\n",150*0.4463+250*0.4663+(a-400)*0.5663);
    return 0;
 } 
