#include <stdio.h>

int main()
{
	int a, b, d;
	char c;
	scanf ("%d%c%d", &a, &c, &b);
	
	switch (c)
	{
		case '+' : d = a + b; break;
		case '-' : d = a - b;break;
		
		case '*' : d = a * b;break;
		case '/' : d = a / b;break;
		case '%' : d = a % b;break;
	}
	
	printf ("%d\n", d);
	
}