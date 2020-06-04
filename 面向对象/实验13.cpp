//第七周 第一次 实验题
// 肖云杰 1120182349 07111807

//说明:salary为Employee基础薪资，pay()为计算各个类的月薪，默认的salary为0
#include<iostream>
#include<string>
using namespace std;

class Employee
{
public:
	string name;
	string identity = "Employee";
	Employee()
	{
		name = "default";
		salary = 0;
	}
	Employee(string s)
	{
		name = s;
		salary = 0;
	}
	Employee(string s, int x)
	{
		name = s;
		salary = x;
	}
	Employee(int x, string s)
	{
		name = s;
		salary = x;
	}//多个构造函数，构造Employee类
	~Employee() {};

	virtual int pay() { return salary; }//定义虚函数

private:
	int salary;//基础薪资
};

class Technican :virtual public Employee
{
public:

	Technican() :Employee()
	{
		working_time = 0;
		identity = "Technican";
	}
	Technican(string s) :Employee(s)
	{
		working_time = 0;
		identity = "Technican";
	}
	Technican(string s, int work_t) :Employee(s)
	{
		identity = "Technican";
		working_time = work_t;
	}//初始化工作时间
	~Technican() {};
	void work(int n)
	{
		this->working_time += n;
	}//工作时间增加n小时
	int pay() { return Employee::pay() + working_time * 100; }

private:
	int working_time;
};

class Manager :virtual public Employee
{
public:
	Manager() :Employee()
	{
		identity = "Manager";
	}
	Manager(string s) :Employee(s)
	{
		identity = "Manager";
	}//固定月薪
	~Manager() {}
	int pay() { return Employee::pay() + 7000; }
};

class Salesman :virtual public Employee
{
public:
	Salesman() :Employee()
	{
		identity = "Salesman";
		monthly_sales = 0;
	}
	Salesman(string s) :Employee(s)
	{
		identity = "Salesman";
		monthly_sales = 0;
	}
	Salesman(string s, int sales) :Employee(s)
	{
		identity = "Salesman";
		monthly_sales = sales;
	}//销售人员月薪和销售额相关
	~Salesman() {}
	int pay() { return Employee::pay() + monthly_sales * 0.05; }
private:
	int monthly_sales;//月销售额
};

class SalesManager :public Manager, public Salesman
{
public:
	SalesManager() :Employee()
	{
		identity = "SalesManager";
		monthly_sales = 0;
	}
	SalesManager(string s, int sales) :Employee(s)
	{
		identity = "SalesManager";
		monthly_sales = sales;
	}//销售经理月薪
	~SalesManager() {};
	int pay() { return Employee::pay() + 4000 + monthly_sales * 0.005; }
private:
	int monthly_sales;
};

int main()
{
	Employee Jack("Jack");
	Technican Tom("Tom", 300);
	Manager Jerry("Jerry");
	Salesman Sherry("Sherry", 2e6);
	SalesManager Amy("Amy", 2e6);
	//声明各个对象
	cout << "Identity\tName\tSalary" << endl;
	cout << "----------\t|----\t|----" << endl;
	cout << Jack.identity << "\t|" << Jack.name << "\t|" << Jack.pay() << endl;
	cout << Tom.identity << "\t|" << Tom.name << "\t|" << Tom.pay() << endl;
	cout << Jerry.identity << "\t\t|" << Jerry.name << "\t|" << Jerry.pay() << endl;
	cout << Sherry.identity << "\t|" << Sherry.name << "\t|" << Sherry.pay() << endl;
	cout << Amy.identity << "\t|" << Amy.name << "\t|" << Amy.pay() << endl;
	//测试输出
}

// output:
// Identity        Name    Salary
// ----------      |----   |----
// Employee        |Jack   |0
// Technican       |Tom    |30000
// Manager         |Jerry  |7000
// Salesman        |Sherry |100000
// SalesManager    |Amy    |14000