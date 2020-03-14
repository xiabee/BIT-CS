#include <stdio.h>
#include <string.h>
int cf(int n, int m)
{
	if (m == 0) return 1;
	else return n * cf(n, m-1); 
}
int base(char *m, int b)
{
	int i = 0, r = 0, len = strlen(m);
	int temp[100000];
	for (i = 0; i < len; i++)
	{
		if (m[len-1-i] >= '0' && m[len-1-i] <= '9')
			temp[i] = m[len-1-i] - '0';
		else if(m[len-1-i] >= 'A' && m[len-1-i] <= 'Z')
			temp[i] = m[len-1-i] - 'A' + 10;
		if (temp[i] >= b) 
			return -1;
	}
	for (i = 0; i < len; i++)
		r = r + temp[i] * cf(b, i);
	return r;
	
}
int main()
{
	int i, j, ok = 0, jn[40];;
	char m[100000], n[100000];
	scanf ("%s %s", m, n);
	for (i = 2; i <= 36; i++)
		jn[i] = base(n, i);
	for (i = 2; i <= 36; i++)
	{ 
		int temp = base(m, i);
		for (j = 2; j <= 36; j++)
		{
			if (temp == jn[j] && temp >= 0 && jn[j] >= 0)
			{
	ok = 1;
	break;
			}
		}
		if(ok) break;
	}
	if (ok)
		printf ("%s (base %d) = %s (base %d)\n", m, i, n, j);
	else if (!ok)
		printf ("%s is not equal to %s in any base 2..36\n", m, n);
}