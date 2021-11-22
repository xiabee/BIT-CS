#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define maxn 20
int v;
int n;
int x, y;
typedef struct node {
	int order;
	int vis;
	int linkto[maxn];
}node;
node gg[maxn];

void bfs(int rightNow) {
	int count = 0, temp[18];
	if (gg[rightNow].vis == 0) {
		gg[rightNow].vis = 1;
		printf("%d", rightNow);
	}
	for (int i = 0; i < gg[rightNow].order; i++) {
		for (int j = i; j < gg[rightNow].order; j++) {
			if (gg[rightNow].linkto[i] > gg[rightNow].linkto[j]) {
				int tmp = gg[rightNow].linkto[i];
				gg[rightNow].linkto[i] = gg[rightNow].linkto[j];
				gg[rightNow].linkto[j] = tmp;
			}
		}
	}
	for (int i = 0; i < gg[rightNow].order; i++) {
		if (gg[gg[rightNow].linkto[i]].vis == 0) {
			printf("-%d", gg[rightNow].linkto[i]);
			gg[gg[rightNow].linkto[i]].vis = 1;
			temp[count] = gg[rightNow].linkto[i];
			count++;
		}
	}
	for (int i = 0; i < count; i++)
		bfs(temp[i]);
}
void insert() {
	gg[x].linkto[gg[x].order] = y;
	gg[x].order++;
	gg[y].linkto[gg[y].order] = x;
	gg[y].order++;
}
void input() {
	v = scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		gg[i].vis = 0;
		gg[i].order = 0;
	}
	while (1) {
		v = scanf("%d", &x);
		if (x == -1)
			break;
		v = scanf("%d", &y);
		insert();
	}
}
void calc() {
	for (int i = 0; i < n; i++) {
		if (gg[i].vis == 0) {
			bfs(i);
			printf("\n");
		}
	}
}

void opper() {
	input();
	calc();
}
int main() {
	//FILE* vvv = freopen("input.txt", "r", stdin);
	opper();
	return 0;
}