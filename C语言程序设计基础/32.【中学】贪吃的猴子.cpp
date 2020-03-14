#include <stdio.h>
int pc = 1;
int eat(int n)	 //
{ 
	if (n == 0) return 0;
	else 
	{
		pc =(pc + n) * 2;
		eat(n-1);
	}
}
	
int main()
{
	int n;
	scanf ("%d", &n);
	eat(n-1);
	if (pc != 1) printf ("The monkey got %d peaches in first day.\n", pc);
	else printf ("The monkey got %d peach in first day.\n", pc);
}