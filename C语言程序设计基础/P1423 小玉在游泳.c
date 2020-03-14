#include<stdio.h>
int main()
{
    float a,b=2,k=2;
    int i=1;
    scanf("%f",&a);
    for(i=1;;i++)
    {
		if(k>a) 
			break;/*判断是否游到目标*/
    	else 
     	{
          	b=b*0.98;/*每步能游的距离*/
          	k=b+k;/*每步结束后的已游总距离*/
      	}
	}
    printf("%d",i);/*输出步数*/
    return 0;
}
