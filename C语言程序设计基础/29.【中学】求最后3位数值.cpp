#include <stdio.h>
#include <math.h>
int main()
{
	int a, n, tot = 0, temp = 1, flag = 0;
	scanf ("%d %d", &a, &n);
	if (n == 0) temp = 1;
	else 
	{
		while (tot < n)
		{
			temp = temp * a;
			if (temp >= 100) flag = 1;	//ptf 000
			temp = temp % 1000;
			tot++;
		}
	}
	if (flag == 0 || temp > 100) printf ("The last 3 numbers is %d.\n", temp);
	if (flag == 1)
	{
		if (temp >= 10 && temp < 100)  printf ("The last 3 numbers is 0%d.\n", temp);
		else if (temp < 10) printf ("The last 3 numbers is 00%d.\n", temp);
	}
	
}