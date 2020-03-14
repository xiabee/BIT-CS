#include <stdio.h>

int main()
{
	char c;
	int max = -1, min = 130, r, op;
	
	while ( (c = getchar()) != '=')
	{
		if (c >= '0' && c <= '9' )
		{
			if (c - '0' < min)
	min = c - '0';
			if (c - '0' > max)
	max = c - '0'; 
		}
		if (c == '%') {r = max % min;op = c;} 
		if (c == '+') {r = min + max;op = c;}
		if (c == '-') {r = max - min;op = c;}
		if (c == '*') {r = min * max;op = c;}
		if (c == '/')
		{ 
			op = c;
			if (min == 0)
			{
	printf ("Error!\n");
	return 0;
			}
			else r = max / min;
		}  
	}
	printf ("%d%c%d=%d\n",max,op, min, r);
	return 0;
}