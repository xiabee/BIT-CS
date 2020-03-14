/*3.21 Write routines to implement two stacks using only one array. 
Your stack routines should not declare an overflow unless every slot in the array is used.*/
#include<stdlib.h>
#define EmptyTOS1 (-1)
#define MinStackSize (5)
typedef int ElementType;
struct StackRecord;
typedef struct StackRecord* Stack;

struct StackRecord {//一个数组开两个栈，一个从前往后开，一个从后往前开
	int Capacity;
	int TopOfStack1;//栈一顶
	int TopOfStack2;//栈二顶
	ElementType* Array;//所用数组
};

int IsEmpty1(Stack s) {
	return s->TopOfStack1 == EmptyTOS1;//从前往后
}

int IsEmpty2(Stack s) {
	return s->TopOfStack2 == s->Capacity;//从后往前
}

int IsFull(Stack s) {
	return s->TopOfStack1 + 1 == s->TopOfStack2;//两个游标相遇，栈满 
}

Stack CreateStack(int MaxElements) {
	Stack s;
	if (MaxElements < MinStackSize)
		Error("Stack size is too small");
	s =(Stack)malloc(sizeof(struct StackRecord));
	if (s == NULL)
		Error("out of space");
	else {
		s->Array = malloc(sizeof(ElementType) * MaxElements);
		if (s->Array == NULL)
			Error("out of space");
		else {
			s->Capacity = MaxElements;
			MakeEmpty1(s);
			MakeEmpty2(s);
		}
	}
	return s;
}

void DisposeStack(Stack s) {
	if (s != NULL) {
		free(s->Array);
		free(s);
	}
}

void MakeEmpty1(Stack s) {
	s->TopOfStack1 = -1;//栈一游标移至最左端
}

void MakeEmpty2(Stack s) {
	s->TopOfStack2 = s->Capacity;//栈二游标移至最右端
}

void Push1(ElementType X, Stack s) {
	if (IsFull(s))
		Error("out of space");
	s->Array[++s->TopOfStack1] = X;//栈一从前往后push
}

void Push2(ElementType X, Stack s) {
	if (IsFull(s))
		Error("out of space");
	s->Array[--s->TopOfStack2] = X;//栈二从后往前push

}


ElementType Top1(Stack s) {
	if (IsEmpty1(s))
		Error("Empty stack");
	return s->Array[s->TopOfStack1];//栈一top
}

ElementType Top2(Stack s) {
	if (IsEmpty2(s))
		Error("Empty stack");
	return s->Array[s->TopOfStack2];//栈二top
}

void Pop1(Stack s) {
	if (IsEmpty1(s))
		Error("Empty stack");
	s->TopOfStack1--;//栈一从右往左pop
}

void Pop2(Stack s) {
	if (IsEmpty2(s))
		Error("Empty stack");
	s->TopOfStack2++;//栈二从左往右pop
}

ElementType TopAndPop1(Stack s) {
	if (IsEmpty1(s))
		Error("empty stack");
	return s->Array[s->TopOfStack1--];
}

ElementType TopAndPop2(Stack s) {
	if (IsEmpty2(s))
		Error("empty stack");
	return s->Array[s->TopOfStack2++];
}

/*3.25 Write the routines to implement queues using

a. linked lists

b. arrays*/

//a. linked lists

typedef struct Node* PtrToNode;
typedef struct Queue* PtrToQ;
struct Node {
	ElementType data;
	PtrToNode next;
};

struct Queue {
	PtrToNode rear;
	PtrToNode front;
};

PtrToQ CreateQ(void) {
	PtrToQ Q;
	Q = malloc(sizeof(struct Queue));
	Q->rear = Q->front = malloc(sizeof(struct Node));//申明队首节点
	Q->rear->next = NULL;
}

