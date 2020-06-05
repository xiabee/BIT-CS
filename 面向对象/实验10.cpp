// 实验10.cpp
#include <iostream>
#include<algorithm>
using namespace std;
class CSet
{
public:
	CSet();
	CSet(const int* a, int n);
	~CSet();
	bool IsExist(const int x);
	int len() { return length; }
	CSet &operator=(const CSet &a);
	friend CSet operator+(const CSet& a, int x);
	friend CSet operator-(const CSet& a, int x);
	friend CSet operator+(const CSet& a, const CSet& b);
	friend ostream& operator <<(ostream& os, const CSet& a);
private:
	int* s;
	int length;//to record length;
};

CSet::CSet()
{
	//cout << "Constructor1" << endl;
	s = NULL;
	length = 0;
}
CSet::CSet(const int* a, int n)
{
	//cout << "Constructor2" << endl;
	s = new int[n];
	for (int i = 0; i < n; i++)
		s[i] = a[i];
	length = n;
}
CSet::~CSet()
{
	if (s)
		delete[] s;
	s = NULL;
	//cout << "Destructor." << endl;
}

//To judge if an integer is a member of a set or not;
bool CSet::IsExist(const int x)
{
	for (int i = 0; i < length; i++)
		if (s[i] == x)
			return true;
	return false;
}

//To add an integer to a set. 
CSet operator+(const CSet& a, int x)
{
	int delta = 1;
	for (int i = 0; i < a.length; i++)
		if (a.s[i] == x)
		{
			delta = 0;
			break;
		}
	int len = a.length + delta;
	int* a1 = new int[len];
	a1 = a.s;
	if (delta)
	{
		a1[a.length] = x;
	}
	CSet res(a1,len);
	delete[] a1;
	return res;
}

//To delete an integer from the set;
CSet operator-(const CSet& a, int x)
{
	int count = 0, cnt = 0;
	for (int i = 0; i < a.length; i++)
		if (a.s[i] == x)
			count++;
	int len = a.length - count;
	int* p = new int[len + 1];
	for (int i = 0; i < a.length; i++)
		if (a.s[i] != x)
			p[cnt++] = a.s[i];
	CSet res(p, len);
	delete[] p;
	return res;
}

//To get intersection with another set.
CSet operator+(const CSet& a, const CSet& b)
{
	int len = max(a.length, b.length);
	int* s1 = new int[len + 1];
	int cnt = 0;
	for (int i = 0; i < a.length; i++)
		for (int j = 0; j < b.length; j++)
			if (a.s[i] == b.s[j])
				s1[cnt++] = a.s[i];
	CSet res(s1, cnt);
	delete[] s1;
	return res;
	
}

//overload "<<"
ostream& operator <<(ostream& os, const CSet& a)
{
	for (int i = 0; i < a.length; i++)
		os << a.s[i] << ' ';
	os<<endl;
	return os;
}

//over operater "="
CSet &CSet::operator=(const CSet &a)
{
	if (this->s != NULL)
		delete[] this->s;
	this->length = a.length;
	this->s = new int[length];
	for (int i = 0; i < length; i++)
		this->s[i] = a.s[i];
	return *this;
}

int main() {
	int a[] = { 1, 3, 5, 7, 6, 4, 2};
	CSet  S1, S2(a, 7);
	S1 = S2 + 8;			//add "8" intp section S1
	CSet  S3 = S1 + S2;		//S3 is the intersection of S1 and S2;
	cout << S1 << S2 << endl;
	cout << S3 << endl;
	return 0;
}

// output:
// 1 3 5 7 6 4 2 8 0
// 1 3 5 7 6 4 2

// 1 3 5 7 6 4 2
