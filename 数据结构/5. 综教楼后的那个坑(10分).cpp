#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#define maxn 100005
typedef struct LIT_2 {
	long long data;
	long long height;
	long long width;
	struct LIT_2* next;
	struct LIT_2* pre;
}node;
//FILE* p = freopen("input.txt", "r", stdin);
long long answer[maxn];
node* left, * right, * prehole, * rear, * depth;
long long n, a, b, v;

node* Creat_list();
void Oper();

int main() {//这个亚子就显得主函数很简洁/cy
	Creat_list();
	Oper();
	return 0;
}//然而调用函数就贼扯

node* Creat_list() {//创建链表
	left = (node*)malloc(sizeof(node));
	if (NULL == left)//如果内存分配失败
		return 0;
	left->width = 0;//归零
	left->height = maxn;//设为无穷大
	left->pre = left->next = NULL;//两端指向NULL
	prehole = left;
	depth = left;
	v = scanf("%lld", &n);//v记录返回值
	rear = (node*)malloc(sizeof(node));
	if (NULL == rear)//再次判断内存是否分配
		return 0;
	for (long long i = 0; i < n; i++) {
		v = scanf("%lld%lld", &a, &b);//v记录返回值
		rear = (node*)malloc(sizeof(node));
		if (NULL == rear)
			return 0;
		rear->width = a;//赋值
		rear->height = b;//赋值
		rear->pre = prehole;
		rear->next = NULL;
		rear->data = i;//赋值

		prehole->next = rear;
		prehole = rear;

		if (depth->height > b)//判断是否溢出
			depth = rear;
	}
	right = (node*)malloc(sizeof(node));
	if (NULL == right)//判断内存是否分配成功
		return 0;
	right->width = 0;
	right->height = maxn;
	right->pre = rear;//成对操作
	rear->next = right;
	right->next = NULL;//成对操作
	return left;
}
void Oper() {
	long long time_gg = 0;
	if (depth->pre == NULL || depth->next == NULL)
		return;
	while (depth->pre->height != depth->next->height) {//开始循环，直到水溢出
		answer[depth->data] = time_gg + depth->width;//时间相加
		if (depth->pre->height > depth->next->height) {//前项高于后项
			time_gg  += (depth->next->height - depth->height) * depth->width;//计算剩余体积
			depth->next->width += depth->width;//宽度变化
			depth->pre->next = depth->next;//深度变化
			depth->next->pre = depth->pre;//指针移动
			depth = depth->next;//指针后移
		}
		else {//后项高于前项
			time_gg += (depth->pre->height - depth->height) * depth->width;//计算剩余体积
			depth->pre->width += depth->width;//宽度变化
			depth->pre->next = depth->next;
			depth->next->pre = depth->pre;
			depth = depth->pre;//指针前移
		}

		if (depth->height < depth->pre->height && depth->height < depth->next->height)
			continue;
		else if (depth->pre->height > depth->next->height) {
			while (depth->height > depth->next->height)
				depth = depth->next;//指针后移
		}
		else {
			while (depth->height > depth->pre->height)
				depth = depth->pre;//指针前移
		}
	}
	answer[depth->data] = time_gg + depth->width;

	for (long long i = 0; i < n; i++) {
		printf("%lld\n", answer[i]);//逐个输出
	}
	return;
}
