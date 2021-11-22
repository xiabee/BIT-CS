#include "equation.h"
FindRoot::FindRoot(double x, double y, double z)
{
	a = x;
	b = y;
	c = z;
	delta = b * b - 4 * a * c;
	x1 = 0;
	x2 = 0;
}//分别传入三个参数的值，并计算判别式

void FindRoot::Find()
{
	if (delta > 0)
	{
		x1 = (-b + sqrt(delta)) / (2 * a);
		x2 = (-b - sqrt(delta)) / (2 * a);
		return;
	}//判别式大于零时，求根公式直接计算

	else if (delta == 0)
	{
		x1 = x2 = (-b) / (2 * a);
		return;
	}//求根公式直接计算

	else
	{
		x1 = (-b) / (2 * a);
		x2 = sqrt(-delta) / (2 * a);
	}//判别式小于零时，x1,x2分别记录解的实部和虚部
}

void FindRoot::Display()
{
	cout << endl;
	if (delta > 0)
	{
		cout << "x1=" << x1 << "\nx2=" << x2 << endl;
		return;
	}
	else if (delta == 0)
	{
		cout << "x1=x2=" << x1 << endl;
		return;
	}
	else
	{
		cout << "x1=" << x1 << "+" << x2 << "i" << endl;
		cout << "x2=" << x1 << "-" << x2 << "i" << endl;
	}//复数解的输出
	cout << endl;
}
void Read(double& a, double& b, double& c)
{
	cout << "Input equation coefficient a:";
	cin >> a;
	if (a == 0)
	{
		int trs = getchar();
		return;
	};
	cout << "Input equation coefficient b:";
	cin >> b;
	cout << "Input equation coefficient c:";
	cin >> c;
}

int main()
{
	double a, b, c;
	cout << "This is a program to find the root of equation ax2+bx+c=0:\n(press '0' to exit.)\n" << endl;
	for (;;)//循环计算方程的解
	{
		Read(a, b, c);
		if (a == 0) 
			return 0;
		FindRoot obj(a, b, c);//创建方程对象
		obj.Find();
		obj.Display();
	}
	return 0;
}
