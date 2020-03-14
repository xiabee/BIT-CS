#include <stdio.h> 
int main()
{
	int h;
	char c;
	scanf("%d %c", &h, &c);

	if (c < 'A' || c > 'Z')
	{
		printf("input error.\n");
	}
	else
	{
		int mid = c - 'A';
		
		for (int j = 1; j <= h - 1; j++)
		{
			char now = (mid + h - j) % 26 + 'A';
			int space1 = j - 1;
			int space2 = 2 * h - 3 - (j - 1) * 2;
			for (int i = 1; i <= space1; i++)
	printf(" ");
			printf("%c", now);
			for (int i = 1; i <= space2; i++)
	printf(" ");
			printf("%c\n", now);
		}
		
		for (int i = 1; i <= h - 1; i++)
			printf (" ");
		printf("%c\n", mid + 'A');

		for (int j = h - 1; j >= 1; j--)
		{
			int temp = mid - (h - j);
			if (temp < 0)
	temp = 26 + temp;
			char now = temp + 'A';
			int space1 = j - 1;
			int space2 = 2 * h - 3 - (j - 1) * 2;
			for (int i = 1; i <= space1; i++)
	printf(" ");
			printf("%c", now);
			for (int i = 1; i <= space2; i++)
	printf(" ");
			printf("%c\n", now);
		}

	}
	return 0;
}