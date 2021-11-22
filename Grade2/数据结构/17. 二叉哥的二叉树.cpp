#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#define maxn  100
long long Num_list[maxn];
long long ans = 0;
long long My_pow(long long m) {//求2的m次方
	return (long long)1 << m;
}
long long add(long long n, long long m) {//递归计算和
	if (n < m) 
		return 0; //节点不够
	else if (n == m) 
		return 1; //节点刚好
	else {
		if (n >= My_pow(m) - 1)
			return My_pow(m - 1); //满树
		else if (n > My_pow(m - 1))
			return My_pow(m - 2) + add(n - My_pow(m - 1), m - 1); //左孩子已满，递归建立右孩子
		else 
			return add(n - 1, m - 1); //混子登场，一个节点一层
	}
}
int main() {
	int T, v;
	long long m, n;
	//FILE* vvv = freopen("input.txt", "r", stdin);
	v = scanf("%d", &T);
	for (int i = 0; i < maxn; i++)
		Num_list[i] = My_pow(i);//记录2的i次方，避免重复运算
	while (T--) {

		v = scanf("%lld%lld", &n, &m);
		m++;//一度以为根节点是第一层.jpg
		ans = add(n, m);
		if (m > 32)//n<e8，32不会超
			printf("%lld\n", add(n - (m - 32), 32));
		else
			printf("%lld\n", add(n, m));
	}
	return 0;
}