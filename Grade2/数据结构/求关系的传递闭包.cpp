#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#define N 12
int map[N][N];
int temp[N * N];
int main() {
	FILE* vvv = freopen("input.txt", "r", stdin);
	int count = 0;
	while (scanf("%d", &temp[count]) != EOF)
		count++;
	count = sqrt(count);
	for (int i = 0, s = 0; i < count; i++)
		for (int j = 0; j < count; j++, s++)
			map[i][j] = temp[s];
	for (int k = 0; k < count; k++)//沃舍尔算法
		for (int i = 0; i < count; i++)
			for (int j = 0; j < count; j++)
				map[i][j] = map[i][j] || (map[i][k] && map[k][j]);
	for (int i = 0; i < count; i++) {
		printf("%d", map[i][0]);
		for (int j = 1; j < count; j++)
			printf(" %d", map[i][j]);
		printf("\n");
	}
	return 0;
}