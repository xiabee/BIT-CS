#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define maxn 100

//因为不知道能交C艹.jpg
//所以真手搓链表.jpg
//粗口
typedef struct Node {
	int Destination;   //货物目的地
	struct Node* next;      //结点元素指针
} node;

typedef struct {
	int Quality;      //货物总量
	node* front;       //队列头指针
	node* rear;        //队列尾指针
} queue;//队列结构

typedef struct {         //货车栈
	int* top;//栈顶
	int* base;//栈底
} stack;//栈结构

int testCnt, stations, carCapacity, storeCapacity, i, j, leftNum, goodsDes, k, Time, flag;
int v;
queue* goods, * sptr;               //货运站队列，动态分配
stack car;

void InitQueue(queue* Q) {//队列初始化
	Q->rear = Q->front = (node*)malloc(sizeof(node));//头结点，不存放数据
	if (NULL == Q->front)//判断内存是否分配成功   
		exit(1);
	Q->front->next = NULL;//下一项指向NULL，结束
	Q->Quality = 0;//赋值
}
void DeQueue(queue* Q, int* goodsDes) {//队列删除
	node* QueuePtr = Q->front->next;//找到下一项
	if (Q->front == Q->rear) //如果f、r相遇
		exit(1);        //空队列

	*goodsDes = QueuePtr->Destination;
	Q->Quality--;//数值减少
	Q->front->next = QueuePtr->next;
	if (QueuePtr == Q->rear)//遇到rear
		Q->rear = Q->front;//front推过去
	free(QueuePtr);//内存释放
}

void EnQueue(queue* Q, int Destination) {//队尾插入
	node* QueuePtr = (node*)malloc(sizeof(node));
	if (NULL == QueuePtr)//判断内存是否分配成功   
		exit(1);

	QueuePtr->Destination = Destination;//赋值，确认地点
	QueuePtr->next = NULL;//下一个赋为NULL
	Q->rear->next = QueuePtr;//移动
	Q->rear = QueuePtr;//移动
	Q->Quality++;//数据加一
}
void DestroyQueue(queue* Q) {//清除队列
	while (Q->front) {
		Q->rear = Q->front; //摘下
		Q->front = Q->front->next;//移至下一结点
		free(Q->rear);//释放
	}
}
void PrintQueue(queue Q) {//输出队列
	if (NULL==Q.front) //判断是否分配内存
		exit(1);
	printf("%d\t", Q.Quality);//输出首项
	while (Q.front->next) {//寻找下一项
		printf("%d\t", Q.front->next->Destination);//按序输出
		Q.front->next = Q.front->next->next;//数据传递
	}
}


                        //货车栈

void Create() {
	v = scanf("%d%d%d", &stations, &carCapacity, &storeCapacity);
	goods = (queue*)malloc(stations * sizeof(queue));//动态分配环中站
	for (i = 0; i < stations; i++) {
		v = scanf("%d", &leftNum);//输入
		sptr = goods + i;
		InitQueue(sptr);
		for (j = 0; j < leftNum; j++) {
			v = scanf("%d", &goodsDes);
			EnQueue(sptr, goodsDes);
		}
	}
	return;
}

void Oper() {
	Time = 0;
	car.top = car.base;
	for (k = 0;; k = ((++k) % stations)) {
		flag = 1;       //模拟处理标志位
		sptr = goods + k;
		//卸货
		while (car.top != car.base) {
			if (*(--car.top) == k + 1) { //卸到A平台
				Time++;
			}
			else if (sptr->Quality < storeCapacity) { //卸到B平台
				EnQueue(sptr, *car.top);
				Time++;
			}
			else {
				car.top++;
				break;
			}
		}
		//装货
		if (NULL == car.top || NULL == sptr)
			exit(1);
		while ((car.top - car.base) < carCapacity && (sptr->Quality != 0)) {
			DeQueue(sptr, &goodsDes);//卸货
			*car.top = goodsDes;
			car.top++;
			Time++;
		}
		for (i = 0; i < stations; i++) {
			sptr = goods + i;
			if (sptr->Quality != 0) {
				flag = 0;//结束，跳出循环
				break;
			}
		}
		if (flag && (car.top == car.base))//操作结束，跳出循环
			break;
		Time += 2;
	}
	return;
}

int main()
{
	//FILE* gg = freopen("input.txt", "r", stdin);
	car.base = (int*)malloc(maxn * sizeof(int));//创建初始car
	if (!car.base)   
		exit(1);
	v = scanf("%d", &testCnt);
	while (testCnt--) {
		Create();
		Oper();//分理中心货物模拟
		printf("%d\n", Time);
	}
	return 0;//程序君您休息
}