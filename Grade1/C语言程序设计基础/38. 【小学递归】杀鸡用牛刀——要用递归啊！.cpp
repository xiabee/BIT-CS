#include <stdio.h>
int sb(int a, int b)
{
	if (a == b) return b;
	else return a+sb(a+1, b);
}
int main()
{
	int a, b;
	scanf ("%d %d", &a, &b);
	printf ("The sum from %d to %d is %d.\n",a, b, sb(a, b));
}