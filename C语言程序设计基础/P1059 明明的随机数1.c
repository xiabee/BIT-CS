#include<stdio.h>  
int n,i,count;int num[1010]={0};//定义全局变量，值自动赋为0，num数组用来进行桶排  
int main()
{   
    scanf("%d",&n);//读入随机数的个数  
    while(n--)
	{
        scanf("%d",&i);//读入随机数i  
        if(num[i]==1)//如果已有  
            continue;//跳出本层while循环  
        num[i]=1;
		count++;//不重复，修改num[i]状态为已有，并计入不重复的随机数总数  
}  
//输出不重复的随机数总数  
   printf("%d\n",count);  
//输出排序后的随机数  
   for(i=1;i<1000;i++)//循环查找元素  
        if(num[i]) 
		   	printf("%d ",i);//如果i存在，则输出i  
   return 0;  
}
