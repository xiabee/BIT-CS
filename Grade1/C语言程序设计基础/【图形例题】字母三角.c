#include<stdio.h>
char trans(char a)
{
	if(a>='A'&&a<='Z')
		return a;	
	else
	{
		a-=26;
		return (trans(a));
	}
}
int main()
{
	int n,i,j;
	char ch;
	scanf("%d",&n);
	getchar();
	scanf("%c",&ch);
	for(i=0;i<n-1;i++)//´òÓ¡Ç°n-1ÐÐ 
	{
		for(j=0;j<n-1+i;j++)
		{
			if(j==n-i-1)
				printf("%c",trans(ch+i));
			else
				printf(" ");
		}
		printf("%c\n",trans(ch+i));
	}
	for(i=0;i<n-1;i++)
		printf("%c",trans(ch+i+n-1));
	for(i=n-1;i>=0;i--)
		printf("%c",trans(ch+i+n-1));
	printf("\n");
	return 0;
}
