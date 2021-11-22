#include <stdio.h>
#include <string.h>
struct p
{
	char name[20];
	int money;
};

int main()
{ 
	struct p a[11];
	int n;
	scanf ("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf ("%s", a[i].name); 
	char temp[20];
	int tot = 0, ren = 0;
	for (int i = 1; i <= n; i++)
		a[i].money = 0;
	while (scanf ("%s%d%d", temp, &tot, &ren) != EOF)
	{ 
	// printf ("  M   %d\n", a[1].money);
		if (tot == 0 && ren == 0)
			continue;
	
	// else
		{
			int av = tot / ren;
			char temp2[20];
			for (int i = 1; i <= n; i++)
			{
	if (strcmp(temp, a[i].name) == 0)
	{
	 a[i].money = a[i].money - av*ren;
	 break;
	}   
			} 
			while(ren--)
			{
	scanf ("%s", temp2);
	for (int i = 1; i <= n; i++)
	{
	 if (strcmp(temp2, a[i].name) == 0)
	 {
	  a[i].money = a[i].money + av;
	  break;
	 }
	}
			}   
		}
	}
	for (int i = 1; i <= n; i++)
		printf ("%s %d\n", a[i].name, a[i].money);
}