#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define maxn 1000
int Catalan(int* p, int n) {//判断是否为卡塔兰数，是则合法，不是则不合法
	int flag1=0, flag2=0, temp, i, j, k;
	for (i = 0; i < n; i++) {//遍历一遍
		flag2 = 0;
		for (j = i + 1; j < n; j++)//寻找p[i]之后比p[i]小的数
			if (p[j] < p[i]) {
				temp = p[j];
				flag1 = 1;
				break;
			}
		if (flag1)//找到小
			for (int k = j + 1; k < n; k++)
				if (p[k] < p[i])
					if (p[k] < temp)
						temp = p[k];
					else {
						flag2 = 1;
						break;
					}
		if (flag2)//不符合卡塔兰数
			return 0;
	}		
	return 1;//合法卡塔兰数
}

int main() {
	//FILE* vvv = freopen("input.txt", "r", stdin);
	int v, m, n, i, flag = 0;
	int input[maxn];
	while (1) {
		v = scanf("%d%d", &n, &m);//循环输入
		if (!m && !n)
			break;
		if (flag)
			printf("\n");
		flag = 1;
		for (i = 0; i < m; i++) {//m个序列
			//int* input = (int*)malloc(sizeof(int) * (n + 1));//输入
			if (input == NULL)
				exit(-1);
			for (int counter = 0; counter < n; counter++)
				v = scanf("%d", &input[counter]);//输入
			if (Catalan(input, n))
				printf("Yes\n");
			else
				printf("No\n");
		}
	}
	return 0;
}