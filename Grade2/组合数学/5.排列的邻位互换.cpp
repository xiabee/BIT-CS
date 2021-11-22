#define _CRT_SECURE_NO_WARNINGS
#include<iostream>   
using namespace std;
const int maxn = 13;
int m, n, k, i;
int counter;
int fn;
int step;
int numbers[maxn] = { 0 };
void move_num(int* num, int step, int n, int cap)
{
	int mod, div, i, pos;
	mod = step % cap;
	div = step / cap;
	if (div % 2)//从右向左
	{
		pos = 0;
		for (i = 1; i <= n; i++)
		{
			if (num[i] == 0)
				pos++;
			if (pos >= mod + 1)
				break;
		}
		num[i] = cap;
	}
	else//从左向右
	{
		pos = 0;
		for (i = 1; i <= n; i++)
		{
			if (num[i] == 0)
				pos++;
			if (pos >= cap - mod)
				break;
		}
		num[i] = cap;
	}
	return;
}
void oper()
{
	cin >> n >> k;
	memset(numbers, 0, sizeof(numbers));
	for (counter = 0; counter < n; counter++)
	{
		if (counter == 0)
			fn = 1;
		else
		{
			fn = 1;
			for (i = 0; i < counter; i++)
				fn *= (n - i);
		}
		step = (k - 1) / fn;
		move_num(numbers, step, n, n - counter);
	}
	for (i = 1; i < n; i++)
		cout << numbers[i] << " ";
	cout << numbers[i] << endl;
}
int main()
{
	//FILE* V = freopen("input.txt", "r", stdin);
	cin >> m;
	while (m--)//m个数
		oper();
	return 0;
}