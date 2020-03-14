#include <stdio.h>
int is_sushu(int n)
{ 
	int i;
	for ( i = 2; i*i <= n; i++)
			if (n % i == 0)  return 0;
	if (i*i > n)  return 1;  
}
int main()
{
	int n;
	scanf ("%d", &n);
	
	for (; n >= 0; n--)
	{
		if ( is_sushu(n) == 1)
		{
	 printf ("The max prime number is %d.\n", n); 
	 break;	
		}
	}
}