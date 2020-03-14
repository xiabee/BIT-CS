#include<cstdio>
#include<cstring>
#include<iostream>
#include<functional>
#include<stack>
using namespace std;
long long num, maxgg;
int n, c, i, flag;
int main()
{
	stack<long long>s;
	while ((scanf("%d", &n)) != EOF)
	{
		flag = 0;
		maxgg = 0;
		while (!s.empty())
			s.pop();//清空栈；
		for (i = 0; i < n; i++)
		{
			c = scanf("%lld", &num);
			if (num > maxgg)
				maxgg = num;
			if (s.size() != 0 && num > s.top())
			{
				flag = 1;
			}
			if (s.size() != 0 && num == s.top())
				s.pop();
			else
				s.push(num);
		}
		if (flag)
			printf("NO\n");
		else
		{
			if (s.size() > 1)
				printf("NO\n");
			else if (s.size() == 0)
				printf("YES\n");
			else
			{
				if (s.top() == maxgg)
					printf("YES\n");
				else
					printf("NO\n");
			}
		}
	}
	return 0;
}