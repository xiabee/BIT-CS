#include <stdio.h>
#include <string.h>
int main()
{
	char a[300];
	int space = 0, hc = 0, forxh = 0;
	while (gets(a))
	{
		for (int i = 0; a[i] != '\0'; i++)
		{
			if (a[i] == '}')
	space = space - 4;
			if (space && hc )
	for (int j = 0; j < space; j++)
	 printf(" ");

			hc = 0;
			printf("%c", a[i]);

			if (a[i] == '{' || a[i] == '}' || forxh == 0 && a[i] == ';' || (a[i] == '>' && a[i - 1] == 'h' && a[i - 2] == '.') || a[i] == ')' && a[i + 1] != ';'  && a[i + 1] != ')'&& !(a[i + 1] == ' ' && a[i + 2] == '?'))
			{ 
	hc = 1;
	printf("\n");  
			}
			if (forxh != 0 && a[i] == ';')
			{
	forxh--;
			} 

			if (a[i] == 'f' && a[i + 1] == 'o' && a[i + 2] == 'r')
			{
	forxh = 2;
			} 

			if (a[i] == '{')
			{
	space += 4;
			} 
			
		}
	}
}