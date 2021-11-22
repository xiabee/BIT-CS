#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#define Min(a,b) (a<=b?a:b)//宏运算
int flag, v;
int choice, stockid, quantity, orderid = 1;
float price;
char bs;
typedef struct expect {
	int orderid;
	int stockid;
	float price;
	int quantity;
	char type;
	struct expect* next;
}node;
node* apply() {//申请空间，顺便检查是否申请成功
	node* p;
	p = (node*)malloc(sizeof(node));
	if (NULL == p)
		exit(-1);
	return p;
}
node* buy, * p, * sell;
void initBuyQueue() {
	buy = apply();
	buy->orderid = -1;
	buy->stockid = -1;
	buy->price = -1.0;
	buy->quantity = -1;
	buy->type = 'x';
	buy->next = NULL;
}
void initSellQueue() {
	sell = apply();
	sell->orderid = -1;
	sell->stockid = -1;
	sell->price = -1.0;
	sell->quantity = -1;
	sell->type = 'x';
	sell->next = NULL;
}
void saveBuy(node* p) {
	node* q = buy, * q_pre;
	int flag1 = 0;
	while (q->next != NULL) {
		q_pre = q;
		q = q->next;
		if (p->stockid == q->stockid) {
			flag1 = 1;
			while (q != NULL && (q->price > p->price || q->price == p->price) && q->stockid == p->stockid) {
				q_pre = q;
				q = q->next;
			}
			q_pre->next = p;
			p->next = q;
			break;
		}
	}
	if (flag1 == 0) {
		p->next = buy->next;
		buy->next = p;
	}

}
void saveSell(node* p) {
	node* q = sell, * q_pre;
	int flag1 = 0;
	while (q->next != NULL) {
		q_pre = q;
		q = q->next;
		if (p->stockid == q->stockid) {
			flag1 = 1;
			while (q != NULL && (q->price <= p->price) && q->stockid == p->stockid) {
				q_pre = q;
				q = q->next;
			}
			q_pre->next = p;
			p->next = q;
			break;
		}
	}
	if (flag1 == 0) {
		p->next = sell->next;
		sell->next = p;
	}
}
void deleteBuy(node* p) {
	node* x = buy;
	while (x->next->orderid != p->orderid)
		x = x->next;
	x->next = p->next;

}
void deleteSell(node* p) {
	node* x = sell;
	while (x->next->orderid != p->orderid)
		x = x->next;
	x->next = p->next;

}
void deleteAll() {
	node* x;
	x = buy;
	while (x->next != NULL) {
		x = x->next;
		if (x->quantity == 0) deleteBuy(x);
	}
	x = sell;
	while (x->next != NULL) {
		x = x->next;
		if (x->quantity == 0) deleteSell(x);
	}
}
void opper1(int stockid, float price, int quantity, char bs) {
	p = apply();
	p->orderid = orderid++;
	p->price = price;
	p->stockid = stockid;
	p->quantity = quantity;
	p->type = bs;
	printf("orderid: %04d\n", p->orderid);
	if (bs == 'b') {
		node* q = sell;
		while (q->next != NULL) {
			q = q->next;
			if (q->stockid != p->stockid) continue;
			else {
				if (q->price < p->price || q->price == p->price) {
					int dealquantity = Min(p->quantity, q->quantity);
					printf("deal--price:%6.1f  quantity:%4d  buyorder:%04d  sellorder:%04d\n", (p->price + q->price) / 2.0, dealquantity, p->orderid, q->orderid);
					p->quantity -= dealquantity;
					q->quantity -= dealquantity;
					if (q->quantity == 0) deleteSell(q);
					if (p->quantity == 0) break;
				}
				else continue;
			}
		}
		if (p->quantity == 0)
			free(p);
		else {
			saveBuy(p);
		}
	}
	else {
		node* q = buy;
		while (q->next != NULL && p->quantity != 0) {
			q = q->next;
			if (q->stockid != p->stockid) continue;
			else {
				if (q->price > p->price || q->price == p->price) {
					int dealquantity = Min(p->quantity, q->quantity);
					printf("deal--price:%6.1f  quantity:%4d  sellorder:%04d  buyorder:%04d\n", (p->price + q->price) / 2.0, dealquantity, p->orderid, q->orderid);
					p->quantity -= dealquantity;
					q->quantity -= dealquantity;
					if (q->quantity == 0) deleteBuy(q);
				}
				else continue;
			}
		}
		if (p->quantity == 0)
			free(p);
		else {
			saveSell(p);
		}
	}
	deleteAll();
	return;
}
void opper2(int stockid1) {
	printf("buy orders:\n");
	p = buy;
	while (p->next != NULL) {
		p = p->next;
		if (p->stockid == stockid1 && p->quantity != 0)
			printf("orderid: %04d, stockid:%04d, price: %6.1f, quantity: %4d, b/s: %c\n", p->orderid, p->stockid, p->price, p->quantity, p->type);
	}
	printf("sell orders:\n");
	p = sell;
	while (p->next != NULL) {
		p = p->next;
		if (p->stockid == stockid1 && p->quantity != 0)
			printf("orderid: %04d, stockid:%04d, price: %6.1f, quantity: %4d, b/s: %c\n", p->orderid, p->stockid, p->price, p->quantity, p->type);
	}
}
void opper3(int orderid1) {
	flag = 0;
	p = buy;
	while (p->next != NULL) {
		p = p->next;
		if (p->orderid == orderid1) {
			flag = 1;
			printf("deleted order:orderid: %04d, stockid:%04d, price: %6.1f, quantity: %4d, b/s: %c\n", p->orderid, p->stockid, p->price, p->quantity, p->type);
			deleteBuy(p);
			break;
		}
	}
	p = sell;
	while (p->next != NULL && !flag) {
		p = p->next;
		if (p->orderid == orderid1) {
			flag = 1;
			printf("deleted order:orderid: %04d, stockid:%04d, price: %6.1f, quantity: %4d, b/s: %c\n", p->orderid, p->stockid, p->price, p->quantity, p->type);
			deleteSell(p);
			break;
		}
	}
	if (flag == 0) {
		printf("not found\n");
	}
	flag = 0;
	return;
}
int main() {
	//FILE* vvv = freopen("input.txt", "r", stdin);
	initBuyQueue();
	initSellQueue();
	while ((scanf("%d ", &choice)) && choice != 0) {
		if (choice == 0) {
			exit(0);
			break;
		}
		else if (choice == 1) {
			//输入 
			v = scanf("%d %f %d %c", &stockid, &price, &quantity, &bs);
			opper1(stockid, price, quantity, bs);
		}
		else if (choice == 2) {
			int stockid1;
			v = scanf("%d", &stockid1);
			opper2(stockid1);
		}
		else if (choice == 3) {
			int orderid1;
			v = scanf("%d", &orderid1);
			opper3(orderid1);
		}
	}
	return 0;
}
