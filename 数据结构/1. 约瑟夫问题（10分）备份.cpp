#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#define ERROR 0
struct Joseph* CreatList(int n);//用于创建链表
typedef struct Joseph {
	int data;//记录编号
	struct Joseph* next;//指向下一个
}node;
int main() {//C6011 C6001一大堆，内存分配与销毁出现大问题......先跑一遍康康能不能过.jpg
	int n, k, m, v;
	node* head;//假装有个头节点
	v = scanf("%d,%d,%d", &n, &k, &m);//v记录返回值避免C6031
	if (n < 1 || k < 1 || m < 1) {
		printf("n,m,k must bigger than 0.\n");
	}
	else if (k > n) {
		printf("k should not bigger than n.\n");
	}
	else {
		head = CreatList(n);
		node* dnmd, * p2;
		dnmd = head->next;
		p2 = NULL;
		node* temp;
		while (1) {
			if (dnmd->data != k) {
				dnmd = dnmd->next;
				continue;
			}
			else break;
		}
		int count = 1;
		for (int i = 0; i < n; i++) {
			for (int j = 1; j < m; j++)
			{
				p2 = dnmd;
				if (dnmd)
					dnmd = dnmd->next;
			}
			if (i == n - 1) {//最后一个直接换行
				printf("%d\n", dnmd->data);//这里的C6011还是么的避免啊我dnmd不是分配了内存吗
				count++;
			}
			else if (count == 10) {
				printf("%d\n", dnmd->data);//每十个换行......然鹅这里怎么还是C6011啊
				count = 1;
			}
			else {
				if (dnmd)
					printf("%d ", dnmd->data);//C6001又是撒子，我dnmd不是初始化了吗//
				count++;
			}
			temp = dnmd;
			if (p2 != NULL && temp != NULL)//再次判断是否分配内存
				p2->next = temp->next;
			if (dnmd)
				dnmd = temp->next;
			if (temp != NULL)//判断是否释放内存
				free(temp);
		}
	}
	return 0;
}

struct Joseph* CreatList(int n) {
	node* head;//真头节点
	node* dnmd, * p2;
	head = (struct Joseph*)malloc(sizeof(struct Joseph));
	p2 = head;
	if (!p2)//强行判断是否分配内存避免C6011
		return ERROR;
	else
		p2->next = NULL;
	dnmd = NULL;
	for (int i = 1; i <= n; i++) {
		dnmd = (struct Joseph*)malloc(sizeof(struct Joseph));
		if (!dnmd)//强行判断是否分配内存避免C6011
			return ERROR;
		else
			dnmd->data = i;
		if (!p2)//强行判断是否分配内存避免C6011
			return ERROR;
		else
			p2->next = dnmd;
		p2 = dnmd;
		if (!dnmd)//强行判断是否分配内存避免C6011
			return ERROR;
		else
			dnmd->next = NULL;
	}
	if (dnmd != NULL && head != NULL)
		dnmd->next = head->next;
	return head;
}