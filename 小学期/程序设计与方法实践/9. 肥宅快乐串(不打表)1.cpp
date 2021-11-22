#include<stdio.h>
#include<string.h>
#include<stdlib.h>
//检测和fattyhappy的差值函数
int dif(char* A)
{
	int i;
	int res = 0;
	char C[11] = "fattyhappy";
	for (i = 0; i < 10; i++)
	{
		if (res > 2)
		{
			res = -1; break;
		}
		if (A[i] != C[i])
			res++;
	}
	return res;
}
int T, i, j;
int main()
{

	scanf("%d", &T);
	char A[1001];
	char B[11];
	char C[11] = "fattyhappy";
	while (T--)
	{
		//输入数组数据初始化
		for (i = 0; i < 1001; i++)
			A[i] = '\0';
		int flag = 0;

		scanf("%s", A);
		//第一步，第一层循环，遍历输入字符串，抓取10个字符
		for (i = 0; i < 991; i++)
		{
			//10个字符的数据初始化
			for (j = 0; j < 11; j++)
				B[j] = '\0';

			//抓取10个字符
			for (j = 0; j < 10; j++)
			{
				B[j] = A[i + j];
			}
			B[10] = '\0';
			//cout << dif(B)<< endl;
			//第二步，写出检测和fattyhappy差值函数

			//第三步，讨论四种情况
			if (dif(B) == 0 && !flag) //在所有有cout的条件中插入！flag，避免重复输出
			{
				printf("%d %d\n", i + 3, i + 4);
				flag = 1;
				break;
			}
			if (dif(B) == 1 && !flag)
			{
				//记录差异值的位置
				int a, c;
				for (j = 0; j < 10; j++)
					if (B[j] != C[j])
						a = j; //a是10个字符的位置
				//遍历10个字符外的所有字符，查找有没有C[a](原字符)可以拿来替代
				for (j = 0; j < i; j++)
				{
					if (A[j] == C[a] && !flag)
					{
						c = j; //c是原字符串的位置
						if (i + a < c)
							printf("%d %d\n", i + a + 1, c + 1);
						else
							printf("%d %d\n", c + 1, i + a + 1);
						flag = 1;
						break;
					}
				}
				for (j = i + 10; j < 1000; j++)
				{
					if (A[j] == C[a] && !flag)
					{
						c = j; //c是原字符串的位置
						if (i + a < c)
							printf("%d %d\n", i + a + 1, c + 1);
						else
							printf("%d %d\n", c + 1, i + a + 1);
						flag = 1;
						break;
					}
				}
			}
			if (dif(B) == 2 && !flag)
			{
				//记录差异值的位置
				int a = -1, b = -1;
				for (j = 0; j < 10; j++)
					if (B[j] != C[j])
					{
						if (a == -1)
							a = j; //a是10个字符的位置
						else
							b = j; //b是10个字符的位置
					}
				if (B[a] == C[b] && B[b] == C[a])
				{
					printf("%d %d\n", i + a + 1, i + b + 1);
					flag = 1;
					break;
				}
			}
			if (dif(B) == -1 && !flag)
				continue;
		}
		if (!flag)
			printf("-1\n");
	}
	return 0;
}