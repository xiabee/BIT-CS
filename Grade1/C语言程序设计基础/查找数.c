#include<stdio.h>
#include<string.h>
int main()
{
	int n,i,a[10],*p=a;
	for(i=0;i<10;i++) 
		scanf("%d",&a[i]);
	scanf("%d",&n);
	for(i=0;;i++)
	{
		if(n==*(p+i))
		{
			printf("%d\n",*(p+i));
			break;
		}
		if(i==9)
		{
			printf("No\n");
			break;
		}
			
	}
}
