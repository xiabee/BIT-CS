#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define maxn 100
/*题目看起来有点简单，所以决定手写一个栈试试*/
typedef struct MyStack {//栈结构
	int top;
	int botton;
	char data[maxn];
}stack;

stack* CreateStack() {//创建栈
	stack* head = (stack*)malloc(sizeof(stack));
	if (NULL == head) {
		printf("Error!\n");
		exit(-1);
	}
	head->botton = head->top = 0;//创建头节点
	return head;
}

void push(stack* p, char x) {//入栈
	p->data[p->top] = x;//入栈
	p->top++;//栈顶指针加一
}

void pop(stack* p) {//出栈
	if (p->top != p->botton) {//栈非空
		p->top--;//栈顶指针减一
		return;
	}
	exit(-1);
}

int IsEmpty(stack* p) {//判断栈是否为空
	if (p->top == p->botton)
		return 1;
	else
		return 0;
}

char getTop(stack* p) {//返回栈顶元素
	if (!IsEmpty(p))
		return p->data[p->top - 1];
	else
		return '*';
}

int main() {
	int v;
	char str;
	stack* s = CreateStack();//创建栈
	while((scanf("%c", &str))) {
		//v = scanf("%c", &str);
		if (str == '(' || str == '[') 
			push(s, str);//第一个开括号入栈
		if (str == ')') {
			if (getTop(s) != '(') {//空栈或者不匹配
				printf("Match false!\n");
				return 0;
			}
			else
				pop(s);//匹配则出栈
		}
		if (str == ']') {
			if (getTop(s) != '[') {//空栈或者不匹配
				printf("Match false!\n");
				return 0;
			}
			else
				pop(s);//匹配则出栈
		}
		if (str == '\n') {
			break;
		}
	}
	if (IsEmpty(s))
		printf("Match succeed!\n");
	else
		printf("Match false!\n");
	return 0;
}