#include<stdio.h>
#include<math.h>
#include<stdlib.h> 
#define MAX 100000000
int isPrime(int n)//判断素数函数。
{
    int i;
    for(i=2;i<=(int)sqrt(n);i++)//从2到算数平方根遍历。
        if(n%i == 0) 
			return 0;//存在约数，非素数，返回0.
    return 1;//是素数，返回1.
}
int main()
{
    int i;
    FILE *fp=fopen("Prime_Number.txt","w");//写入文档； 
    for(i=2;i<=MAX;i++)//遍历。
        if(isPrime(i))//是素数。
        {
        	printf("%d,", i);//输出素数。
        	fprintf(fp,"%d,",i);//写入文档； 
		}
	fclose(fp); 
    return 0;
}
