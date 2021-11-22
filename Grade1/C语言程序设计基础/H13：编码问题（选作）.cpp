#include <stdio.h>
int main()
{
	int n, ins, a[100] = {0}, b[100] = {0};
	scanf ("%d %d", &ins, &n);
	for (int i = 0; i < n; i++)
		scanf ("%d", &a[i]);

	if (ins == 1)
	{
		for (int j = n - 1; j >= 0; j--)
		{ 
			int tot = 0;
			for (int i = j - 1; i >= 0; i--)
			{  
	if (a[j] > a[i])
	 tot++;
			}
			b[j] = tot;
		}
	}
	else if (ins == 2)
	{
		for (int j = n - 1; j >= 0; j--)
		{
			int tot = a[j];
			for (int i = j + 1; i < n; i++)
			{
	if (a[j] >= a[i])
	 tot++;
			}
			for (int i = 1; j + i < n; i++)
			{
	if (tot == b[j+i])
	 tot++;
			}
			b[j] = tot;
			
		}
	}
	for (int i = 0; i < n; i++)
	{
		if (i != n-1) printf ("%d ", b[i]);
		else printf ("%d\n", b[i]);
	} 
}