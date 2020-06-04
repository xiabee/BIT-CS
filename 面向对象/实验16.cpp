//第八周实验2	肖云杰	1120182349	07111827
#include<sstream>
#include<iostream>
#include<string>
using namespace std;

template<typename T,int n>//定义模板类
class Array
{
public:
	Array()
	{
		size = n;
		s = new T[size];
		for (int i = 0; i < size; i++)
			s[i] = 0;
	}
	Array(int num)
	{
		size = num;
		s = new T[size];
		for (int i = 0; i < size; i++)
			s[i] = 0;
	}
	T& operator[](int x)//重载[]
	{
		if (x >= 0 && x < size)
			return s[x];
		else
		{
			cout << "Out of range!" << endl;
			exit(-1);
		}
	}
	friend ostream& operator<< <>(ostream& os, const Array<T, n>& a);//重载<<
	friend istream& operator>> <>(istream& is, Array<T, n>& a);//重载>>
private:
	T* s;		//用于储存数组
	int size;	//记录长度
};

template <typename T, int n>
ostream& operator<<(ostream& os, const Array<T, n>& a)//重载<<
{
	for (int i = 0; i < a.size; i++)
	{
		os << a.s[i];
		if (i != a.size - 1)
			os << ", ";
	}
	os << endl;
	return os;
}

template <typename T, int n>
istream& operator>> (istream& is, Array<T, n>& a)//重载>>
{
	for (int i = 0; i < a.size; i++)
		is >> a.s[i];
	return is;
}
int main() {
	stringstream input("47 34 56 92 103");
	Array<int, 5>   a;
	input >> a;
	a[4] = -1;           // Use overloaded operator[]
	cout << a;
}

// output:
// 47, 34, 56, 92, -1