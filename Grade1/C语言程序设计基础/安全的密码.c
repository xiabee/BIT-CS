#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(int argc, char *argv[]) 
{
	static int f[100];
	static int  n,i,j,k,p1,p2,p3,p4;
	scanf("%d",&n);
	getchar();
	static char a[100][100];
	for(i=0;i<n;i++)
	{
		for(j=0;j<21;j++)
		{
			gets(a[i]);
			p1=0;p2=0;p3=0;p4=0;
			if(strlen(a[i])<6) 
			    f[i]=0;
			else 
			for(k=0;k<strlen(a[i])-1;k++)
			{
				if(a[i][k]>=48&&a[i][k]<=57&&p1==0)
				{
					p1=1;f[i]++;
		        }
			    else if(a[i][k]>=65&&a[i][k]<=90&&p2==0)
				{
		            p2=1;f[i]++;
				}
				else if(a[i][k]>=97&&a[i][k]<=122&&p3==0)
				{
					p3=1;f[i]++;
				}
				else if((a[i][k]<48||(a[i][k]>57&&a[i][k]<65)||(a[i][k]>90&&a[i][k]<97)||a[i][k]>122)&&p4==0)
				{
					p4=1;f[i]++;
				}
			}
			break;
		}
	}
	for(i=0;i<n;i++)
	{
		switch(f[i])
		{
			case 0:case 1:printf("Not Safe\n");break;
			case 2:printf("Medium Safe\n");break;
			case 3:case 4:printf("Safe\n");break;
		}
	}
	return 0;
}
