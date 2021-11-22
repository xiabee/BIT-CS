#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<queue>
#include<algorithm>
using namespace std;//被迫向stl妥协，向递归妥协
typedef struct TreeNode* tree;
int num = 0;

typedef struct TreeNode {
	char data;
	tree Left;
	tree Right;
}node;
queue <tree> GG_tree;
tree apply() {//申请内存，顺便判断是否分配成功
	tree p = (tree)malloc(sizeof(node));
	if (!p)
		exit(-1);
	p->Left = NULL;
	p->Right = NULL;
	p->data = '\0';
	return p;
}

void CreatBiTree() {
	char ch;
	tree tmp, N;
	int v;
	while (!GG_tree.empty()) {
		v = scanf("%c", &ch);
		tmp = GG_tree.front();
		GG_tree.pop();
		if (ch == '\n')//遇到会回车结束
			break;
		tmp->data = ch;
		N = apply();//申请空间......之前一直出错，，，忘记申请空间了
		tmp->Left = N;
		GG_tree.push(N);
		N = apply();
		tmp->Right = N;
		GG_tree.push(N);
	}
	return;
}
void Visit(tree tmp) {//访问当前节点并输出
	if (tmp->data != '#' && tmp->data != '\0')
		printf("%c", tmp->data);
}
void Print(tree tmp, int i) {//递归输出左右节点
	if (tmp->data != '#' && tmp->data != '\0') {
		int j;
		for (j = 1; j <= i; j++)
			printf("    ");
		Visit(tmp);
		printf("\n");
		i++;
		Print(tmp->Left, i);
		Print(tmp->Right, i);
	}
	return;
}
void Anti_Print(tree tmp, int i) {//交换后递归输出
	if (tmp->data != '#' && tmp->data != '\0') {
		int j;
		for (j = 1; j <= i; j++)
			printf("    ");
		Visit(tmp);
		printf("\n");
		i++;
		Anti_Print(tmp->Right, i);
		Anti_Print(tmp->Left, i);
	}
	return;
}
void Pre_Sequence(tree tmp) {//交换前先序遍历输出
	if (tmp->data != '#' && tmp->data != '\0') {
		Visit(tmp);
		Pre_Sequence(tmp->Left);
		Pre_Sequence(tmp->Right);
	}
	return;
}
void In_Sequence(tree tmp){//交换前中序遍历输出
	if (tmp->data != '#' && tmp->data != '\0') {
		In_Sequence(tmp->Left);
		if ((tmp->Left->data == '#' || tmp->Left->data == '\0') && (tmp->Right->data == '#' || tmp->Right->data == '\0'))
			num++;
		Visit(tmp);
		In_Sequence(tmp->Right);
	}
	return;
}
void Post_Sequence(tree tmp) {//交换前先序遍历输出
	if (tmp->data != '#' && tmp->data != '\0') {
		Post_Sequence(tmp->Left);
		Post_Sequence(tmp->Right);
		Visit(tmp);
	}
	return;
}
void Pre_Anti(tree tmp) {//交换后先序输出
	if (tmp->data != '#' && tmp->data != '\0') {
		Visit(tmp);
		Pre_Anti(tmp->Right);
		Pre_Anti(tmp->Left);
	}
	return;
}
void In_Anti(tree tmp) {//交换后中序输出
	if (tmp->data != '#' && tmp->data != '\0') {
		In_Anti(tmp->Right);
		Visit(tmp);
		In_Anti(tmp->Left);
	}
	return;
}
void Post_Anti(tree tmp) {//交换后后续输出
	if (tmp->data != '#' && tmp->data != '\0') {
		Post_Anti(tmp->Right);
		Post_Anti(tmp->Left);
		Visit(tmp);
	}
	return;
}
tree root = apply();

void Cre() {//把回车写进函数，让主函数好看看一点点......
	GG_tree.push(root);
	CreatBiTree();
	printf("BiTree\n");
	Print(root, 0);
	return;
}
void Pre1() {//交换前先序遍历
	printf("pre_sequence  : ");
	Pre_Sequence(root);
	printf("\n");
	return;
}
void In1() {//交换前中序遍历
	printf("in_sequence   : ");
	In_Sequence(root);
	printf("\n");
	return;
}
void Pos1() {//交换前后序遍历
	printf("post_sequence : ");
	Post_Sequence(root);
	printf("\n");
	return;
}
void Swap() {//左右节点交换
	printf("Number of leaf: %d\n", num);
	printf("BiTree swapped\n");
	Anti_Print(root, 0);
	return;
}
void Pre2() {//交换后先序遍历
	printf("pre_sequence  : ");
	Pre_Anti(root);
	printf("\n");
	return;
}
void In2() {//交换后中序遍历
	printf("in_sequence   : ");
	In_Anti(root);
	printf("\n");
	return;
}
void Pos2() {//交换后后续遍历
	printf("post_sequence : ");
	Post_Anti(root);
	printf("\n");
	return;
}
void Oper1() {//交换前输出
	Cre();
	Pre1();
	In1();
	Pos1();
	return;
}
void Oper2() {//交换后输出
	Pre2();
	In2();
	Pos2();
	return;
}
int main() {//这个亚子就显得主函数很简洁
	//虽然其他函数智障了一点
	//FILE* vvv = freopen("input.txt", "r", stdin);
	Oper1();
	Swap();
	Oper2();
	return 0;
}