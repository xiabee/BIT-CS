#define _CRT_SECURE_NO_WARNINGS
/* PRESET CODE BEGIN - NEVER TOUCH CODE BELOW */

#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	int coef;
	int exp;
	struct node* next;
} NODE;

void multiplication(NODE* head1, NODE* head2, NODE* head3);
void input(NODE* head);
void output(NODE* head);

void input(NODE* head)
{
	int flag = 0, sign = 1, sum = 0, x = 0;
	char c;

	NODE* p = head;

	while ((c = getchar()) != '\n')
	{
		if (c == '<')
		{
			sum = 0;
			sign = 1;
			flag = 1;
		}
		else if (c == '-')
			sign = -1;
		else if (c >= '0' && c <= '9')
		{
			sum = sum * 10 + c - '0';
		}
		else if (c == ',')
		{
			if (flag == 1)
			{
				x = sign * sum;
				sum = 0;
				flag = 2;
				sign = 1;
			}
		}
		else if (c == '>')
		{
			p->next = (NODE*)malloc(sizeof(NODE));
			if (p->next == NULL)
				exit(-1);
			p->next->coef = x;
			p->next->exp = sign * sum;
			p = p->next;
			p->next = NULL;
			flag = 0;
		}
	}
	return;
}

void output(NODE* head)
{
	while (head->next != NULL)
	{
		head = head->next;
		printf("<%d,%d>,", head->coef, head->exp);
	}
	printf("\n");
	return;
}

int main()
{
	FILE* G_G = freopen("input.txt", "r", stdin);
	NODE* head1, * head2, * head3;
	head1 = (NODE*)malloc(sizeof(NODE));
	input(head1);
	head2 = (NODE*)malloc(sizeof(NODE));
	input(head2);
	head3 = (NODE*)malloc(sizeof(NODE));
	if (head3 == NULL)
		exit(-1);
	head3->next = NULL;
	multiplication(head1, head2, head3);
	output(head3);
	return 0;
}

/* PRESET CODE END - NEVER TOUCH CODE ABOVE */

int flag = 0;//用于标记是否为第一项
int co, ex;//临时记录系数和指数
NODE* temp1, * temp2;
void Loop(NODE* head3) {//大型迷惑模拟现场
	register NODE* p3 = head3;
	while (p3) {
		temp2 = p3;//临时变量储存p3
		p3 = p3->next;
		if (p3 == NULL) {
			temp1 = (NODE*)malloc(sizeof(NODE));
			if (temp1 == NULL)
				exit(-1);//C6011??!?	n*sl
			if (!co && !flag) {//未计算过
				temp1->exp = 0;//指数标零
				flag = 1;//标记，已经算过
			}
			else
				temp1->exp = ex;
			temp1->coef = co;//不论if真假，后续赋值都一样
			temp1->next = p3;
			temp2->next = temp1;
			p3 = temp2;
			break;
		}
		if (p3->exp < ex)//指数结果大于原指数
			continue;
		else if (p3->exp == ex) {
			p3->coef += co;
			if (!p3->coef && ex) {
				temp2->next = p3->next;
			}
			p3 = temp2;
			break;
		}
		else {
			temp1 = (NODE*)malloc(sizeof(NODE));
			if (temp1 == NULL)
				exit(-1);//C6011又来了，它又来了.......
			if (!co && !flag) {
				temp1->exp = 0;
				flag = 1;//标记
			}
			else
				temp1->exp = ex;
			temp1->coef = co;//不论if真假，后续赋值都一样
			temp1->next = p3;
			temp2->next = temp1;
			p3 = temp2;
			break;
		}
	}
	return;
}
void multiplication(NODE* head1, NODE* head2, NODE* head3) {//head1,head2，分别为原多项式，head3为结果多项式
	void Loop(NODE*p3);//太丑了，就单独写出来了
	register NODE* p1 = head1;
	register NODE* p2 = head2;
	register NODE* p3 = head3;
	while (p1->next) {
		p2 = head2;
		p1 = p1->next;//第一位没存数，直接后移后移一位
		p3 = head3;
		while (p2->next) {//p2后一位非空
			p2 = p2->next;//同理，先后移一位
			co = p1->coef * p2->coef;//计算系数
			ex = p1->exp + p2->exp;//计算指数
			if (!co && flag)
				continue;
			//Loop(head3);
			
			while (p3) {
				
				temp2 = p3;//临时变量储存p3
				p3 = p3->next;
				if (p3 == NULL) {
					temp1 = (NODE*)malloc(sizeof(NODE));
					if (temp1 == NULL)
						exit(-1);//C6011??!?	n*sl
					if (!co && !flag) {//未计算过
						temp1->exp = 0;//指数标零
						flag = 1;//标记，已经算过
					}
					else
						temp1->exp = ex;
					temp1->coef = co;//不论if真假，后续赋值都一样
					temp1->next = p3;
					temp2->next = temp1;
					p3 = temp2;
					break;
				}
				if (p3->exp < ex)//指数结果大于原指数
					continue;
				else if (p3->exp == ex) {
					p3->coef += co;
					if (!p3->coef && ex) {
						temp2->next = p3->next;
					}
					p3 = temp2;
					break;
				}
				else {
					temp1 = (NODE*)malloc(sizeof(NODE));
					if (temp1 == NULL)
						exit(-1);//C6011又来了，它又来了.......
					if (!co && !flag) {
						temp1->exp = 0;
						flag = 1;//标记
					}
					else
						temp1->exp = ex;
					temp1->coef = co;//不论if真假，后续赋值都一样
					temp1->next = p3;
					temp2->next = temp1;
					p3 = temp2;
					break;
				}
			}
		}
	}
	return;
}