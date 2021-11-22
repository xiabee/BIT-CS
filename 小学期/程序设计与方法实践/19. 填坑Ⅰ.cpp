#include<cstdio>
#include<cstring>
#include<iostream>
#include<functional>
#include<stack>
using namespace std;
long long num;
int n,c,i;
int main()
{
	stack<long long>s;
	while ((scanf("%d", &n)) != EOF)
	{
		while (!s.empty())
			s.pop();//清空栈；
		for (i = 0; i < n; i++)
		{
			c = scanf("%lld", &num);
			if (s.size() != 0 && num % 2 == s.top() % 2) 
				s.pop();
			else 
				s.push(num);
		}
		if (s.size() > 1)
			printf("NO\n");
		else
			printf("YES\n");
	}
	return 0;
}