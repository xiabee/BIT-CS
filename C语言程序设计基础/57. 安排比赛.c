#include<stdio.h>
int main()
{
	int n,a;
	scanf("%d",&n);
	while(n--)
	{
		scanf("%d",&a);
		if(a>1)
			printf("%d\n",a*(a-1)/2/(a/2));
		else 
			printf("0\n");
	}
	return 0;
}
