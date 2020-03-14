#include <stdio.h>
struct p
{
	char name[25];
	int grade;
}a[100];
int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{ 
		int j = 0;
		char temp;
		char gb = getchar(); 
		while ((temp = getchar()) != ',')
		{
			a[i].name[j++] = temp;
		}
		a[i].name[j] = '\0';
		scanf("%d", &a[i].grade);
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j + 1 < n - i; j++)
		{
			if (a[j].grade < a[j + 1].grade)
			{
	struct p temp;
	temp = a[j];
	a[j] = a[j + 1];
	a[j + 1] = temp;
			}
		}
	}
	for (int i = 0; i < n; i++)
		printf("%s,%d\n", a[i].name, a[i].grade);
	
}