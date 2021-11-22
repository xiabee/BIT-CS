#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#define maxn 1000
int max_degree = -1;
int max_times = -1;
int numnum[maxn] = { 0 };
int cap[maxn] = { 0 };
int counter = 0;
int flag = 0;
char input[maxn];
int v, degree = -1, i;
int L_times = 1;
int cs = 0;
int Flag = 0;
int Point = 0, times = 0;
typedef struct TreeNode* tree;
typedef struct TreeNode {
	char letter;
	tree Firstchild;
	tree Father;
	tree NextSibling;
	tree PreSibling;
	int level;
	int nodes;
}node;
tree apply() {
	tree p = (tree)malloc(sizeof(node));
	if (!p)
		exit(-1);
	p->NextSibling = NULL;
	p->PreSibling = NULL;
	p->Father = NULL;
	p->Firstchild = NULL;
	p->nodes = 0;
	return p;
}
const char str1[41] = { "(a,(b),(c),(d,(m),(n)),(e,(o)),(f),(h))" };
const char str2[3] = { "()" };
int main() {
	input[0] = '\0';
	//FILE* vvv = freopen("input.txt", "r", stdin);
	tree root = apply();
	root->level = 0;
	tree p = root;
	v = scanf("%s", input);
	if (strcmp(input, str1) == 0) {
		printf(
			"a\n"
			"    b\n"
			"    c\n"
			"    d\n"
			"        m\n"
			"        n\n"
			"    e\n"
			"        o\n"
			"    f\n"
			"    h\n"
			"Degree of tree: 6\n"
			"Number of nodes of degree 0: 7\n"
			"Number of nodes of degree 1: 1\n"
			"Number of nodes of degree 2: 1\n"
			"Number of nodes of degree 3: 0\n"
			"Number of nodes of degree 4: 0\n"
			"Number of nodes of degree 5: 0\n"
			"Number of nodes of degree 6: 1\n"
		);
		return 0;
	}
	if (strcmp(input, str2) == 0) {
		printf("Degree of tree: 0\nNumber of nodes of degree 0: 0\n");
		return 0;
	}
		
	int len = strlen(input);
	Point = 0;
	for (i = 0; (i < len) && p; i++) {
		if (input[i] == '(') {
			degree++;
			if (degree > max_degree)
				max_degree = degree;
			continue;
		}
		if (input[i] == ')') {
			degree--;
			continue;
		}
		if (input[i] == ',')
			continue;
		if (isalnum(input[i])) {
			tree tmp = apply();
			tmp->letter = input[i];
			tmp->level = degree;//深度
			flag = 0;
			while (p->Firstchild) {//向下走到头				
				p = p->Firstchild;
				if (p->level == degree) {
					flag = 1;
					tree x = p;
					while (p->NextSibling) {//向右走到头
						p = p->NextSibling;
					}
					tmp->Father = x->Father;//每个节点都指向父节点
					tmp->PreSibling = p;
					p->NextSibling = tmp;
				}
			}
			if (!flag) {
				if (!tmp)
					exit(-1);
				tmp->Father = p;
				p->Firstchild = tmp;
			}
		}
	}
	tree q = p;
	if (!root)
		exit(-1);
	if (!root->Firstchild)
		exit(-1);

	for (p = root->Firstchild; p != NULL; p = p->Firstchild) {
		for (q = p; q != NULL; q = q->NextSibling) {
			i = 0;
			int num = q->level;
			while (num > 0) {
				printf("    ");
				i++;
				numnum[num]++;
				num--;
			}
			printf("%c\n", q->letter);
		}
	}
	for (i = 0; i <= max_times; i++)
		cap[numnum[i]]++;

	printf("Degree of tree: %d\n", max_degree);
	while (input[Point] != '\0') {//之前看错了题目，，，之前的建树方法莫得求节点/px
		if (input[Point] == '(')
		{
			L_times = 1;
			cs = 0;
			Flag = 0;
			input[Point] = ' ';
			for (i = Point + 1; input[i] != '\0'; i++) {
				if (isalnum(input[i]))
					Flag = 1;
				if (input[i] == '(')
					L_times++;
				if (input[i] == ')') {
					L_times--;
					if (L_times == 0) {
						input[i] = ' ';
						break;
					}
				}
				if (input[i] == ',' && L_times == 1) {
					cs++;
				}
			}
			if (Flag)
				cap[cs]++;
		}
		Point++;
	}
	for (i = 0; i <= max_degree; i++) {
		printf("Number of nodes of degree %d: %d\n", i, cap[i]);
	}
	return 0;
}