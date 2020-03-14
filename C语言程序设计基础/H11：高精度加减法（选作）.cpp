#include <stdio.h>
#include <string.h>
char d[2000];
int maxlen(int a, int b)
{
	if (a > b) return a;
	else return b;
}

char * add(char * a, char * b)
{ 
	memset(d, '0', sizeof(d));
	int len1 = strlen(a), len2 = strlen(b);
	int len3 = maxlen(len1, len2);
	int i = len3, carry = 0;
	for (; len1 - 1 >= 0 || len2 - 1>= 0; i--, len1--, len2--)
	{ 
		int temp = carry;
		carry = 0;
		if (len1 - 1 >= 0) temp = temp + (a[len1 - 1] - '0');
		if (len2 - 1 >= 0) temp = temp + (b[len2 - 1] - '0');
		
		if (temp >= 10)
		{
			carry = 1;
			temp = temp % 10;
		}
		
		d[i-1] = temp + '0';
	}
	if (carry)
	{
		for (int i = len3; i >= 1; i--)
			d[i] = d[i-1];
			
		d[0] = '1';
		d[len3+1] = '\0';
	}
	else 
		d[len3] = '\0';
	return d;
}

char * minus(char * a, char * b)
{
	memset(d, '0', sizeof(d));
	int len1 = strlen(a), len2 = strlen(b);
	int len3 = maxlen(len1, len2);
	int i = len3, carry = 0;
	for (; len1 - 1 >= 0 || len2 - 1 >= 0;len1-- , len2--, i--)
	{
		int temp = carry;
		carry = 0;
		if (len1 - 1 >= 0) temp = temp + (a[len1 - 1] - '0');
		if (len2 - 1 >= 0) temp = temp - (b[len2 - 1] - '0');
		
		if (temp < 0)
		{
			temp = 10 + temp;
			carry = -1;
		}
		
		d[i-1] = temp + '0';
	}
	if ( d[0] == '0')
	{ 
		int n0;
		for ( n0 = 0; d[n0] == '0'; n0++);
		for (int i = 0; i < len3 - n0 ; i++)
		{
			d[i] = d[i+n0];
		}
		d[len3-n0] = '\0';
	}
	else
		d[len3] = '\0';
	
	return d;
}

int compare(char * a, char * b)
{
	int len1 = strlen(a), len2 = strlen(b);
	if (len1 > len2) return 1;
	else if (len1 < len2) return -1;
	else if (len1 == len2)
	{
		if (strcmp(a, b) > 0) return 1;
		else if (strcmp(a, b) < 0) return -1;
		else if (strcmp(a, b) == 0) return 0;
	}
}
int main()
{ 
	char * add(char * a, char * b);
	char * minus(char * a, char * b);
	int compare(char * a, char * b);
	int n, i;
	scanf ("%d", &n);
	while (n--)
	{
		char c[2000], a[2000], b[2000];
		int na = 0, nb = 0;
		scanf ("%s", c);
		for (i = 0; c[i] >= '0' && c[i] <= '9'; i++)
			a[na++] = c[i];
		a[na] = '\0';
		
		char ins = c[i];
		i++;
		
		for (; c[i] != '\0'; i++)
			b[nb++] = c[i];
		b[nb] = '\0';
		
		if (ins == '+')
			printf ("%s\n", add(a, b));
		else if (ins == '-')
		{
			if (compare(a, b) > 0) 
	printf ("%s\n", minus(a, b));
			else if (compare(a, b) < 0)
	printf ("-%s\n", minus(b, a));
			else if (compare(a, b) == 0)
	printf ("0\n");
		}  
	}
}