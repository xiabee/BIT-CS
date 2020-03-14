#include <stdio.h>
int sb(char * p0, char * p1)
{
	if (p0 >= p1) return 1;
	else
	{
		if (*p0 != *p1) return 0;
		else if (*p1 == *p0) return sb(p0+1, p1-1);
	}
} 
int main()
{
	char a[20];
	char * p0 = a, * p1 = a;
	gets (a);
	while (*p1)
		p1++;
	p1--;
	int ok = sb(p0, p1);
	if (ok) printf ("Yes\n");
	else printf ("No\n");
}