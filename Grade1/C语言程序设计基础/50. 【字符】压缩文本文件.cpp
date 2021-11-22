#include <stdio.h>
#include <string.h>
int is_zm(char a)
{
	if (a >= 'a' && a <= 'z' || a >= 'A' && a <= 'Z')
		return 1;
	else return 0;
} 
int main()
{
	char word[10000][50], str[100];
	int No = 1;
	while (gets(str))
	{
		int i = 0;
		for (; str[i] != '\0'; i++)
		{ 
			char temp[50] = {'0'};
			int exit = 0;
			if (is_zm(str[i]))
			{
	int j = 0;
	while(is_zm(str[i]))
	{
	 temp[j] = str[i];
	 i++;
	 j++;
	} 
	i--;
	for (int j = 1; j <= No; j++)
	{
	 if (strcmp(temp, word[j]) == 0)
	 { 
	  exit = 1;
	  printf ("%d", j);
	  break;
	 }
	}
	if (!exit)
	{
	 printf ("%s", temp);
	 strcpy(word[No++], temp); 
	} 

			} 
			else if (!is_zm(str[i]))
			{
	printf ("%c", str[i]);
			} 
		}
		printf ("\n");
	}
}