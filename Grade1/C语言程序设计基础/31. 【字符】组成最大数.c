#include<stdio.h>
#define N 100
int main()
{
	char a[N]={'\0'};		//≥ı ºªØ£ª
	int i,j,k;
	scanf("%s",&a);
	for(i=0;a[i]!=0;i++)
		for(k=i+1;a[k]!=0;k++)	
			if(a[i]<a[k])
			{
				j=a[i];
				a[i]=a[k];
				a[k]=j;
		 	}	 
		 puts(a);
	return 0;
 } 
