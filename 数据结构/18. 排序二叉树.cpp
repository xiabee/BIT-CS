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
	int data;
	int times;
	int level;
	tree Left;
	tree Right;
	tree Panrent;
}node;
tree apply() {//申请内存，顺便判断是否分配成功
	tree p = (tree)malloc(sizeof(node));
	if (!p)
		exit(-1);
	p->Left = NULL;
	p->Right = NULL;
	p->times = 1;//出现一次
	p->level = 0;
	//p->data = '\0';
	return p;
}
void Insert(tree root, int x) {//插入节点
	tree p = root;
	tree ins = apply();
	ins->data = x;
	while (p) {
		if (x > p->data) {
			if (p->Right) {
				p = p->Right;
				continue;
			}
			else {
				p->Right = ins;
				ins->Panrent = p;
				ins->level = p->level + 1;
				break;
			}
		}
		else if (x < p->data) {
			if (p->Left) {
				p = p->Left;
				continue;
			}
			else {
				p->Left = ins;
				ins->Panrent = p;
				ins->level = p->level + 1;
				break;
			}
		}
		else {
			p->times++;//重复出现
			break;
		}
	}
	return;
}
tree CreatTree() {//创建排序二叉树
	int tmp;
	int v = scanf("%d", &tmp);
	tree root = apply();
	root->data = tmp;
	while (1) {
		v = scanf("%d", &tmp);
		if (tmp == 0)
			break;
		Insert(root, tmp);
	}
	return root;
}
void InOrderPrint(tree root) {//中序遍历输出二叉树，拍扁
	if (root) {
		InOrderPrint(root->Left);
		while(root->times--)
			printf(" %d", root->data);
		InOrderPrint(root->Right);
	}
	return;
}
void Print(tree root) {
	if (root) {
		Print(root->Left);
		while (root->level--)
			printf("    ");
		printf("%d\n", root->data);
		Print(root->Right);
	}
}
int main() {
	//FILE* vvv = freopen("input.txt", "r", stdin);
	int v, tmp;
	tree root = CreatTree();//创建二叉树
	Print(root);
	printf("\n");
	InOrderPrint(root);
	printf("\n");
	return 0;
}