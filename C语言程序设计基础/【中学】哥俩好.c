#include<stdio.h>
#include<string.h>
int main(int argc, char *argv[])
{
	int str[20],n,a,i,j,flag=0;
	scanf("%d",&n);
	flag=n%2;
	for(i=0;i<n;i++)
		scanf("%d",&str[i]);
	for(j=0;j<(n-flag)/2;j++)
	{
	    a=str[j]*str[n-j-1];
	    printf("%d ",a);
    }
    if(flag==1) 
		printf("%d ",str[(n+flag)/2-1]);
    printf("\n");
	return 0;
}
