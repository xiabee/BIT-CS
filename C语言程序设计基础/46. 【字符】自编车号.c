#include<stdio.h>
#include<stdlib.h>
int main()
{
	char a[5];
	int i,p=0,f=0;
	for(i=0;i<=4;i++)
	{
		scanf("%c",&a[i]);
		if(a[i]<48||(a[i]>57&&a[i]<65)||a[i]>=90) 
			f=1; 
	    if(a[i]>=65&&a[i]<=90&&a[i]!=73&&a[i]!=79) 
			p++;
	}
	if(a[4]<48||a[4]>57||p<2) 
		f=1;
    if(f==0) 
		printf("ok.\n");
    else 
		printf("no.\n");
	return 0;
}
