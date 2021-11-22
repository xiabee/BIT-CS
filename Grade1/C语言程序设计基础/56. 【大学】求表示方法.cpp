#include <stdio.h>
int dic(int n, int m)
{
	if (m > n) return dic(n, n);
	else if (m == 1 || n == 1) return 1;
	else if (m == n) return dic(n, m-1) + 1; 
	else return dic(n, m-1) + dic(n-m, m);
} 
int main()
{
	int n, m;
	scanf ("%d %d", &n, &m);
	int tot = dic(n, m);
	printf ("%d\n", tot);
}