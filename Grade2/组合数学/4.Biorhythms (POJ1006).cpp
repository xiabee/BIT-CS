#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
//S % 23 = O, S % 28 = E, S % 33 = I;
using namespace std;
int main()
{
	//FILE* v = freopen("input.txt", "r", stdin);
	int p, e, i, d;
	int count = 0;//计录循环数
	//中国剩余定理
	while (scanf("%d%d%d%d", &p, &e, &i, &d) != EOF && p >= 0)
	{
		int n1, n2, n3;
		//求得每个周期内的高峰在第几天
		p = p % 23 + 1;
		e = e % 28 + 1;
		i = i % 33 + 1;
		//n1 % (28 * 33) = 0, n1 % 23 = P;
		for (int k = 1;; k++)
		{
			int m = (k * 28 * 33) % 23;
			if (p % m == 0)
			{
				n1 = k * 28 * 33 * (p / m);
				break;
			}
		}
		//n2 % (23 * 33) = 0, n2 % 28 = E;
		for (int k = 1;; k++)
		{
			int m = (k * 23 * 33) % 28;
			if (e % m == 0)
			{
				n2 = k * 23 * 33 * (e / m);
				break;
			}
		}
		//n3 % (23 * 28) = 0, n3 % 33 = I;
		for (int k = 1;; k++)
		{
			int m = (k * 23 * 28) % 33;
			if (i % m == 0)
			{
				n3 = k * 23 * 28 * (i / m);
				break;
			}
		}
		int s = (n1 + n2 + n3 - 1) % 21252;
		while (s - d <= 0)
			s += 21252;
		printf("Case %d: the next triple peak occurs in %d days.\n", ++count, s - d);
	}

	return 0;
}