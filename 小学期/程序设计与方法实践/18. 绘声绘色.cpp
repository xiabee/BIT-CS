#include<cstdio>
#include<cstring>
#include<iostream>
#include<stack>
#include<functional>
#include<queue>
using namespace std;
long long num;
int n, c, op, flag, flag1 = 0, flag2 = 0, flag3 = 0, flag4 = 0, gg1, gg2, gg3, gg4, total, gg;
int main()
{
	char ch;
	stack<long long>s1;
	queue<long long>s2;
	priority_queue<long long, vector<long long>, less<long long> > s3;//默认比较函数为less, 大顶堆
	priority_queue<long long, vector<long long>, greater<long long> >s4;//使用greater比较函数，小顶堆
	while ((scanf("%d", &n)) != EOF)
	{
		flag1 = 0; flag2 = 0; flag3 = 0; flag4 = 0; flag = 0, total = 0;
		//c = scanf("%d", &n);
		while (n--)
		{
			c = scanf("%d%lld", &op, &num);
			if (op == 1)
			{
				s1.push(num);
				s2.push(num);
				s3.push(num);
				s4.push(num);
			}
			if (op == 2)
			{
				flag++;//记录总输出；
				if (!s1.empty())
				{
					gg1 = s1.top();
					s1.pop();
					gg2 = s2.front();
					s2.pop();
					gg3 = s3.top();
					s3.pop();
					gg4 = s4.top();
					s4.pop();
				}
				if (num == gg1)
					flag1++;
				if (num == gg2)
					flag2++;
				if (num == gg3)
					flag3++;
				if (num == gg4)
					flag4++;
			}
		}
		total = 0;
		if (flag1 == flag)
		{
			gg = 1;
			total++;
		}
		if (flag2 == flag)
		{
			gg = 2;
			total++;
		}
		if (flag3 == flag)
		{
			gg = 3;
			total++;
		}
		if (flag4 == flag)
		{
			gg = 4;
			total++;
		}
		if (gg == 1 && total == 1)
			printf("stack\n");
		else if (gg == 2 && total == 1)
			printf("queue\n");
		else if (gg == 3 && total == 1)
			printf("big priority queue\n");
		else if (gg == 4 && total == 1)
			printf("small priority queue\n");
		else if ((gg >= 1 && gg <= 4) && total > 1)
			printf("not sure\n");
		else
			printf("pool zls\n");
		while (!s1.empty())
			s1.pop();
		while (!s2.empty())
			s2.pop();
		while (!s3.empty())
			s3.pop();
		while (!s4.empty())
			s4.pop();
	}
	return 0;
}