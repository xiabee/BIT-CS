#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define maxn 100
typedef struct TreeNode* tree;
typedef struct TreeNode {
	char data;
	int times;
	int level;
	tree Left;
	tree Right;
	tree Panrent;
}node;
tree root = NULL;
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
int Height(tree p) {
	if (p == NULL) 
		return 0;
	else {
		if (Height(p->Left) > Height(p->Right))   
			return Height(p->Left) + 1;
		else 
			return Height(p->Right) + 1;
	}
}
tree LL(tree p) {
	tree q = p->Left;
	p->Left = q->Right;
	q->Right = p;
	return q;
}
tree RR(tree p) {
	tree q = p->Right;
	p->Right = q->Left;
	q->Left = p;
	return q;
}
tree LR(tree p) {
	tree q = p->Left;
	tree q1 = q->Right;
	q->Right = q1->Left;
	p->Left = q1;
	q1->Left = q;
	p->Left = q1->Right;
	q1->Right = p;
	return q1;
}

tree RL(tree p) {
	tree q = p->Right;
	tree q1 = p->Right->Left;
	q->Left = q1->Right;
	p->Right = q1;
	q1->Right = q;
	p->Right = q1->Left;
	q1->Left = p;
	return q1;
}

tree Insert(tree root, char x) {//插入节点
	if (!root) {
		root = apply();//申请内存
		root->data = x;
		return root;
	}
	else {
		if (x < root->data) {//小于
			root->Left = Insert(root->Left, x);
			if (Height(root->Left) - Height(root->Right) > 1) {//深度差大于1，开始旋转
				if (x < root->Left->data)
					root = LL(root);
				else
					root = LR(root);
			}
			return root;
		}
		else {//大于
			root->Right = Insert(root->Right, x);
			if (Height(root->Right) - Height(root->Left) > 1) {//深度差大于1，开始旋转
				if (x > root->Right->data)
					root = RR(root);
				else
					root = RL(root);
			}
			return root;
		}
	}
}

void Preorder(tree head) {//先序遍历
	printf("%c", head->data);
	if (head->Left)
		Preorder(head->Left);
	if (head->Right)
		Preorder(head->Right);
	return;
}

void Inorder(tree head) {//中序遍历
	if (head->Left)
		Inorder(head->Left);
	printf("%c", head->data);
	if (head->Right)
		Inorder(head->Right);
	return;
}
void Postorder(tree head) {//后序遍历
	if (head->Left)
		Postorder(head->Left);
	if (head->Right)
		Postorder(head->Right);
	printf("%c", head->data);
	return;
}

void Print(tree p, int depth) {//打印二叉树
	int i;
	if (p->Right)
		Print(p->Right, depth + 1);
	for (i = 0; i < depth; i++)
		printf("    ");
	printf("%c\n", p->data);
	if (p->Left)
		Print(p->Left, depth + 1);
	return;
}
void Pre() {//先序遍历并打印
	printf("Preorder: ");
	Preorder(root);
	printf("\n");
	return;
}
void In() {//中序遍历并打印
	printf("Inorder: ");
	Inorder(root);
	printf("\n");
	return;
}
void Post() {//后续遍历并打印
	printf("Postorder: ");
	Postorder(root);
	printf("\n");
	return;
}
void Ptree() {//打印凹入二叉树
	printf("Tree:\n");
	Print(root, 0);
	return;
}
void Oper() {//全部操作集合
	Pre();
	In();
	Post();
	Ptree();
}
int main() {
	char ch;
	FILE* vvv = freopen("input.txt", "r", stdin);
	while((ch=getchar())&&ch!='\n')
		root = Insert(root, ch);//插入节点
	Oper();//主函数控制在六行以内/cy
	return 0;
}