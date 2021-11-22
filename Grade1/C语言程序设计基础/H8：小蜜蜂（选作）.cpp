#include <stdio.h>
#include <string.h>
char c[50];	   //传递值 
char * sum(char a[], char b[])
{ 
	memset(c, 0, sizeof(c));
	int la = strlen(a), lb = strlen(b), flag = 0;	//首位是否进位 
	int lc = la, len = la, carry = 0;
	for (; la - 1 >= 0 || lb - 1 >= 0; lc--, la--, lb--)
	{
		int temp = carry;
		if (la - 1 >= 0) temp = temp + (a[la-1] - '0');
		if (lb - 1 >= 0) temp = temp + (b[lb-1] - '0');
		carry = temp / 10;
		c[lc] = temp % 10 + '0';
		if (lc == 1 && carry != 0)
			flag = 1;
	}
	if (flag) 
	{
		c[0] = carry + '0';
		c[len+1] = '\0';
	}
	else	//最大位没进就全体向前移动 
	{
		for (int i = 0; c[i+1] != '\0'; i++)
			c[i] = c[i+1];
		c[len] = '\0';
	}
	return c;
}
int main()
{
	int a, b;
	scanf ("%d %d", &a, &b);
	char fb[100][50];
	memset(fb, 0, sizeof(fb));
	strcpy(fb[0], "1");
	strcpy(fb[1], "1");
	for (int i = 2; i <= b - a; i++)
		strcpy(fb[i], sum(fb[i-1], fb[i-2]));
	printf ("%s\n", fb[b-a]);
}