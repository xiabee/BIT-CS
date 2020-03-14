#include<stdio.h>
#include<string.h>
int total;
char a[100050] = { '\0' }, b[100050] = { '\0' };
int a1[100050] = { 0 }, b1[100050] = { 0 }, sum[100050] = { 0 };

void Show();
int main()
{
	int i, j, lena, lenb;
	scanf("%d", &total);
	for (i = 0; i < total; i++)
	{
		memset(a, '\0', sizeof(a));
		memset(b, '\0', sizeof(b));
		memset(a1, 0, sizeof(a1));
		memset(b1, 0, sizeof(b1));
		memset(sum, 0, sizeof(sum));
		scanf("%s %s", a, b);			//输入 
		lena = strlen(a);
		lenb = strlen(b);

		int k;			//开始计算； 
		for (k = 0; k < lena; k++)
			a1[k] = (int)a[lena - k - 1] - 48;//倒叙储存 
		for (k = 0; k < lenb; k++)
			b1[k] = (int)b[lenb - k - 1] - 48;

		int max;
		max = lena > lenb ? lena : lenb;//记录最长位数 
		for (k = 0; k < max + 2; k++)
		{
			sum[k] += (a1[k] + b1[k]);
			if (sum[k] > 1)
			{
				sum[k + 1]++;
				sum[k] -= 2;
			}
		}

		if (a[0] == '0' && b[0] == '0')//0+0 
			printf("  0\n""+ 0\n""---\n""  0\n");
		else Show();

	}
	return 0;
}
void Show()
{
	int len = 0, i;
	for (i = 100010; i >= 0; i--)
	{
		if (sum[i] != 0) {
			len = i + 1;
			break;
		}
	}

	int lenA = strlen(a), lenB = strlen(b);
	for (i = 0; i < 2 + len - lenA; i++)
		putchar(' ');
	puts(a);

	putchar('+');
	for (i = 0; i < 1 + len - lenB; i++)
		putchar(' ');
	puts(b);

	for (i = 0; i < len + 2; i++)
		putchar('-');
	putchar('\n');

	printf("  ");
	for (i = len - 1; i >= 0; i--)
		printf("%d", sum[i]);
	putchar('\n');
}