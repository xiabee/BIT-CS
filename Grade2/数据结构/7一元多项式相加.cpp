#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define maxn 2
int flag = 1, m;

typedef struct Poly {
	int coe;//系数
	int exp;//指数
	struct Poly* next;
}node;
node* CCC(int m);;
int IsLast(node* p) {
	return p->next == NULL;
}

void Empty(node* head) {
	node* p = (node*)malloc(sizeof(node));
	p = head;
	if (p == NULL)
		return;
	while (p != NULL) {
		node* temp = p->next;
		p = temp->next;
		free(p);
	}
	return;
}

node* Create(int m) {//创建多项式
	int v;
	node* head, * p, * p1;
	p1 = (node*)malloc(sizeof(node));
	if (NULL == p1)
		exit(-1);
	v = scanf("%d%d", &p1->coe, &p1->exp);
	printf("<%d,%d>,", p1->coe, p1->exp);
	head = p1;
	int n = m - 1;//第一项已经创建，记得减一/px	窒息，真的窒息
	while (n--) {
		p = (node*)malloc(sizeof(node));
		if (NULL == p)
			exit(-1);
		v = scanf("%d%d", &p->coe, &p->exp);
		printf("<%d,%d>", p->coe, p->exp);
		if (!(n - 1))
			printf(",");
		p1->next = p;
		p1 = p;
	}
	p1->next = NULL;
	printf("\n");
	return head;
}

node* Add(node* a, node* b) {
	node* head, * p, * p1;
	if (a->coe == 0)//为零直接返回了
		return b;
	if (b->coe == 0)
		return a;
	p = (node*)malloc(sizeof(node));
	if (NULL == p)
		exit(-1);
	while (1) {//先直接while（1）吧
		if (a == NULL || b == NULL) {
			p->coe = 0;
			p->exp = 0;
			p->next = NULL;
			return p;
		}
		if (a->exp < b->exp) {//判断大小
			p->exp = a->exp;
			p->coe = a->coe;
			a = a->next;
			break;
		}
		else {
			if (a->exp > b->exp) {
				p->exp = b->exp;
				p->coe = b->coe;
				b = b->next;
				break;
			}
			else {
				int ttemp;
				ttemp = a->coe + b->coe;
				if (ttemp != 0) {
					p->exp = a->exp;
					p->coe = ttemp;
					a = a->next;
					b = b->next;
					break;
				}
				else {
					a = a->next;
					b = b->next;
				}
			}
		}
	}
	head = p1 = p;
	while (a != NULL && b != NULL) {
		p = (node*)malloc(sizeof(node));
		if (NULL == p)
			exit(-1);
		if (a->exp < b->exp) {
			p->exp = a->exp;
			p->coe = a->coe;
			a = a->next;
			p1->next = p;
			p1 = p;
		}
		else {
			if (a->exp > b->exp) {
				p->exp = b->exp;
				p->coe = b->coe;
				b = b->next;
				p1->next = p;
				p1 = p;
			}
			else {
				int ttemp;
				ttemp = a->coe + b->coe;
				if (ttemp != 0) {//非零，记录
					p->exp = a->exp;
					p->coe = ttemp;
					a = a->next;
					b = b->next;
					p1->next = p;
					p1 = p;
				}
				else {//为零的时候直接略过......
					a = a->next;
					b = b->next;
				}
			}
		}
	}
	while (a != NULL) {//开始寻找
		p = (node*)malloc(sizeof(node));
		if (NULL == p)
			exit(-1);
		p->exp = a->exp;
		p->coe = a->coe;
		p1->next = p;
		p1 = p;
		a = a->next;
	}
	while (b != NULL) {
		p = (node*)malloc(sizeof(node));
		if (NULL == p)
			exit(-1);
		p->exp = b->exp;
		p->coe = b->coe;
		p1->next = p;
		p1 = p;
		b = b->next;
	}
	p1->next = NULL;
	return head;
}

void Print(node* head) {//输出
	if (head->coe == 0) {//这里判断了半天，零链表系数为零，之前一直折腾零的问题/px	智熄，真的智熄
		printf("<0,0>\n");
		return;
	}
	while (head->next != NULL) {//非零多项式
		printf("<%d,%d>,", head->coe, head->exp);
		head = head->next;
	}
	printf("<%d,%d>\n", head->coe, head->exp);
	return;
}

node* input() {
	int i, v;
	flag = 0;
	v = scanf("%d", &m);
	if (m > maxn) {
		flag = 1;
		return CCC(m);//奇怪算法暴算
	}
		
	return Create(m);
}

node* CCC(int m) {//暴力hack
	int i, v;
	node* head, * p, * p1;
	p1 = (node*)malloc(sizeof(node));
	if (NULL == p1)
		exit(-1);
	v = scanf("%d%d", &p1->coe, &p1->exp);
	head = p1;
	for (i = 1; i < m; i++) {
		p = (node*)malloc(sizeof(node));
		if (p == NULL)
			exit(-1);
		v = scanf("%d%d", &p->coe, &p->exp);
		p1->next = p;
		p1 = p;
	}
	p1->next = NULL;
	return head;
}

int main() {
	//FILE *g_g = freopen("input.txt", "r", stdin);
	int oper, v, i;
	int x1, x2, x3;
	v = scanf("%d", &oper);
	if (oper) {//如果输入为“1”
		node* p1, * p2, * p3, * temp;
		//p1 = input();
		//if (flag) 
		{//暴力hack
			v = scanf("%d", &x1);
			p1 = CCC(x1);
			temp = p1;
			for (i = 1; i < x1; i++) {
				printf("<%d,%d>,", temp->coe, temp->exp);
				temp = temp->next;
			}
			printf("<%d,%d>\n", temp->coe, temp->exp);
		}
		//p2 = input();
		//if (flag) 
		{//暴力hack
			v = scanf("%d", &x2);
			p2 = CCC(x2);
			temp = p2;
			for (i = 1; i < x2; i++) {
				printf("<%d,%d>,", temp->coe, temp->exp);
				temp = temp->next;
			}
			printf("<%d,%d>\n", temp->coe, temp->exp);
		}
		//p3 = input();
		//if (flag) 
		{//暴力hack
			v = scanf("%d", &x3);
			p3 = CCC(x3);
			temp = p3;
			for (i = 1; i < x3; i++) {
				printf("<%d,%d>,", temp->coe, temp->exp);
				temp = temp->next;
			}
			printf("<%d,%d>\n", temp->coe, temp->exp);
		}

		node* sum1, * sum;
		sum1 = Add(p1, p2);
		//Empty(p1);
		//Empty(p2);
		sum = Add(sum1, p3);
		Print(sum1);
		Print(sum);
	}
	return 0;//程序君您休息
}