void AddQ(ElementType X, PtrToQ Q) {//入队操作
	PtrToNode TmpCell;
	Tmpcell = malloc(sizeof(struct Node));
	TmpCell->data = X;
	TmpCell->next = NULL;
	Q->rear->next = TmpCell;//入队
	Q->rear = TmpCell;//队尾指针后移
}

Elementtype DeleteQ(PtrToQ Q) {//出队并返回队首值
	ElementType res;
	PtrToNode TmpCell;
	TmpCell = Q->front->next;
	Q->front->next = TmpCell->next;
	res = Tmpcell->data;
	free(TmpCell);
	return res;
}

//b. arrays
//循环数组
#define MaxSize 100
struct Queue;
typedef struct Queue* PtrToQ;

struct Queue {
	ElementType* Array;
	int front;//队首游标
	int rear;//队尾游标
};
PtrToQ CreateQ(int Size) {
	PtrToQ Q;
	Q = malloc(sizeof(struct Queue));
	Q->Array = malloc(sizeof(ElementType) * Size);
	Q->front = Q->rear = 0;//队首=队尾=0；
	return Q;
}

int IsFull(PtrToQ Q) {
	return (Q->rear + 1) % MaxSize == Q->front;//首尾相遇则队列满
}

void AddQ(ElementType X, PtrToQ Q) {
	if (!IsFull(Q)) {
		Q->rear = (Q->rear + 1) % MaxSize;//队尾后移
		Q->Array[Q->rear] = X;//插入新元素
	}
	else
		Error("full")
}

int IsEmpty(PtrToQ Q) {
	return Q->rear == Q->front;//未存数时，首位游标相等
}

ElementType DeleteQ(PtrToQ Q) {
	if (!IsEmpty(Q)) {
		Q->front = (Q->front + 1) % MaxSize;//队首后移
		return Q->front->data;
	}
	else
		Error();
}

/*3.26 A deque is a data structure consisting of a list of items, on which the following operations are possible: 

push(x,d): Insert item x on the front end of deque d.

pop(d): Remove the front item from deque d and return it. 

inject(x,d): Insert item x on the rear end of deque d.

eject(d): Remove the rear item from deque d and return it.

Write routines to support the deque that take O(1) time per operation.*/

typedef struct Node* PtrToNode;
typedef struct Queue* PtrToQ;
struct Node {
	ElementType data;
	PtrToNode next;
};

struct Queue {
	PtrToNode rear;
	PtrToNode front;
};

PtrToQ CreateQ(void) {
	PtrToQ Q;
	Q = malloc(sizeof(struct Queue));
	Q->rear = Q->front = malloc(sizeof(struct Node));//申明队首节点
	Q->rear->next = NULL;
}

void Push(ElementType X, PtrToQ Q) {//将X插入到双端队列的前端
	PtrToNode TmpCell = (PtrToNode)malloc(sizeof(PtrToNode));
	TmpCell->data = X;
	Q->front->next = TmpCell;//加入前端
	Q->front = TmpCell;//队首前移
}

ElementType Pop(PtrToQ Q) {//出队并返回队首值
	ElementType res;
	PtrToNode TmpCell;
	TmpCell = Q->front->next;
	Q->front->next = TmpCell->next;
	res = Tmpcell->data;
	free(TmpCell);
	return res;//返回前端
}

void Inject(ElementType X, PtrToNode Q) {//将X插入队列尾端
	PtrToNode TmpCell;
	Tmpcell = malloc(sizeof(struct Node));
	TmpCell->data = X;
	TmpCell->next = NULL;
	Q->rear->next = TmpCell;//入队
	Q->rear = TmpCell;//队尾指针后移
}

ElementType Eject(PtrToNode Q) {//删除队尾并返回
	ElementType res;
	PtrToNode TmpCell;
	TmpCell = Q->rear;//记录队尾
	Q->rear = TmpCell->next;//移至下一个
	res = Tmpcell->data;
	free(TmpCell);//释放队尾
	return res;//返回前端
}