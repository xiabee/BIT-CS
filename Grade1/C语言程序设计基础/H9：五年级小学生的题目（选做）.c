#include<stdio.h> 
#include<string.h> 
	int intpow(int a,int b)//a^b 
	{
	int result=1;
	int i; 
	for(i=0;i<b;i++) 
		result=result*a; 
	return result;
	} 
struct date 
	{
		int max;
		int min;
		char op;
		int r;
	}; 
struct date function(char p[],int n) 
{
	struct date result; 
	n=n-4;
	int max=-10000; 
	int min=10000; 
	int count=0; 
	int x[10]={0}; 
	int temp=0;
	int sign=1;
	int i,k; 
	for(i=0;i<=n;i++)
	{
		if (p[i]==',')
		{
			for(k=0;k<count;k++) 
				temp=temp+x[k]*intpow(10,count-1-k); 
			temp=temp*sign; 
			if(temp>max) 
				max=temp; 
			if(temp<min)
				min=temp;
			count=0;
			temp=0;
			sign=1; 
			continue;
		} 
		if(p[i]=='-') 
		{
			sign=-1;
			continue;
		} 
		else
		{
			x[count]=p[i]-'0'; 
			count++;
		}
	} 
	char opp;
	opp=p[n+1]; 
	if(opp=='+') 
	{
		result.r=max+min;
		result.op='+';
	} 
	else if(opp=='-') 
	{
		result.r=max-min;
		result.op='-';
	}
	else if(opp=='*') 
	{
		result.r=max*min;result.op='*';
	} 
	else if(opp=='/')
	{
		if(min==0) result.r=0; 
		else 
		{
			result.r=max/min;
		} 
		result.op='/';
	} 
	else if(opp=='%') 
	{
		result.r=max%min;result.op='%';
	} 
	result.max=max;
	result.min=min;
	return result;
} 
int main() 
{
	char w[100];
	gets(w); 
	int l=strlen(w); 
	struct date cc=function(w,l); 
	if(cc.op=='/'&&cc.min==0) 
		printf("Error!"); 
	else 
	{
		if(cc.max<0) 
			printf("(%d)",cc.max); 
		else 
			printf("%d",cc.max); 
			printf(" %c ",cc.op); 
		if(cc.min<0) 
			printf("(%d)",cc.min); 
		else 
			printf("%d",cc.min); 
		printf(" = "); 
		printf("%d",cc.r);
		printf("\n");
		}
	return 0; 
}
