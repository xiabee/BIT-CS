#include<stdio.h>
#include<string.h>
int main()
{
	printf("ÖÇÕÏ¸´¶Á£¬ÎªÄú·þÎñ£º\n\n");
	while(1)
	{
		char a[1000];
		gets(a);
		if(strcmp(a,"exit")==0||strcmp(a,"stop")==0)
			break;
		else
		{
			printf("BOT£º\n");
			puts(a);
			printf("\n"); 
		}
	}
}
