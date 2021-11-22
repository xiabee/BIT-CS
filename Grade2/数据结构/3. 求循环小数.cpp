/* PRESET CODE BEGIN - NEVER TOUCH CODE BELOW */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
	int data;
	struct node* next;
} NODE;
void output(NODE* head);
void change(int divisor, int dis, NODE*head);
void output(NODE* head) {
	int k = 0;
	printf("0.");
	while (head->next != NULL && k < 50) {//好像是要搞循环链表来着，50位，，，直接暴算吧
		printf("%d", head->next->data);
		head = head->next;
		k++;
	}
	printf("\n");
}

int main() {
	//FILE* GG = freopen("input.txt", "r", stdin);
	int divisor, dis;
	NODE* head;
	int v;
	v = scanf("%d%d", &divisor, &dis);
	head = (NODE*)malloc(sizeof(NODE));
	if (NULL == head)
		return 0;
	head->next = NULL;
	head->data = -1;
	change(divisor, dis, head);
	output(head);
	return 0;
}

/* PRESET CODE END - NEVER TOUCH CODE ABOVE */
void change(int divisor, int dis, NODE* head) {
	typedef struct qnmd {
		int order;
		int check;
	}nmd;//掉发爆粗现场
	nmd re[10];
	for (int i = 0; i < 10; i++) {
		re[i].check = 0;
		re[i].order = i;
	}
		
	NODE* p = head;
	NODE* q = (NODE*)malloc(sizeof(NODE));
	int i = 0, gg = 0, remainder = 1;//余数为1，之前余数为0直接暴毙
	//gg用来存储data
	divisor *= 10;//先阔十倍，之前不乘直接暴毙
	gg = divisor / dis;
	if (NULL == q)//C6011......又是你
		return;
	q->data = gg;
	p->next = q;//后移一位
	p = q;
	NODE* temp = head;
	//int check[10] = { 0 };
	while (remainder && i < 50) {
		divisor -= gg * dis;//计算余数
		divisor *= 10;//一位一位算过去
		gg = divisor / dis;
		q = (NODE*)malloc(sizeof(NODE));
		if (NULL == q)//嗯?又是你......
			return;
		q->data = gg;
		p->next = q;
		p = q;//后移，继续算
		i++;//一路向下算
		remainder = divisor % dis;
		
		/*if (re[remainder].check) {
			while (temp->data != re[remainder].order)//找到前一个
				temp = temp->next;
			p->next = temp->next;
			break;
		}*/
		re[remainder].check = 1;
	}
	p->next = NULL;
	return;
}