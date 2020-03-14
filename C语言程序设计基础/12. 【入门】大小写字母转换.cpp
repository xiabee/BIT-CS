#include <stdio.h>

void main()
{
	char ch;

	scanf ("%c", &ch);

	if (ch >= 65 && ch <= 90)   ch = ch + 32;
	else if (ch >= 97 && ch <= 122)   ch = ch -32;
	else ch=ch;

	printf ("%c\n", ch);
}