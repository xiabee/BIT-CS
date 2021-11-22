//按此思路，三角函数  为成员函数，而拥有该三角函数的  角  则为类/对象。于是，可以重新封装常见三角函数如下：

#include "iostream"
#include "cmath"
using namespace std;

class CAngle
{
private:  double m_dAlpha;
public:
	CAngle(void);  //缺少构造函数
	CAngle(double a);  //构造函数
	CAngle(const CAngle& a);//拷贝构造函数
	double GetAlpha(void);  //返回角的角度值（弧度）
	double GetSin(void);  //返回角的正弦值
	double GetCos(void);  //返回角的余弦值
};

CAngle::CAngle(void)
{
	m_dAlpha = 0;
}

CAngle::CAngle(double a)
{
	m_dAlpha = a;
}

CAngle::CAngle(const CAngle& a)
{
	m_dAlpha = a.m_dAlpha;
}

double CAngle::GetAlpha(void)
{
	return m_dAlpha;
}

double CAngle::GetSin(void)
{
	return sin(m_dAlpha);
}

double CAngle::GetCos(void)
{
	return cos(m_dAlpha);
}

void Print1(CAngle a)
{
	cout << a.GetCos() << endl;
}

void Print2(CAngle& a)
{
	cout << a.GetCos() << endl;
}

int main()
{
	CAngle aa(3.1415926);
	Print1(aa);
	Print2(aa);
	return 1;
}

