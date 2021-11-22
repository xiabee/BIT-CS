#include <stdio.h>
int main()
{
	int n, m, i, j, t[100], p[150], score = 0;
	scanf ("%d %d", &n, &m);
	for (i = 0; i < n; i++)
		scanf ("%d", &t[i]);
	for (i = 0; i < m; i++)
		scanf ("%d", &p[i]);
		
	for (i = 0; i < n; i++)
	{ 
		int ok = 0, sign, chu = 1; 
		for (j = 0; j < m; j++)
		{ 
			if (p[j] >= t[i])
			{ 
	if (chu)  //第一次找到 
	 sign = j;
	else if (!chu && p[j] <= p[sign])
	 sign = j;
	chu = 0;
	ok = 1;
			}
		}
		if (ok)   //找到了一个比他大的 
		{
			score = score + p[sign];
			p[sign] = 0;
		} 
		else
		{
			printf ("bit is doomed!\n");
			return 0;
		} 
	}
	printf ("%d\n", score);
}