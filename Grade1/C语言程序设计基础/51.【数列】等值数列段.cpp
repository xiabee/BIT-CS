#include <stdio.h>
int main()
{
	int a[100], n, ml = 0, rst, red;
	scanf ("%d", &n);
	for (int i = 0; i < n; i++)
		scanf ("%d", &a[i]);
	for (int i = 0; i < n; i++)
	{
		if (a[i] == a[i+1])
		{
			int st = i;
			while(a[i] == a[i+1])
	i++;
			int ed = i;
			int l = ed - st;
			if (l > ml)
			{
	ml = l;
	rst = st;
	red = ed;
			}	
		}
	}
	if (ml != 0)
		printf ("The longest equal number list is from %d to %d.\n", rst, red);
	else if (ml == 0)
		printf ("No equal number list.\n");
}