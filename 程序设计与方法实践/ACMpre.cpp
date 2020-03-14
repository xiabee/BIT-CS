#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define max(x,y) (x>y?x:y)
int main()
{
	int a, b, c, v, s, s1, s2;
	v = scanf("%d%d%d", &a, &b, &c);
	if (a == 1 && b == 1)
	{
		s1 = (c / 2) * 3;
		s2 = (c / 3) * 5;
		s = max(s1, s2);
	}
	else if ((a == 1 && b == 2) || (a == 2 && b == 1))
		s = c * 3;
	else if ((a == 1 && b == 3) || (a == 3 && b == 1))
		s = c * 5;
	else
	{

	}
	return 0;
}