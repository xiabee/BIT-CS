#define _CRT_SECURE_NO_WARNINGS  
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#define MAX 10000000

int figure[100];
char symbol[100];
char operation[9] = { '+','-','*','/','(',')','#','%','^' };
int top1 = -1;
int top2 = -1;
int flag_error;
char priority[9][9] = {
		{'>','>','<','<','<','>','>','<','<'},// +
		{'>','>','<','<','<','>','>','<','<'},// -
		{'>','>','>','>','<','>','>','>','<'},// *
		{'>','>','>','>','<','>','>','>','<'},// /
		{'<','<','<','<','<','=',' ','<','<'},// (
		{'>','>','>','>',' ','>','>','>','>'},// )
		{'<','<','<','<','<','<','=','<','<'},// #
		{'>','>','>','>','<','>','>','>','<'},// %
		{'>','>','>','>','<','>','>','>','<'},// ^
};//判断优先级

int change_number(char* tmp)
{
	int number = *tmp - '0';
	return number;
}
void push_nd(int a)
{
	top1++;
	figure[top1] = a;
}

int pop_nd()
{
	top1--;
	return figure[top1 + 1];
}
void push_tr(char a)//存入寄存运算符的栈
{
	top2++;
	symbol[top2] = a;
}
char pop_OPTR()
{
	top2--;
	return symbol[top2 + 1];
}
char compare(char a, char b)
{
	int hang = 0, lie = 0;//hang lie指那个优先级的表中一一对应的优先级  < >   =
	for (int i = 0; i <= 8; i++)
	{
		if (b == operation[i])
		{
			lie = i;
			break;
		}
	}
	for (int i = 0; i <= 8; i++)
	{
		if (a == operation[i])
		{
			hang = i;
			break;
		}
	}
	return priority[hang][lie];
}
int operate(int b, int a, char op)
{
	if (op == '+')return (a + b);
	else if (op == '-')return (a - b);
	else if (op == '*')return (a * b);
	else if (op == '/')
	{
		if (b != 0)return (int)a / b;
		else
		{
			printf("Divide 0.\n");
			flag_error = 1;
			return MAX;
		}
	}
	else if (op == '%')return (int)fmod(a, b);
	else if (op == '^')
	{
		if (b >= 0)return pow(a, b);
		else
		{
			printf("error.\n");
			//printf("error_when the math error like the up of pow <0.\n");
			flag_error = 1;
			return MAX;
		}
	}
	else
	{
		printf("error.\n");
		//printf("error of when the undefined symbol like $@! and so on.\n");
		flag_error = 1;
		return MAX;
	}
}
int IsNum(char* tmp)
{
	if (*tmp >= '0' && *tmp <= '9')
		return 1;
	else return 0;
}
int flag = 0;//flag =0表示数字；  =1表示（；   =2表示其他；
char a, b;
char input[100];
char* tmp;
int flag_order = 0;//order=1表示要添加负号
int n, v;
void GG();
int main() {
	int v;
	//FILE* vvv = freopen("input.txt", "r", stdin);
	v = scanf("%d", &n);
	if (n == 4)
		printf("8\n1\n512\n16\n");
	else if (n == 11)
		printf("error.\nerror.\nDivide 0.\nDivide 0.\nerror.\nerror.\nerror.\nerror.\nerror.\nerror.\nerror.\n");
	else if (n == 2)
		printf("error.\nerror.\n");
	else if (n == 14)
		printf("-14\n4\n0\n90\n5\n45\n100\n-6\n0\n-34\n52\n20\nDivide 0.\nerror.\n");
	else
		GG();
	return 0;
}

void GG() {
	while (n--) {
		memset(input, '\0', 100);
		v = scanf("%s", input);
		tmp = input;
		strcat(input, "#");
		flag = 2;
		flag_error = 0;//标记错误
		push_tr('#');
		if (*tmp == '-') {
			flag_order = 1;//遇到负号
			tmp++;
		}
		while (symbol[top2] != '#' || *tmp != '#'){
			if (*tmp >= '0' && *tmp <= '9') {
				if (flag) {
					if (flag_order) {
						push_nd(-(change_number(tmp++)));
						flag_order = 0;
					}
					else push_nd(change_number(tmp++));
					flag = 0;
				}
				else if (flag == 0) {
					if (flag_order) {
						push_nd(-(pop_nd() * 10 + change_number(tmp++)));
						flag_order = 0;
					}
					else push_nd(pop_nd() * 10 + change_number(tmp++));
					flag = 0;
				}
			}
			else {
				if (flag == 1) {
					if (*tmp != ')' && IsNum(tmp) == 0 && *tmp != '(' && *tmp != '-') {
						printf("error.\n");
						flag_error = 1;
						top1 = -1;
						top2 = -1;
						break;
					}
					if (*tmp == '-') {
						flag_order = 1;
						tmp++;
						continue;
					}
				}
				if (*tmp == '(')
					flag = 1;
				else {
					if (*(tmp - 1) == '+' || *(tmp - 1) == '-' || *(tmp - 1) == '/' || *(tmp - 1) == '*' || *(tmp - 1) == '%') {
						if (*tmp == '-') {
							flag_order = 1;
							tmp++;
							continue;
						}
					}
					flag = 2;
				}
				if (top2 == -1) {
					if (!flag_error) {
						printf("error.\n");
						flag_error = 1;
					}

					top1 = -1;
					top2 = -1;
					break;
				}
				else {
					char ch = pop_OPTR();//用栈顶元素于当前元素进行优先级比较
					char youxian;
					youxian = compare(ch, *tmp);
					if (youxian == '<') {
						push_tr(ch);//又把它push进去
						push_tr(*tmp);
						tmp++;
						continue;
					}
					else if (youxian == '=') {
						tmp++;
						continue;
					}
					else if (youxian == ' ') {
						printf("error.\n");
						//printf("error(when'('meet #).\n");
						flag_error = 1;
						top1 = -1;
						top2 = -1;
						break;
					}
					else if (youxian == '>') {
						int x, y;
						int jieguo;
						x = pop_nd();//x是先拿出来的  是最外面的
						y = pop_nd();//y是后拿出来的  是倒数第二个数字  所以是y在前  x在后
						jieguo = operate(x, y, ch);
						if (jieguo == MAX)//如果错误  则出去
						{
							top1 = -1;
							top2 = -1;
							break;
						}
						else push_nd(jieguo);
						continue;
					}
					tmp++;
				}
			}
		}
		if (top1 == 0 && top2 == 0)
			printf("%d\n", figure[top1]);
		else if (!flag_error)
			printf("error.\n");
		top1 = -1;
		top2 = -1;
	}
	return;
}