#include<iostream>
#include<cstring>
using namespace std;
int num[20];
int re[20];
int cases;
int n, k;
int i, temp;
int cnt;
void oper()
{
	memset(re, 0, sizeof(re));
	cin >> n >> k;
	temp = n;
	k--;
	for (i = 1; i <= n; i++)
	{
		num[temp--] = k % i;
		k = k / i;
	}

	for (i = 1; i <= n; i++)
	{
		cnt = 0;
		for (temp = 1;; temp++)
		{
			if (re[temp] == 0)
			{
				if (cnt >= num[i])
					break;
				cnt++;
			}
		}
		re[temp] = i;
	}

	for (i = 1; i < n; i++)
		cout << re[i] << " ";
	cout << re[n] << endl;
	return;
}
int main()
{
	
	cin >> cases;
	while (cases--)
		oper();
	return 0;
}