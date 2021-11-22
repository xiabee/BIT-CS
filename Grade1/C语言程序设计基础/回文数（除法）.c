#include<stdio.h>
#include<stdlib.h>
int huiwenshu(int number)
{
	int res=0;
	int n=number;
	if(n==0)
	{
		return 0;
	}
	do
	{
		res=res*10+n%10;
		n/=10;
	}
	while(n);
	if(res==number)
		return 1;	
	return 0;
 } 
int main(int argc,char argv[])
{
	int num,squ,i;
    int ret = 0;
    scanf("%d",&num);
    for(i=1;i<num;i++)
    {
    	squ=i*i;
    	ret=huiwenshu(squ);
    	if(ret==1)
    	printf("%d\n",i);
	}
	
    return 0;
}
