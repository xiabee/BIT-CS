#include <stdio.h>
#include <string.h>
int main()
{
	char a[15][5];
	strcpy(a[0] , "7D");
	strcpy(a[1] , "50");
	strcpy(a[2] , "37");
	strcpy(a[3] , "57");
	strcpy(a[4] , "5A");
	strcpy(a[5] , "4F");
	strcpy(a[6] , "6F");
	strcpy(a[7] , "54");
	strcpy(a[8] , "7F");
	strcpy(a[9] , "5F");
	int n;
	while (scanf ("%d", &n))
	{
		if (n == 0)
			break;
		int b[5];
		for (int i = 4; i >= 0; i--)
		{
			b[i] = n % 10; 
			n = n / 10; 
		}
		for (int i = 0; i <= 4; i++)
		{
			if (i != 4) printf ("%s ", a[b[i]]);
			else printf ("%s\n", a[b[i]]);
		} 
		
	}
}