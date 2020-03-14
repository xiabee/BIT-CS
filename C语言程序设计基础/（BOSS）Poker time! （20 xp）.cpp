#include <stdio.h>
#include <string.h>
int main()
{
	char a[3][5], b[3][5];   //1 - »¨É«£¬ 2 - Êý×Ö 
	int na[3] = {0}, nb[3] = {0};
	scanf ("%s %s %s", a[0], a[1], a[2]);
	scanf ("%s %s %s", b[0], b[1], b[2]);
	
	for (int i = 0; i < 3; i++)
	{
		if (a[i][0] == 'H')
			na[i] = 39;
		else if (a[i][0] == 'S')
			na[i] = 26;
		else if (a[i][0] == 'D')
			na[i] = 13;
		else if (a[i][0] == 'C')
			na[i] = 0;
		else 
		{
			printf ("Input Error!\n");
			return 0;
		}
			
		if (a[i][1] >= '0' && a[i][1] <= '9')
			na[i] = na[i] + (a[i][1] - '0' - 1);
		else if (a[i][1] == '1' && a[i][2] == '0')
			na[i] = na[i] + 9;
		else if (a[i][1] == 'J')   na[i] = na[i] + 10;
		else if (a[i][1] == 'Q')   na[i] = na[i] + 11;
		else if (a[i][1] == 'K')   na[i] = na[i] + 12;
		else if (a[i][1] == 'A')   na[i] = na[i] + 13;
		else 
		{
			printf ("Input Error!\n");
			return 0;
		}  
	} 
	for (int i = 0; i < 3; i++)
	{
		if (b[i][0] == 'H')
			nb[i] = 39;
		else if (b[i][0] == 'S')
			nb[i] = 26;
		else if (b[i][0] == 'D')
			nb[i] = 13;
		else if (a[i][0] == 'C')
			nb[i] = 0;
		else 
		{
			printf ("Input Error!\n");
			return 0;
		}  
		
		if (b[i][1] >= '0' && b[i][1] <= '9')
			nb[i] = nb[i] + (b[i][1] - '0' - 1);
		else if (b[i][1] == '1' && b[i][2] == '0')
			nb[i] = nb[i] + 9;
		else if (b[i][1] == 'J')   nb[i] = nb[i] + 10;
		else if (b[i][1] == 'Q')   nb[i] = nb[i] + 11;
		else if (b[i][1] == 'K')   nb[i] = nb[i] + 12;
		else if (b[i][1] == 'A')   nb[i] = nb[i] + 13;
		else 
		{
			printf ("Input Error!\n");
			return 0;
		}   
	}  
	
	for(int i = 0; i < 3; i++) 
	{
		for (int j = i + 1; j < 3; j++)
		{
			if(na[i] == na[j])
			{
	printf ("Input Error!\n");
	return 0;	
			}
		}
	}
	for(int i = 0; i < 3; i++) 
	{
		for (int j = i + 1; j < 3; j++)
		{
			if(nb[i] == nb[j])
			{
	printf ("Input Error!\n");
	return 0;	
			}
		}
	}
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j + 1 < 3 - i; j++)
		{
			if (na[j] <= na[j+1])
			{
	int temp;
	temp = na[j];
	na[j] = na[j+1];
	na[j+1] = temp;
	char temp2[5];
	strcpy(temp2, a[j]);
	strcpy(a[j], a[j+1]);
	strcpy(a[j+1], temp2);
	
			}
			if (nb[j] <= nb[j+1])
			{
	int temp;
	temp = nb[j];
	nb[j] = nb[j+1];
	nb[j+1] = temp;
	char temp2[5];
	strcpy(temp2, b[j]);
	strcpy(b[j], b[j+1]);
	strcpy(b[j+1], temp2);
			}   
		}
	} 
	
	int fa = na[0]*10000 + na[1]*100 + na[2];
	int fb = nb[0]*10000 + nb[1]*100 + nb[2];
	
	if (fa > fb)
		printf ("Winner is A!\n");
	else if (fa < fb)
		printf ("Winner is B!\n");
	else if (fa == fb)
		printf ("Winner is X!\n");
	
	printf ("A: %s %s %s\n", a[0], a[1], a[2]);
	printf ("B: %s %s %s\n", b[0], b[1], b[2]);  
	
	}