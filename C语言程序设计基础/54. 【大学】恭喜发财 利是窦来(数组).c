#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(int argc, char *argv[]) 
{
	static char name[11][15],temp[15];
	static signed int money[11];
	int n,m,r,flag=0;
	register int i,j,k;
	scanf("%d\n",&n);
	for(i=0;i<n;i++){
		gets(name[i]);
	}
	for(i=0;i<n;i++)
	{
	    gets(temp);
	    for(j=0;j<n;j++)
		{
	    	if(strcmp(temp,name[j])==0) 
			{
	    	    flag=j;
	    	    break;
			}
	    }
	    scanf("%d %d\n",&m,&r);
	    if(r==0){
	    	money[flag]-=m;
	        continue;
	    }
	    money[flag]+=(m%r-m);
	    for(j=0;j<r;j++)
		{
	    	gets(temp);
	    	for(k=0;k<n;k++)
			{
	    		if(strcmp(temp,name[k])==0) money[k]+=m/r;
	    	}
	    }
	}
	for(i=0;i<n;i++)
	{
		j=0;
		while(name[i][j]!='\0')
		{
			printf("%c",name[i][j]);
			j++;
		}
		printf(" %d\n",money[i]);
	}
	return 0;
}
