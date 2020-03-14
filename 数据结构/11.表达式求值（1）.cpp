#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#define MAX 999999
typedef struct ADT {
	int cha;
	struct ADT* next;
}node;
typedef	node* stack;
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
		//exit(-1);
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
int top(stack s) {
	if (s == NULL) {
		//printf("error.\n");
		exit(-1);
	}
	while (s->next != NULL)
		s = s->next;
	return s->cha;
}
int pow(int a, int n) {//a的n次方
	int res = 1;
	while (!n) {
		if (n & 1)
			res *= a;
		n >>= 1;
		a = a * a;
	}
	return res;
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
int operate(int x, int y, char symbol) {
	switch (symbol) {
	case '+': return x + y;
	case '-': return x - y;
	case '*': return x * y;
	case '/': if (y) 
		return x / y;
			else {
			printf("Divide 0.\n");
			return MAX;
		}
	case '%': return x % y;//直接取余
	case '^': if (y >= 0) 
		return pow(x, y);
			else {
			printf("error.\n");
			return MAX;
		}
	default: printf("error.\n");
		return MAX;
	}
}

char operation[9] = { '+','-','*','/','(',')','#','^','%' };
char checklist[9][9] = {
	{'>','>','<','<','<','>','>','<','<'},
	{'>','>','<','<','<','>','>','<','<'},
	{'>','>','>','>','<','>','>','<','>'},
	{'>','>','>','>','<','>','>','<','>'},
	{'<','<','<','<','<','=',' ','<','<'},
	{'>','>','>','>',' ','>','>','>','>'},
	{'<','<','<','<','<',' ','=','<','<'},
	{'>','>','>','>','<','>','>','<','>'},
	{'>','>','>','>','<','>','>','<','>'}
};
char compare(char x, char y) {//比较两个符号的优先级
	int a = 0, b = 0;
	for (int i = 0; i <= 8; i++) {//找到a
		if (operation[i] == x) {
			a = i;
			break;
		}
	}
	for (int i = 0; i <= 8; i++) {//找到b
		if (operation[i] == y) {
			b = i;
			break;
		}
	}
	return checklist[a][b];
}

int main() {
	FILE* vvv = freopen("input.txt", "r", stdin);
	int v, n, flag, flag_num;
	int x, y, judge;
	char tmp = '\0', tmp1, ans, ope;
	v = scanf("%d", &n);
 	while (n--) {
		stack num = Create();
		stack op = Create();
		x = 0;
		flag = 0;
		flag_num = 0;
		while (1) {//开始计算
			tmp1 = tmp;
			v = scanf("%c", &tmp);
			if (tmp == '\n') {//遇到回车，结束输入，并加入#
				push('#', op);
				break;
			}
			if (isalnum(tmp)) {//遇到数字，因为不会出现字母
				x = x * 10 + tmp - 48;
				flag = 1;//标记，表示已经输入数字
			}
			else {//遇到符号
				flag_num = 1;//标记第一个符号已入栈
				if (flag) {
					push(x, num);
					x = 0;//数字入栈
				}
				if (tmp == '(') {
					push(tmp, op);//左括号直接入栈
					continue;
				}
				else if (tmp == ')') {
					while (top(op) != '(') {
						x = top(num);
						pop(num);
						y = top(num);
						ope = top(op);
						pop(op);
						judge = operate(x, y, ope);
						if (judge == MAX) {
							printf("error.\n");
							break;
						}
						push(judge, num);
					}
					pop(op);//弹出左括号
				}
				else {
					ans = compare(tmp, tmp1);
					if (ans == ' ') {
						printf("error.\n");
						break;
					}
					else if (ans == '<') {
						push(tmp, op);
						continue;
					}
					else {
						x = top(num);
						pop(num);
						y = top(num);
						ope = top(op);
						pop(op);
						judge = operate(x, y, ope);
						if (judge == MAX) {
							printf("error.\n");
							break;
						}
						push(judge, num);
					}
				}
			}
		}
		if (IsEmpty(op))
			printf("%d\n", top(num));
		else
			printf("error.\n");
	}
	return 0;
}