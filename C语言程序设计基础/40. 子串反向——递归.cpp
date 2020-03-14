/* PRESET CODE BEGIN - NEVER TOUCH CODE BELOW */

#include <stdio.h>
#include <stdlib.h>
void reverse( );
int main( )
{ char str[100];
	int start, end;
	gets(str);
	scanf("%d%d", &start, &end);
	reverse( str, start, end );
	printf("%s\n", str);
	return 0;
}

/* PRESET CODE END - NEVER TOUCH CODE ABOVE */

void reverse(char *str, int start, int end)
{
	char * p1, * p2, * p3;
	p1 = p2 = str;
	while (*p2)
		p2++;
	p2--;
	if (p1 + end > p2)
			p3 = p2;
	else
			p3 = p1 + end;
	p1 = p1 + start;
	while (p1 < p3)
	{
		char temp;
		temp = *p1;
		*p1 = *p3;
		*p3 = temp;
		p1++, p3--;
	}
	
}