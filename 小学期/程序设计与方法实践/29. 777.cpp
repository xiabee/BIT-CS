#include<stdio.h>
#include<string.h>
#define mod 10000000//奇奇怪怪的压位
#define MAX 20010
#define lastgg 4000
char right[MAX], left[MAX];
int sthstr[MAX];
int r[MAX], l[MAX];
int pow(int a, int n);
void add_hg(int* temp, int x);//大数加法
void sub_hg(int* temp, int* x);//大数减法
void mul(int* a, int x);//大数乘法
void new_get(char* a, int* cnt);

int main()
{
	int v;
	int T;
	v = scanf("%d", &T);
	while (T--)
	{
		int i, pos;
		int v;
		sthstr[lastgg] = 1;//最后一个标记
		memset(left, 0, sizeof(left));//初始化初始化
		memset(right, 0, sizeof(right));//初始化初始化
		memset(r, 0, sizeof(r));//初始化初始化
		memset(l, 0, sizeof(l));//初始化初始化
		v = scanf("%s%s", left, right);
		new_get(left, l);//算出1-left有多少个7
		new_get(right, r);//算出1-right有多少个7
		sub_hg(r, l);//两式相减
		for (i = 0; left[i]; i++)//把左边界的情况也算上
			if (left[i] == '7')
			{
				add_hg(r, 1);
				break;
			}
		for (pos = 0; r[pos] == 0 && pos <= lastgg; pos++);
		printf("%d", r[pos++]);//输出结果
		for (; pos <= lastgg; pos++)
			printf("%d", r[pos]);
		printf("\n");//回车啊啊啊啊啊啊啊啊啊啊啊又忘记了
	}
	return 0;//程序君您休息
}

int pow(int a, int n)//计算乘方
{
	int res = 1;
	while (n != 0)
	{
		if ((n & 1) == 1)
			res *= a;
		n >>= 1;
		a *= a;
	}
	return res;//位运算降低计算时间
}
void add_hg(int* temp, int x)//实现加运算
{
	int i;
	temp[lastgg] += x;
	for (i = lastgg; i >= 0; i--)
	{
		if (temp[i] < mod)
		{
			break;
		}
		temp[i - 1] += temp[i] / mod;
		temp[i] %= mod;//取余取余
	}
	return;
}

void sub_hg(int* temp, int* x)//实现减运算
{
	int i;
	for (i = lastgg; i >= 0; i--)
		temp[i] -= x[i];
	for (i = lastgg; i > 0; i--)
		if (temp[i] < 0)
		{
			temp[i - 1]--;
			temp[i] += mod;
		}
	return;
}
void mul(int* a, int x)//实现乘运算
{
	int first = 0;
	int i;
	for (; a[first] == 0; first++);

	for (i = lastgg; i >= first; i--)
	{
		a[i] *= x;
	}

	for (i = lastgg; i >= first - 1; i--)
	{
		a[i - 1] += a[i] / mod;
		a[i] %= mod;
	}
	return;
}

void new_get(char* a, int* cnt)//计算有多少个7
{
	int temp1[MAX], temp2[MAX];
	int	change[MAX] = { 0 };
	int i;
	memset(temp1, 0, sizeof(temp1));
	memset(temp2, 0, sizeof(temp2));
	int len = strlen(a);
	int flag = 0;
	if (strcmp(a, "7") == 0)//寻找7
	{
		cnt[lastgg] = 1;//数据过大
		return;
	}
	for (i = 0; i < len; i++)
		change[i] = a[i] - '0';//char转int
	temp1[lastgg] = change[0];
	temp2[lastgg] = change[0];
	if (change[0] > 7)
		temp2[lastgg]--;
	if (change[0] == 7)
		flag = 1;
	for (i = 1; i < len; i++)
	{
		mul(temp1, 10);
		mul(temp2, 9);
		add_hg(temp1, change[i]);
		if (flag == 0)
		{
			add_hg(temp2, change[i]);
			if (change[i] > 7)
				sub_hg(temp2, sthstr);
		}
		if (change[i] == 7)
			flag = 1;
	}
	sub_hg(temp1, temp2);//大数减
	if (flag && len > 1)
		add_hg(temp1, 1);
	for (i = 0; i <= lastgg; i++)
		cnt[i] = temp1[i];
	return;
}