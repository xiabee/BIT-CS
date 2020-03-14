#include<stdio.h>
int main()
{
	int a, b;
	while (scanf ("%d %d", &a, &b))
	{ 
		int c = 0;
		if (a == 0 && b == 0)
			break;
		if (a > b || a < 1000 || b < 1000)
			printf ("Error\n");
		else
		{ 
			for (int i = a; i <= b; i++)
			{
	if (i % 2 == 0)
	{
	 int g = i % 10, s = (i/10)%10, b = (i/100)%10, q = (i/1000)%10;
	 if (g != s && g != b && g != q && s != b && s != q && b != q)
	 {
	  c++;
	   printf ("%d  ", i);
	 }
	  
	}
			}
			printf ("\ncounter=%d\n", c);
		}
	}
}