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
char priority[9][9] ={
//    +   -   *   /   (   )   #   %   ^
    {'>','>','<','<','<','>','>','<','<'},// +
    {'>','>','<','<','<','>','>','<','<'},// -
    {'>','>','>','>','<','>','>','>','<'},// *
    {'>','>','>','>','<','>','>','>','<'},// /
    {'<','<','<','<','<','=',' ','<','<'},// (
    {'>','>','>','>',' ','>','>','>','>'},// )
    {'<','<','<','<','<','<','=','<','<'},// #
    {'>','>','>','>','<','>','>','>','<'},// %
    {'>','>','>','>','<','>','>','>','<'},// ^
};//优先级的表 相等的抵消

int change_number(char *p)
{
	int number = *p - '0'; 
	return number;
}
void push_OPND(int a)
{
	top1++;
	figure[top1] = a;
}

int pop_OPND()
{
	top1--;
	return figure[top1+1];
}
void push_OPTR(char a)//存入寄存运算符的栈
{
	top2++;
	symbol[top2] = a;
}
char pop_OPTR()
{
	top2--;
	return symbol[top2+1];
}
char compare(char a, char b)
{
	int hang=0,lie=0;//hang lie指那个优先级的表中一一对应的优先级  < >   =
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
	else if (op == '*')return (a*b);
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
int is_figure(char *p)
{
	if (*p >= '0' && *p <= '9')
		return 1;
	else return 0;
}
int main()
{
	//FILE* vvv = freopen("input.txt", "r", stdin);
	int n;
	scanf("%d", &n);
	int flag = 0;//flag =0表示数字  =1表示（   =2表示其他
	char a, b;
	char expression[100];
	char *p;
	int flag_bianhao = 0;//bianhao=1表示要把一个数字变为负号
	while (n--)
	{
		memset(expression, '\0', 100);
		scanf("%s", expression);
		p = expression;
		strcat(expression, "#");
		flag = 2;
		flag_error = 0;//用来记录打印错误的  如果出现错误  让flag_error=1，之后就不用再打印了
		push_OPTR('#');
		if (*p == '-')
		{
			flag_bianhao = 1;//如果第一个是-号
			p++;
		}
		while (symbol[top2] != '#' || *p != '#')
		{
			if (*p >= '0' && *p <= '9')//如果a是数字  就存入数字栈中
			{
				if (flag)//如果flag！=0就是前面不是数字 就不用
				{
					if (flag_bianhao)
					{
						push_OPND(-(change_number(p++)));
						flag_bianhao = 0;
					}
					else push_OPND(change_number(p++));
					flag = 0;
				}
				else if (flag == 0)//表示前面这个字符是数字
				{
					if (flag_bianhao)
					{
						push_OPND(-(pop_OPND() * 10 + change_number(p++)));
						flag_bianhao = 0;
					}
					else push_OPND(pop_OPND() * 10 + change_number(p++));
					flag = 0;
				}
			}
			else//如果不是数字  就可能使#或者运算符和（）
			{
				if (flag == 1)//如果前面是（  则后面只能是数字和）和-  其他的全错
				{//就是  如果前面是（  后面：不是）且不是数字且不是）且不是-
					if (*p!=')'&& is_figure(p)==0 && *p!='(' && *p!='-')//既不是）也不是数字  就错误  但是如果是（ 也可以
					{
						//printf("error(when the front is '('but the next is not ')'or figure.\n");//然后后面的已经不用再继续了 等式错误  直接读操作下一个表达式
						printf("error.\n");
						flag_error = 1;
						top1 = -1;
						top2 = -1;
						break;
					}
					if (*p == '-')
					{
						flag_bianhao = 1;
						p++;
						continue;
					}
				}//如果前面是(
			    if (*p == '(')flag = 1;//如果现在是（
				else//如果现在不是（  前面不是数字  （因为读到数字就要继续读下一个  而读到合法的符号  就要开始操作了）
				{
					if (*(p - 1) == '+' || *(p - 1) == '-' || *(p - 1) == '/' || *(p - 1) == '*' || *(p - 1) == '%')
					{
						if (*p == '-')
						{
							flag_bianhao = 1;
							p++;
							continue;
						}
					}
					flag = 2;
				}

				if (top2 == -1)
				{
					if (!flag_error)//如果它为零 才打印  如果它不为0说明之前已经打印过了
					{
						//printf("error__emmmm.\n");
						printf("error.\n");
						flag_error = 1;
					}
					top1 = -1;
					top2 = -1;
					break;
				}
				else //然后就可以展开运算
				{
					char ch = pop_OPTR();//用栈顶元素于当前元素进行优先级比较
					char youxian;
					youxian = compare(ch, *p);
					if (youxian == '<')//如果符号中栈顶元素优先级小于当前元素 当前元素入栈
					{
						push_OPTR(ch);//又把它push进去
						push_OPTR(*p);
						p++;
						continue;
					}
					else if (youxian == '=')//如果相等  （也只有（）才会是= ） 直接消掉就好  那就是不用处理了 因为（已经拿出来了
					{
						p++;
						continue;
					}
					else if (youxian == ' ')//如果不合法
					{
						printf("error.\n");
						//printf("error(when'('meet #).\n");
						flag_error = 1;
						top1 = -1;
						top2 = -1;
						break;
					}
					else if (youxian == '>')//如果栈顶元素优先级大  就进行运算
					{
						int x, y;
						int jieguo;
						x = pop_OPND();//x是先拿出来的  是最外面的
						y = pop_OPND();//y是后拿出来的  是倒数第二个数字  所以是y在前  x在后
						jieguo = operate(x, y, ch);
						if (jieguo == MAX)//如果错误  则出去
						{
							top1 = -1;
							top2 = -1;
							break;
						}
						else push_OPND(jieguo);
						continue;
					}
					p++;
				}
			}
		}
		if (top1 == 0 && top2 == 0)printf("%d\n", figure[top1]);
		else if(!flag_error)printf("error.\n");
		top1 = -1;
		top2 = -1;
	}
	//system("pause");
	return 0;
	
}
