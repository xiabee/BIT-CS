#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
typedef struct JosephTwice {
	int data;
	struct JosephTwice* pre;//向前
	struct JosephTwice* next;//向后
}NODE;
NODE* head = NULL, * tail = NULL;
int n, k, m, v;
void Oper() {
	NODE* begin_1 = head;//指向头指针
	if (NULL == begin_1)//判断是否分配内存成功
		exit(-1);
	while (begin_1->data != k)
		begin_1 = begin_1->next;
	NODE* begin_2 = begin_1;
	int i; int begin = 1;
	while (n--) {//开始计算
		for (i = begin; i < m; i++) {
			begin_1 = begin_1->next;
			if (begin_1->data == 0)
				i--;//链表赋值，初始化
		}
		for (i = begin; i < m; i++) {
			begin_2 = begin_2->pre;
			if (begin_2->data == 0)
				i--;//赋值，初始化
		}
		printf("%d", begin_1->data);//先输出前一个
		begin_1->data = 0;
		if (begin_1 != begin_2) {
			printf("-%d", begin_2->data);//再输出后一个
			begin_2->data = 0;
			n--;
		}
		begin = 0;//归零.jpg
		printf(",");
	}
	printf("\n");
}
NODE* Create() {
	for (int i = 1; i <= n; i++) {//创建链表
		NODE* rear = (NODE*)malloc(sizeof(NODE));
		if (NULL == rear)
			return 0;
		rear->data = i;//循环赋值
		if (NULL == head)//判断是否分配内存成功
			head = tail = rear;
		else {
			tail->next = rear;//创建双向循环链表
			rear->pre = tail;
			tail = rear;
			head->pre = rear;
		}
	}
	tail->next = head;
	head->pre = tail;
	return head;
}

int check() {
	v = scanf("%d,%d,%d", &n, &k, &m);//记录返回值
	if (n < 1 || k < 1 || m < 1) {
		printf("n,m,k must bigger than 0.\n");
		return 0;
	}
	if (k > n) {
		printf("k should not bigger than n.\n");
		return 0;
	}
	return 1;
}
int main() {
	//FILE* p=freopen("input.txt", "r", stdin);
	if (check()) {//成功把主函数省成了三行/cy
		Create();
		Oper();//窒息操作
	}
	return 0;
}