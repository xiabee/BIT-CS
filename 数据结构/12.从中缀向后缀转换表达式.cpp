#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#define maxn 1000
typedef struct ADT {
	char cha;
	struct ADT* next;

}node;
const char Opp_char[6] = { '^','*','/','+','-','(' };
const int Opp_num1[6] = { 7,4,4,2,2,2 };
const int Opp_num2[6] = { 6,5,5,3,3,1 };

typedef	node* stack;
int x, y;
int IsEmpty(stack s) {//判断栈是否为空
	return s->next == NULL;
}
void push(char x, stack s) {//入栈
	stack TempCell;
	TempCell = (stack)malloc(sizeof(node));
	if (NULL == TempCell)
		exit(-1);
	else {
		TempCell->cha = x;
		TempCell->next = s->next;
		s->next = TempCell;
	}
	return;
}
void pop(stack s) {//出栈
	stack FirstCell;
	if (IsEmpty(s)) {
		//printf("error.\n");
		exit(-1);
	}

	else {
		FirstCell = s->next;
		s->next = s->next->next;
		free(FirstCell);
	}
	return;
}
void MakeEmpty(stack s) {//清空栈
	if (NULL == s)
		exit(-1);
	else
		while (!IsEmpty(s))
			pop(s);
	return;
}
char top(stack s) {
	if (s == NULL) {
		//printf("error.\n");
		exit(-1);
	}
	while (s->next != NULL)
		s = s->next;
	return s->cha;
}
stack Create(void) {
	stack s;
	s = (stack)malloc(sizeof(node));
	if (NULL == s) {
		//printf("error.\n");
		exit(-1);
	}

	s->next = NULL;
	MakeEmpty(s);
	return s;
}
void Oper1(stack s,char tmp) {
	while (1) {
		if (s->next == NULL) {
			push(tmp, s);
			break;
		}
		char tmp1 = s->next->cha;
		switch (tmp) {
		case '^': {x = 7; break; }
		case '*': {x = 4; break; }
		case '/': {x = 4; break; }
		case '+': {x = 2; break; }
		case '-': {x = 2; break; }
		}
		switch (tmp1) {
		case '^': {y = 6; break; }
		case '*': {y = 5; break; }
		case '/': {y = 5; break; }
		case '(': {y = 1; break; }
		case '+': {y = 3; break; }
		case '-': {y = 3; break; }
		}
		if (y > x || y == x) {
			putchar(tmp1);
			//printf("%c", tmp1);
			pop(s);
			continue;
		}
		else {
			push(tmp, s);
			break;
		}
	}
	return;
}
void Oper2(stack s, char tmp) {
	int i1, i2;
	while (1) {
		if (s->next == NULL) {
			push(tmp, s);
			break;
		}
		char tmp1 = s->next->cha;
		i1 = 0;
		i2 = 0;
		while (Opp_char[i1] != tmp)
			i1++;//找到对应操作符
		while (Opp_char[i2] != tmp1)
			i2++;//找到对应操作符
		if (Opp_num2[i2] > Opp_num1[i1]) {
			printf("%c", tmp1);
		
			pop(s);
			continue;
		}
		else {
			push(tmp, s);
			break;
		}
	}
	return;
}

int main() {
	//FILE* vvv = freopen("input.txt", "r", stdin);
	int v, n;
	char tmp;
	v = scanf("%d", &n);
	while (n--) {//n组用例
		stack s = Create();
		while ((scanf("%c",&tmp)) && tmp != '#') {//#号结束输入
			if (tmp == '\n')
				continue;
			if (isalnum(tmp)) {//输入为字母和数字
				printf("%c", tmp);
			}
			else if (tmp == '(') {
				push(tmp, s);//栈外左括号优先级最高，直接压入
			}
			else if (tmp == ')') {
				while (s->next->cha != '(') {//栈外右括号闭合，寻找栈内左括号
					printf("%c", s->next->cha);
					pop(s);
				}
				pop(s);
			}
			else {
				if (s->next == NULL)//栈空
					push(tmp, s);
				else {//遇到运算符
					//Oper1(s, tmp);
					Oper2(s, tmp);
				}
			}
		}
		while (s->next != NULL) {
			printf("%c", s->next->cha);
			pop(s);
		}
		printf("\n");
	}
	//printf("\n");
	return 0;
}