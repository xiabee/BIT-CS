// 实验8.cpp : 
//Create a class, CCircle, and finish the following functions as below:
#include <iostream>
#include<cmath>
using namespace std;

class CCircle
{
private:
	double X;
	double Y;
	double R;
public:
	CCircle();
	CCircle(double vr);
	CCircle(double vx,double vy);
	CCircle(double vx, double vy, double vr);
	~CCircle();
	double GetDis(const CCircle& a);//member funtion to calculate distance.
	double GetX() { return X; }
	double GetY() { return Y; }
	void Relationship(const CCircle& x);
};
double GetDis(const CCircle& a, const CCircle& b);//non-member funtion to calculate distance.

CCircle::CCircle()
{
	X = 0;
	Y = 0;
	R = 0;
}

CCircle::CCircle(double vr)
{
	X = 0;
	Y = 0;
	R = vr;
}

CCircle::CCircle(double vx, double vy)
{
	X = vx;
	Y = vy;
	R = 0;
}

CCircle::CCircle(double vx,double vy,double vr)
{
	X = vx;
	Y = vy;
	R = vr;
}
CCircle::~CCircle()
{
	cout << "CCircle destructor:" << "\tx:" << X << "\ty:" << Y << "\tR:" << R << endl;
}

double CCircle::GetDis(const CCircle &a)
{
	return sqrt((a.X - X) * (a.X - X) + (a.Y - Y) * (a.Y - Y));
}//member funtion to calculate distance.

double GetDis(CCircle& a, CCircle& b)
{
	return sqrt((a.GetX() - b.GetX()) * (a.GetX() - b.GetX()) + (a.GetY() - b.GetY()) * (a.GetY() - b.GetY()));
}//non-member funtion to calculate distance.

void CCircle::Relationship(const CCircle& x)
{
	double dis = GetDis(x);
	if (dis > R + x.R || dis < fabs(R - x.R))
		cout << "seperation" << endl;
	else if (dis == R + x.R)
		cout << "externally tangent" << endl;
	else if (dis == fabs(R - x.R))
		cout << "interally tangernt" << endl;
	else
		cout << "intersection" << endl;
}//to judge the relationship

int main()
{
	CCircle x(1.35, 2.78, 5), y(1.03, -0.51, 2);
	x.Relationship(y);
	cout << "The distance of the two points is: " << GetDis(x, y) << endl;
	return 0;
}

// output:
// intersection
// The distance of the two points is : 3.30553
// CCircle destructor : x:1.03  y : -0.51 R : 2
// CCircle destructor : x:1.35  y : 2.78  R : 5