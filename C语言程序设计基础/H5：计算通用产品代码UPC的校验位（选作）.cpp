#include <stdio.h>

int main()
{ 
	int i;
	char a, b[5], c[5], temp;
	a = getchar();
	temp = getchar();
	gets(b);
	gets(c);
	
	int n[15];
	n[1] = a - '0';
	for (i = 2; i <= 6; i++)
		n[i] = b[i - 2] - '0';
	for (i = 7; i <= 11; i++)
		n[i] = c[i - 7] - '0';
	
	/*for (i = 1; i <= 11; i++)
		printf ("%d ", n[i]);*/
	
	int sum1=0, sum2=0;
	for (i = 1; i <= 11; i++)
	{
		if (i%2 != 0) sum1 = sum1 + n[i];
		else sum2 = sum2 + n[i];
	}
	int r1 = 9-(sum1*3 + sum2 - 1)%10;
	printf ("%d\n", r1);
	}