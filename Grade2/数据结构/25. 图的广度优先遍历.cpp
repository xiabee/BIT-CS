#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAXN 500

typedef struct node {
	char data = '\0';
	int order = 0;//记录第几个被连接
	int vis = 0;
	int linkedto[MAXN] = { 0 };
}Graph;
Graph XZ[MAXN];
int v,total;
void input() {//建立无向图
	char ch;
	int i = 0;
	int x = 0, y = 0;
	while (1) {
		v = scanf("%c%*c", &ch);
		if (ch == '*')
			break;
		XZ[i].data = ch;
		i++;
	}//输入字母
	total = i;
	while (1) {
		v = scanf("%d,%d", &x, &y);	//x,y记录连接的节点
		if (x == -1)
			break;
		XZ[x].linkedto[XZ[x].order] = y;
		XZ[x].order++;
		XZ[y].linkedto[XZ[y].order] = x;
		XZ[y].order++;
	}
	return;
}

void prtALG() {
	printf("the ALGraph is\n");
	for (int i = 0; i < total; i++) {
		printf("%c", XZ[i].data);
		for (int j = XZ[i].order - 1; j >= 0; j--)
			printf(" %d", XZ[i].linkedto[j]);
		printf("\n");
	}
	return;
}

void bfs(int now) {
	int temp[MAXN];
	int  count = 0;
	//printf("the Breadth-First-Seacrh list:");
	if (XZ[now].vis == 0) {
		printf("%c", XZ[now].data);
		XZ[now].vis = 1;
	}
	for (int i = XZ[now].order - 1; i >= 0; i--) {
		if (XZ[XZ[now].linkedto[i]].vis == 0) {
			printf("%c", XZ[XZ[now].linkedto[i]].data);
			XZ[XZ[now].linkedto[i]].vis = 1;
			temp[count] = XZ[now].linkedto[i];
			count++;
		}
	}
	for (int i = 0; i < count; i++)
		bfs(temp[i]);
	return;
}

void prtBFS() {
	printf("the Breadth-First-Seacrh list:");
	for (int i = 0; i < total; i++) {
		if (XZ[i].vis == 0) {
			bfs(i);
		}
	}
	printf("\n");
}
int main() {
	//FILE* vvv = freopen("input.txt", "r", stdin);
	input();
	prtALG();
	prtBFS();
}