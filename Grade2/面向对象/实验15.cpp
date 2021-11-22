//在声明交通工具时，需要定义距离和重量两个参数
#include<iostream>
using namespace std;

class Vehicle
{
public:
	virtual double Fee() = 0;
	Vehicle(double distan,double weight)
	{
		dis = distan;
		wei = weight;
	}//声明距离和重量
	virtual ~Vehicle()
	{
		//cout << "~Vehicle()" << endl;
	}
	double di() { return dis; }
	double we() { return wei; }
	string mod() { return mode; }
protected:
	double dis;
	double wei;
	string mode;
};

class Plane:public Vehicle
{
public:
	Plane(double d, double w) :Vehicle(d, w)
	{
		mode = "plane";
	}
	virtual double Fee()
	{
		return dis * 1.15 + wei * 1.05;
	}
	virtual ~Plane()
	{
		//cout << "~Plane()" << endl;
	}
};

class Ship :public Vehicle
{
public:
	Ship(double d, double w) :Vehicle(d, w)
	{
		mode = "ship";
	}
	virtual double Fee()
	{
		return dis * 1.05 + wei * 0.9;
	}
	virtual ~Ship()
	{
		//cout << "~Ship()" << endl;
	}
};

class Automobile :public Vehicle
{
public:
	Automobile(double d, double w) :Vehicle(d, w)
	{
		mode = "car";
	}
	virtual double Fee()
	{
		return dis * 1.2 + wei * 1.1;
	}
	virtual ~Automobile()
	{
		//cout << "~Automobile()" << endl;
	}
};

int main()
{
	Plane plane(200, 20);
	Ship ship(256, 89);
	Automobile car(198, 235);
	cout << "Mode\t" << "dis\t" << "weight\t" << "Fee" << endl;
	cout << "----\t" << "----\t" << "----\t" << "----\t" << endl;

	cout << plane.mod() << '\t' << plane.di() << '\t' << plane.we() << '\t' << plane.Fee() << endl;
	cout << ship.mod() << '\t' << ship.di() << '\t' << ship.we() << '\t' << ship.Fee() << endl;
	cout << car.mod() << '\t' << car.di() << '\t' << car.we() << '\t' << car.Fee() << endl;
	
	cout << "----\t" << "----\t" << "----\t" << "----\t" << endl;
	//主函数输出样例
	return 0;
}

// output:
// Mode    dis     weight  Fee
// ----    ----    ----    ----
// plane   200     20      251
// ship    256     89      348.9
// car     198     235     496.1
// ----    ----    ----    ----