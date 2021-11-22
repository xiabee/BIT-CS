#include <stdio.h>
int f(int a, int b)
{
	if (a == b) return a;
	else if (a > b) return f(a-b, b);
	else if (a < b) return f(a, b-a);
}
int main()
{
	int a, b;
	scanf ("%d %d", &a, &b);
	printf ("%d\n", f(a, b));
}