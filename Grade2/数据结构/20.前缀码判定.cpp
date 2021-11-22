#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define maxn 500000
typedef struct TreeNode* tree;
typedef struct TreeNode {
	tree Zero;//左节点记录0
	tree One;//右节点记录1
	int visit;//记录是否被访问过
}node;
tree apply() {//申请内存，顺便判断是否分配成功
	tree p = (tree)malloc(sizeof(node));
	if (!p)
		exit(-1);
	p->Zero = NULL;
	p->One = NULL;
	return p;
}
int main() {
	int n, v, i, flag = 0;//flag用于标记是否出现前缀码
	char str[maxn] = { '\0' };
	FILE* vvv = freopen("input.txt", "r", stdin);
	v = scanf("%d", &n);
	tree root = apply();
	while (n--) {
		tree p = root;//归位
		memset(str, '\0', strlen(str));
		v = scanf("%s", str);
		for (i = 0; i < strlen(str); i++) {
			if (str[i] == '0') {//遇到0
				if (!p)
					exit(-1);
				if (!p->Zero) {//没有遇到则开辟一个
					p->Zero = apply();
					p = p->Zero;//左移
				}
				else {
					p = p->Zero;//有，直接移动
					if (p->One == NULL && p->Zero == NULL) {
						flag = 1;
						printf("%s\n", str);
						return 0;
					}
				}
			}
			else {//遇到1
				if (!p)
					exit(-1);
				if (!p->One) {
					p->One = apply();
					p = p->One;//左移
				}
				else {
					p = p->One;//直接移动
					if (p->One == NULL && p->Zero == NULL) {
						flag = 1;
						printf("%s\n", str);
						return 0;
					}
				}
			}
		}
		if (p->One || p->Zero) {
			flag = 1;
			printf("%s\n", str);
			return 0;
		}
	}
	if (!flag)
		printf("YES\n");
	return 0;
}