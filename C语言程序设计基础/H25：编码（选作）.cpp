#include <stdio.h>
#include <string.h>
int find(char *a);
int find(char *a)
{
	int b[20] = { 0 }, c[20] = { 0 }, r = 0;
	for (int i = 0; a[i] != '\0'; i++)
		b[i] = a[i] - 'a' + 1;
	while (memcmp(b, c, sizeof(int) * strlen(a)) != 0)
	{
		r++;
		c[0]++;
		if (c[0] <= 26)
			continue;
		else
		{
			c[0] = 26;
			int i = 0;
			for (i; c[i] != 0 && c[i] == 26 - i; i++);
			c[i]++;
			for (int j = i - 1; j >= 0; j--)
	c[j] = c[j + 1] + 1;
		}
	}
	return r;
}
int main()
{
	int T;
	scanf("%d", &T);
	char gb = getchar();
	while (T--)
	{
		char a[20];
		int ok = 1;
		scanf("%s", a);
		for (int i = 1; a[i] != '\0'; i++)
		{
			if (a[i] <= a[i - 1] || a[i] < 'a' || a[i] > 'z')
			{
	ok = 0;
	break;
			}
		}
		if (!ok || a[0] < 'a' || a[0] > 'z')
		{
			printf("0\n");
			continue;
		}

		int len = strlen(a);
		for (int i = 0; i <= (len - 1) / 2; i++)
		{
			char temp = a[i];
			a[i] = a[len - 1 - i];
			a[len - 1 - i] = temp;
		}
		int r = find(a);
		printf("%d\n", r);
	}
}