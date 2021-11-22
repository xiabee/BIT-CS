#include <stdio.h>
int main()
{
	int a[100][100] = {0}, h, l, i, j, ok = 0;
	scanf ("%d %d", &h, &l);
	for (j = 0; j < h; j++)
		for (i = 0; i < l; i++)
			scanf ("%d", &a[j][i]);
	for (j = 0; j < h; j++)
	{ 
		int max = a[j][0], signy = 0, flag = 1;
		for (i = 0; i < l; i++)
		{
			if (a[j][i] >= max)
			{
	max = a[j][i];
	signy = i;
			}
		}
		for (i = 0; i < h; i++)
		{
			if (a[j][signy] > a[i][signy])
			{
	flag = 0;
	break;
			}
		}
		if (flag)
		{
			ok = 1;
			printf ("Point:a[%d][%d]==%d\n", j, signy, a[j][signy]);
		}
	}
	if (!ok)
		printf ("No Point\n");
}