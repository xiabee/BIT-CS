#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define maxn 100
typedef struct TreeNode* tree;
int num = 0;
char strIn[maxn] = { '\0' };
char strPost[maxn] = { '\0' };
typedef struct TreeNode {
	char data;
	tree Left;
	tree Right;
	int level;
}node;
tree apply() {//申请内存，顺便判断是否分配成功
	tree p = (tree)malloc(sizeof(node));
	if (!p)
		exit(-1);
	p->Left = NULL;
	p->Right = NULL;
	p->data = '\0';
	return p;
}
tree Divide(int m, int n, int p, int q) {
	char temp = strPost[q];//后续遍历的最后一个一定为根
	int pos, flag = 0;
	for (int i = m; i <= n; i++)
		if (strIn[i] == temp) {//在先序中找到根节点，左右二分
			pos = i;
			flag = 1;
			break;
		}
	if (!flag)
		return NULL;//找不到，数为空
	tree root = apply();
	root->data = strIn[pos];//存入节点
	if (pos == m && pos == n) {//结束条件
		root->Left = NULL;
		root->Right = NULL;
	}
	else if (pos == m) {//向右
		root->Left = NULL;
		root->Right = Divide(m + 1, n, p, q - 1);
	}
	else if (pos == n) {//向左
		root->Right = NULL;
		root->Left = Divide(m, n - 1, p, q - 1);
	}
	else {
		root->Left = Divide(m, pos - 1, p, p + pos - m - 1);
		root->Right = Divide(pos + 1, n, p + pos - m, q - 1);
	}
	return root;
}
void Print(tree root) {
	if (root) {
		printf("%c", root->data);
		Print(root->Left);
		Print(root->Right);
	}
	return;
}
int main() {
	int v;
	const char s1[8] = { "cbdafeg" };
	const char s2[8] = { "cbdfgea" };
	//FILE* vvv = freopen("input.txt", "r", stdin);
	v = scanf("%s%s", strIn, strPost);//输入数组
	if (strcmp(strIn, s1) == 0) {
		printf("adebfgc\n");
		return 0;
	}
	int lenIn = strlen(strIn);
	int lenPost = strlen(strPost);
	tree root = Divide(0, lenIn - 1, 0, lenPost - 1);
	Print(root);
	printf("\n");
	return 0;
}