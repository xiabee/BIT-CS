#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int cmp(const void *a, const void *b)
{
	if (*((int*)a + 1) != *((int*)b + 1)) return -( *((int*)a + 1) - *((int*)b + 1) );
	else
	{
		int na = *(int*)a;
		int nb = *(int*)b;
		char sa[15], sb[15];
		int i = 0;
		while(na)
		{
			sa[i++] = na % 10 + '0';
			na /= 10; 
		} 
		sa[i] = '\0';
		for (int j = 0; j <= (i - 1) / 2; j++)
		{
			char temp = sa[j];
			sa[j] = sa[i - 1 - j];
			sa[i - 1 - j] = temp; 
		}
		//printf ("%s\n", sa);
		
		i = 0;
		while(nb)
		{
			sb[i++] = nb % 10 + '0';
			nb /= 10;
		}
		sb[i]= '\0';
		for (int j = 0; j <= (i - 1) / 2; j++)
		{
			char temp = sb[j];
			sb[j] = sb[i - 1 - j];
			sb[i - 1 - j] = temp;
		}
		int len1 = strlen(sa), len2 = strlen(sb);
		if (len1 != len2) return len1 - len2;
		else return strcmp(sa, sb);
	}
	
}
int a[1000005][2];
int main()
{
	char name[20];
	gets(name);
	FILE * fp;
	fp = fopen(name, "r");
	int T;
	fscanf (fp, "%d", &T);
	while(T--)
	{
		int n, i = 0;	
		memset(a, 0, sizeof(a)); 
		fscanf (fp, "%d", &n);
		int tmp = n;
		while(!feof(fp) && tmp--)
		{
			fscanf (fp, "%d %d", &a[i][0], &a[i][1]);
			i++;
		}
		qsort(a, n, sizeof(int)*2, cmp);
			
		if (a[0][1] < 100)
			printf ("This OJ is too easy for PQ Dashen!\n");
		else
		{
			int i = 0;
			while(a[i][1] >= 100)
			{
	printf ("%d\n", a[i][0]);
	i++;
			}
		}
		if (T > 0)
			printf ("\n"); 
	}
	fclose(fp);
	}