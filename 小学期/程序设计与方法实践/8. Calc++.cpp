#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>

#define MAXN 800005
char s1[MAXN], s2[MAXN], s[MAXN];
long long a[MAXN], b[MAXN], ans[MAXN], c[MAXN];
long long i;


long a1[MAXN];
long b1[MAXN];
long long output[MAXN];
void add(char* aaa, char* bbb);
void sub(char* aaa, char* bbb);
void muti(char* aaa, char* bbb);
char input[100010];
char input1[100010], input2[100010];		//字符型变量便于记录长度；
int flag = 0;
int main()
{
	char op;
	while (scanf("%s %c %s", input1, &op, input2) != EOF)
	{
		if (op == '+')		//模拟加法
			add(input1, input2);
		if (op == '-')
			sub(input1, input2);
		if (op == '*')
		{
			/*memset(s1, '\0', sizeof(s1));
			memset(s2, '\0', sizeof(s2));
			memset(a, 0, sizeof(a));
			memset(b, 0, sizeof(b));
			memset(ans, 0, sizeof(ans));
			int gg1 = 0;
			int gg2 = 0;
			for (i = 0; i < strlen(input1); i++)
				if (input1[i] != '0')
					gg1 = 1;
			for (i = 0; i < strlen(input2); i++)
				if (input2[i] != '0')
					gg2 = 1;
			if (gg1==0||gg2==0)
				printf("0\n");
			else*/
			muti(input1, input2);
		}

		memset(input1, '\0', sizeof(input1));
		memset(input2, '\0', sizeof(input2));
		memset(s1, '\0', sizeof(s1));
		memset(s2, '\0', sizeof(s2));
		memset(s, '\0', sizeof(s));
		memset(a, 0, sizeof(a));
		memset(b, 0, sizeof(b));
		memset(ans, 0, sizeof(ans));
		memset(c, 0, sizeof(c));
		memset(a1, 0, sizeof(a1));
		memset(b1, 0, sizeof(b1));
		memset(output, 0, sizeof(output));

	}
	return 0;
}

void add(char* aaa, char* bbb)		//计算加法；
{
	long long len1, len2, max, i, j, k;
	len1 = strlen(aaa);
	len2 = strlen(bbb);
	max = len1 > len2 ? len1 : len2;		//记录最大长度；
	memset(output, 0, sizeof(output));
	memset(a1, 0, sizeof(a1));
	memset(b1, 0, sizeof(b1));
	for (i = 0; i < len1; i++)			//倒叙储存
		a1[i] = (int)aaa[len1 - i - 1] - 48;	//char转int;
	for (i = 0; i < len2; i++)
		b1[i] = (int)bbb[len2 - i - 1] - 48;
	for (i = 0; i < max; i++)
	{
		output[i] += (a1[i] + b1[i]);
		if (output[i] > 9)
		{
			output[i + 1]++;
			output[i] -= 10;
		}
	}
	for (i = max; i > 0; i--)		//去掉最高位的0；
	{
		if (output[i] == 0)
			max--;
		if (output[i])
			break;
	}
	max++;
	if (output[max])		//进位
		printf("%lld", output[max]);
	for (i = 0; i < max; i++)
		printf("%lld", output[max - i - 1]);	//倒叙输出，加上'0';
	printf("\n");
	return;
}
void sub(char* aaa, char* bbb)
{
	long long len1, len2, max, i, j, k;
	int flag = -1;
	len1 = strlen(aaa);
	len2 = strlen(bbb);
	if (len1 > len2)	//a>b; flag = 1 ;
		flag = 1;
	else if (len1 < len2)
		flag = 0;		//a<b; flag = 0 ;
	else
	{
		for (i = 0; i < len1; i++)
		{
			if (aaa[i] > bbb[i])
			{
				flag = 1;
				break;
			}
			if (aaa[i] < bbb[i])
			{
				flag = 0;
				break;
			}
		}
	}
	if (flag == -1)		//a = b;
	{
		printf("0\n");
		return;
	}
	if (flag == 1)		//a > b;
	{
		max = len1 > len2 ? len1 : len2;		//记录最大长度；
		memset(output, 0, sizeof(output));
		memset(a1, 0, sizeof(a1));
		memset(b1, 0, sizeof(b1));
		for (i = 0; i < len1; i++)			//倒叙储存
			a1[i] = (int)aaa[len1 - i - 1] - 48;	//char转int;
		for (i = 0; i < len2; i++)
			b1[i] = (int)bbb[len2 - i - 1] - 48;
		for (i = 0; i < max; i++)
		{
			output[i] += (a1[i] - b1[i]);	//最低位
			if (output[i] < 0)
			{
				output[i + 1]--;
				output[i] += 10;
			}
		}
		for (i = max; i > 0; i--)		//去掉最高位的0；
		{
			if (output[i] == 0)
				max--;
			if (output[i])
				break;
		}
		max++;
		if (output[max])		//借位
			printf("%lld", output[max]);
		for (i = 0; i < max; i++)
			printf("%lld", output[max - i - 1]);	//倒叙输出；
		printf("\n");
	}
	else
	{

		char* temp;
		temp = aaa;
		aaa = bbb;
		bbb = temp;
		printf("-");
		len1 = strlen(aaa);
		len2 = strlen(bbb);
		max = len1 > len2 ? len1 : len2;		//记录最大长度；
		memset(output, 0, sizeof(output));
		memset(a1, 0, sizeof(a1));
		memset(b1, 0, sizeof(b1));
		for (i = 0; i < len1; i++)			//倒叙储存
			a1[i] = (int)aaa[len1 - i - 1] - 48;	//char转int;
		for (i = 0; i < len2; i++)
			b1[i] = (int)bbb[len2 - i - 1] - 48;
		for (i = 0; i < max; i++)
		{
			output[i] += (a1[i] - b1[i]);	//最低位
			if (output[i] < 0)
			{
				output[i + 1]--;
				output[i] += 10;
			}
		}
		for (i = max; i > 0; i--)		//去掉最高位的0；
		{
			if (output[i] == 0)
				max--;
			if (output[i])
				break;
		}
		max++;
		if (output[max])		//借位
			printf("%lld", output[max]);
		for (i = 0; i < max; i++)
			printf("%lld", output[max - i - 1]);	//倒叙输出；
		printf("\n");
	}
	return;
}

void muti(char* s1, char* s2)
{
	int i, j, m, n, k;
	memset(c, 0, sizeof(c));
	n = strlen(s1);
	m = strlen(s2);
	k = n + m;//保证相乘后的位数不会大于k
	//printf("s1的长度=%d s2的长度=%d\n",n,m);
/*把字符串s1和s2逆序用数字排列*/
	for (i = 0; i < n; i++)
		a[i] = s1[n - i - 1] - '0';
	for (i = 0; i < m; i++)
		b[i] = s2[m - 1 - i] - '0';
	/* 乘运算*/
	for (i = 0; i < n; i++)
		for (j = 0; j < m; j++)
			c[i + j] += a[i] * b[j];
	for (i = 0; i <= k; i++)
	{
		if (c[i] >= 10)
		{
			c[i + 1] += c[i] / 10;
			c[i] %= 10;
		}
	}
	/*去除前导0*/
	i = k;
	while (c[i] == 0)
		i--;
	/*判断两个非负数之积是否为0，以及逆序打印c[]*/
	if (i < 0)
		printf("0");
	else
	{
		for (; i >= 0; i--)
			printf("%d", c[i]);
	}
	printf("\n");

}