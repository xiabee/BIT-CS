#include<stdio.h>
int main()
{
	int p,q,min;
	scanf("%d%d",&p,&q);
	min=compare(p,q);
	printf("min=%d\n",min);
	return 0;
}

int compare(int a,int b)
{
	if(a>b)
	{
		return b;
	}
	else
	{
		return a;
	}
}
