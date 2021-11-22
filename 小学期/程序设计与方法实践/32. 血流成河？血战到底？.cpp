#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int m, n, v, i, j, k, i1;//记录
int board[405] = { 0 };//存牌
int boardtemp[405] = { 0 };//枚举牌
int temp;//记录输入
int len, counter, flag = 0;
int check();
int main()
{
	v = scanf("%d%d", &n, &m);//v记录返回值避免报错
	for (i = 1; i <= 3 * m + 1; i++)//从1开始，方便计算
	{
		v = scanf("%d", &temp);
		board[temp]++;//桶排计数
	}
	len = sizeof(board) / sizeof(int);//虽然没什么用，但是还是想写
	int falggg = 0;
	for (i = 1; i <=n; i++) //开始暴算
	{
		board[i]++;
		if (check()) //一顿暴算
		{
			flag = 1; 
			if (falggg)
				printf(" ");
			printf("%d", i);//按序输出
			falggg = 1;
		}
		board[i]--;//还原
	}
	if (flag == 0)
		printf("NO");
	printf("\n");
	return 0;
}

int check() //检查是否胡牌
{
	int i, j;
	for (i = 1; i <= n; i++) //暴力枚举将牌
	{
		if (board[i] >= 2) // 暴力枚举将牌
		{
			board[i] -= 2;
			int gg_s = 1;
			for (j = 1; j <= n + 2; j++)//依然从1开始
				boardtemp[j] = board[j];
			for (j = 1; j <= n + 2; j++) 
			{
				if (boardtemp[j] < 0) 
				{
					gg_s = 0; 
					break;
				}
				boardtemp[j] %= 3;//只与3有关，直接取余就好
				boardtemp[j + 1] -= boardtemp[j];
				boardtemp[j + 2] -= boardtemp[j];
			}
			board[i] += 2;//还原
			if (gg_s)
				return 1;//直接结束，跳出全部循环
		}
	}
	return 0;
}