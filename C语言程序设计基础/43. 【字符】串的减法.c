#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) 
{
	int i,j,k=0,p;
	static char s[80],t[80],u[80];
	scanf("%s%s",s,t);
	
	for(i=0;i<=79;i++)
	{
		for(j=0,p=0;j<=79;j++)
		    if(s[i]==t[j]) 
				p=1;
		if(p==0) 
		{
		    u[k]=s[i];
			k++;
	    }
    }

	puts(u);
	return 0;
}
