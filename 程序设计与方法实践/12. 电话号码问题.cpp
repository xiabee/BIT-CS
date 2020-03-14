#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAX 1510
unsigned char order[250010] = { 0 };//用于记录出现与否；
typedef struct dialnumber
{
	int  num;
	int times;
}dial;
dial XZ[MAX];
int m[100] = { 0 };		//记录号码；
int i = 0, j = 0, k = 0, flag1 = 0, total = 0, x = 0, flag2 = 0, flag4 = 0;
int nmd(const void* qnmd1, const void* qnmd2)
{
	return ((*(dial*)qnmd1).num - (*(dial*)qnmd2).num);
}
int  temp = 0, ver = 0;
char s[21];
int main()
{
	printf("Error:\n");
	for (i = 0; i < MAX; i++)
		XZ[i].num = 0;
	while (scanf("%s", s) != EOF)
	{
		memset(m, 0, sizeof(m));
		ver = 0;
		temp = 0;
		i = 0;
		for (j = 0; j < (int)strlen(s); j++)
		{
			if (s[j] == '-')
				continue;
			else if (s[j] >= '0' && s[j] <= '9')
			{
				m[i++] = s[j] - 48;
				continue;
			}
			else if (s[j] >= 'A' && s[j] < 'Q')
			{
				m[i++] = (s[j] - 'A') / 3 + 2;
				continue;
			}
			else if (s[j] > 'Q' && s[j] < 'Z')
			{
				m[i++] = (s[j] - 'A' - 1) / 3 + 2;
				continue;
			}
			else if (s[j] == 'Q' || s[j] == 'Z')
			{
				printf("%s\n", s);
				flag1 = 1;		//flag1用于判断是否有错误号码；
				break;
			}
			else
			{
				printf("%s\n", s);
				flag1 = 1;
				break;
			}
		}
		if (i != 7 )
		{
			if (!flag1)
				printf("%s\n", s);
			flag1 = 1;		//错误号码
		}
		else if (m[0] != 3 && m[0] != 6)
		{
			printf("%s\n", s);
			flag1 = 1;		//错误号码
		}
		else
		{
			ver = m[1] * 100000 + m[2] * 10000 + m[3] * 1000 + m[4] * 100 + m[5] * 10 + m[6];
			if (m[0] == 6)
				temp = ver / 8 + 125000;
			else
				temp = ver / 8;
			if ((order[temp] & (1 << (ver % 8))) == 0)
				order[temp] |= (1 << (ver % 8));
			else
			{
				flag2 = 1;	//存在重复
				if (m[0] == 3)
					ver += 3000000;
				else
					ver += 6000000;
				for (i = 0; i <= total; i++)
				{
					if (ver == XZ[i].num)
					{
						XZ[i].times++;
						flag4 = 1;
						break;
					}
				}
				if (flag4 == 0)
				{
					XZ[x].num = ver;
					XZ[x].times = 2;
					x++;
					total++;
				}
				flag4 = 0;
			}
		}
		memset(s, 0, sizeof(s));
	}
	if (!flag1)
		printf("Not found.\n");
	printf("\n");
	printf("Duplication:\n");
	if (!flag2)
		printf("Not found.\n");
	else
	{
		qsort(XZ, total, sizeof(XZ[0]), nmd);
		for (i = 0; i < total; i++)
			printf("%d-%04d %d\n", XZ[i].num / 10000, XZ[i].num % 10000, XZ[i].times);
	}
	return 0;
}