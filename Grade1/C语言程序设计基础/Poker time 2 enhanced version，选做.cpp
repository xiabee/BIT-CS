#include <stdio.h>
#include <string.h>
int main()
{
	char a[4][5] = {'0'}, b[4][5] = {'0'};
	int na[5] = {0}, nb[5] = {0}, ra = 0, rb = 0, oka = 0, okb = 0;
	scanf ("%s %s %s", a[1], a[2], a[3]);
	scanf ("%s %s %s", b[1], b[2], b[3]);
	
	for (int i = 1; i <= 3; i++)
	{
		if (a[i][1] == '1' && a[i][2] == '0')
			na[i] = 32;
		else if (a[i][1] >= '2' && a[i][1] <= '9')
			na[i] = (a[i][1] - '2') * 4;
		else if (a[i][1] == 'J')
			na[i] = 36;
		else if (a[i][1] == 'Q')
			na[i] = 40;
		else if (a[i][1] == 'K')
			na[i] = 44;
		else if (a[i][1] == 'A')
			na[i] = 48;
		else 
		{
			printf ("Input Error!\n");
			return 0;
		}
		if (a[i][0] == 'C')
			na[i] = na[i];
		else if (a[i][0] == 'D')
			na[i]= na[i]+ 1;
		else if (a[i][0] == 'S')
			na[i] = na[i]+ 2;
		else if (a[i][0] == 'H')
			na[i] = na[i] + 3;
		else
		{
			printf ("Input Error!\n");
			return 0;
			} 
		
		if (b[i][1] == '1' && b[i][2] == '0')
			nb[i] = 32;
		else if (b[i][1] >= '2' && b[i][1] <= '9')
			nb[i] = (b[i][1] - '2') * 4;
		else if (b[i][1] == 'J')
			nb[i] = 36;
		else if (b[i][1] == 'Q')
			nb[i] = 40;
		else if (b[i][1] == 'K')
			nb[i] = 44;
		else if (b[i][1] == 'A')
			nb[i] = 48;
		else 
		{
			printf ("Input Error!\n");
			return 0;
		}
		
		if (b[i][0] == 'C')
			nb[i] = nb[i];
		else if (b[i][0] == 'D')
			nb[i] = nb[i] + 1;
		else if (b[i][0] == 'S')
			nb[i] = nb[i] + 2;
		else if (b[i][0] == 'H')
			nb[i] = nb[i] + 3;
		else
		{
			printf ("Input Error!\n");
			return 0;
			}   
	}
	
	for (int i = 0; i < 2; i++)   //排序了 
	{
		for (int j = 1; j + 1 <= 3 - i; j++)
		{
			if (na[j] < na[j+1])
			{
	char temp[5];
	strcpy(temp, a[j]);
	strcpy(a[j], a[j+1]);
	strcpy(a[j+1], temp);
	int temp2;
	temp2 = na[j];
	na[j] = na[j+1];
	na[j+1] = temp2;
			}
			if (nb[j] < nb[j+1])
			{
	char temp[5];
	strcpy(temp, b[j]);
	strcpy(b[j], b[j+1]);
	strcpy(b[j+1], temp);
	int temp2;
	temp2 = nb[j];
	nb[j] = nb[j+1];
	nb[j+1] = temp2;
			} 
			
			if (na[j] == na[j+1] || nb[j] == nb[j+1]) 
			{
	printf ("Input Error!\n");
	return 0;
			} 
		}
	}
	
	if (na[1] / 4 == na[2] / 4 || na[1] / 4 == na[3] / 4 || na[2] / 4 == na[3] / 4) //对子 
	{ oka = 1;
		ra = 1000;
		int temp1 = na[1] / 4, temp2 = na[2] / 4, temp3 = na[3] / 4;
		if (temp1 == temp2 || temp1 == temp3)
			ra = ra + temp1 * 10;
		else if (temp2 == temp3)
			ra = ra + temp2 * 10;
	} 
	if (na[1] / 4 - 1 == na[2] / 4 && na[2] / 4 - 1 == na[3] / 4) //连牌 
	{
		oka = 1;
		ra = 2000 + na[1] / 4 * 10; 
	} 
	if (na[1] / 4 == na[2] / 4 && na[1] / 4 == na[3] / 4 && na[2] / 4 == na[3] / 4) //炸弹 
	{
		oka = 1;
		ra = 3000 + na[1] / 4 * 10;
	} 
	if (na[1] - 4 == na[2] && na[2] - 4 == na[3]) //同花顺 
	{ 
		oka = 1;
		ra = 4000 + na[1] / 4 * 10 + na[1] % 4;
	}
	if (!oka)
		ra = na[1]; 

	if (nb[1] / 4 == nb[2] / 4 || nb[1] / 4 == nb[3] / 4 || nb[2] / 4 == nb[3] / 4) //对子 
	{ okb = 1;
		rb = 1000;
		int temp1 = nb[1] / 4, temp2 = nb[2] / 4, temp3 = nb[3] / 4;
		if (temp1 == temp2 || temp1 == temp3)
			rb = rb + temp1 * 10;
		else if (temp2 == temp3)
			rb = rb + temp2 * 10;
	} 
	if (nb[1] / 4 - 1 == nb[2] / 4 && nb[2] / 4 - 1 == nb[3] / 4) //连牌 
	{
		okb = 1;
		rb = 2000 + nb[1] / 4 * 10; 
	} 
	if (nb[1] / 4 == nb[2] / 4 && nb[1] / 4 == nb[3] / 4 && nb[2] / 4 == nb[3] / 4) //炸弹 
	{
		okb = 1;
		rb = 3000 + nb[1] / 4 * 10;
	} 
	if (nb[1] - 4 == nb[2] && nb[2] - 4 == nb[3]) //同花顺 
	{ 
		okb = 1;
		rb = 4000 + nb[1] / 4 * 10 + nb[1] % 4;
	}
	if (!okb)
		rb = nb[1]; 
		
	if (ra > rb)
		printf ("Winner is A!\n");
	else if (ra < rb)
		printf ("Winner is B!\n");
	else printf ("Draw!\n");
	
	printf ("A: %s %s %s\n", a[1], a[2], a[3]);
	printf ("B: %s %s %s\n", b[1], b[2], b[3]);
}