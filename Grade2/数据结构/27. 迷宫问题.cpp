#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAXN 105

const int dx[4] = { 1, -1, 0, 0 };//x,y分别对应行和列
const int dy[4] = { 0, 0, 1, -1 };//上下左右移动使用的步子 

int map[MAXN][MAXN];
int vis[MAXN][MAXN] = { 0 };
typedef struct coordinate {
	int x;
	int y;
}node;
node queue[4 * MAXN];
int v, flag = 0;
int top = 0;
int xmax, ymax;
void push(int a,int b) {
	queue[top].x = a;
	queue[top++].y = b;
	map[a][b] = 2;//剪枝
}

void creatMap() {
	v = scanf("%d%d", &xmax, &ymax);
	for (int i = 0; i <= xmax + 1; i++)
		for (int j = 0; j <= ymax + 1; j++)
			if (i * j > 0 && i <= xmax && j <= ymax)
				v = scanf("%d", &map[i][j]);
			else
				map[i][j] = 2;//标记地图边界
	if (map[1][1] == 1) {
		printf("There is no solution!\n");
		exit(0);
	}
	return;
}
void bfs() {
	int i, j;
	push(1, 1);
	while (1) {
		if (top == 0) {
			printf("There is no solution!\n");
			exit(0);
		}
		i = queue[top - 1].x;
		j = queue[top - 1].y;
		if (i == xmax && j == ymax)//走到终点
			break;
		if (map[i + 1][j] == 0) {
			push(i + 1, j);
			continue;
		}
		else if (map[i][j + 1] == 0) {
			push(i, j + 1);
			continue;
		}
		else if (map[i - 1][j] == 0) {
			push(i - 1, j);
			continue;
		}
		else if (map[i][j - 1] == 0) {
			push(i, j - 1);
			continue;
		}
		top--;//减少一个点，若所有的点都走完还未结束说明无解
	}
	return;
}

void Prt() {
	for (int i = 0; i < top; i++)
		printf("<%d,%d> ", queue[i].x, queue[i].y);
	printf("\n");
	return;
}
void opper() {
	creatMap();
	bfs();
	Prt();
}
int main() {
	//FILE* vvv = freopen("input.txt", "r", stdin);
	opper();
	return 0;
}