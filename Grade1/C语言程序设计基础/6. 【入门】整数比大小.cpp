#include <stdio.h>
int main()
{
	int a, b;
	scanf ("%d %d", &a, &b);
	if (a > b)   printf ("min=%d\n", b);
	else		 printf ("min=%d\n", a);
}