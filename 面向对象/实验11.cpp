#include<iostream>
using namespace std;

int len(const char* str)
{
	int count = 0;
	while (str[count] != '\0')
		count++;
	return count;
}//计算字符串长度，不包含'\0'

class CMyString
{
public:
	CMyString()
	{
		str = NULL;
		length = 0;
	}
	CMyString(int n)
	{
		str = new char[n + 1];
		length = n;
	}
	CMyString(const char* s)
	{
		length = len(s);
		str = new char[length + 1];
		for (int i = 0; i < length; i++)
			str[i] = s[i];
		str[length] = '\0';
	}
	CMyString(const char s)
	{
		length = 1;
		str = new char[2];
		str[0] = s;
		str[1] = '\0';
	}
	~CMyString() {}

	int Getlen() { return length; }
	CMyString& operator=(const CMyString &s1)
	{
		length = s1.length;
		if (str)
		{
			delete[]str;
			str = NULL;
		}//释放原内容
		str = new char[length + 1];	//创建新内存
		for (int i = 0; i < length; i++)
			str[i] = s1.str[i];
		str[length] = '\0';
		return *this;
	}//类的赋值
	CMyString& operator=(const char* s1)
	{
		length = len(s1);
		if (str)
		{
			delete[]str;
			str = NULL;
		}
		str = new char[length + 1];
		for (int i = 0; i < length; i++)
			str[i] = s1[i];
		str[length] = '\0';
		return *this;
	}

	friend ostream& operator<<(ostream& os, const CMyString& a)
	{
		for (int i = 0; i < a.length; i++)
			os << a.str[i];
		os << endl;
		return os;
	}//重载<<流输出

	friend CMyString operator+(const char* s, const CMyString& a)
	{
		int l = len(s);
		int n = l + a.length;
		CMyString res(n);//创建新对象
		for (int i = 0; i < n; i++)
		{
			if (i < l)
				res.str[i] = s[i];
			else
				res.str[i] = a.str[i - len(s)];
		}
		res.str[n] = '\0';
		return res;
	}//string + CMyString
	friend CMyString operator+(const CMyString& a, const char* s)
	{
		int l = len(s);
		int n = l + a.length;
		CMyString res(n);//创建新对象
		for (int i = 0; i < n; i++)
		{
			if (i < a.length)
				res.str[i] = a.str[i];
			else
				res.str[i] = s[i - a.length];
		}
		res.str[n] = '\0';
		return res;
	}//CMyString + string
	friend CMyString operator+(const CMyString& a, const CMyString& b)
	{
		int n = a.length + b.length;
		CMyString res(n);
		for (int i = 0; i < n; i++)
		{
			if (i < a.length)
				res.str[i] = a.str[i];
			else
				res.str[i] = b.str[i - a.length];
		}
		res.str[n] = '\0';
		return res;
	}//CMyString + CMyString

	int  Find(const CMyString& sub)
	{
		int n = sub.length;
		for (int i = 0; i < length - n + 1; i++)
		{
			if (str[i] == sub.str[0])//遇到第一个相同字符
			{
				int flag = 0;
				for (int j = 1; j < n; j++)
					if (str[i + j] != sub.str[j])
					{
						flag = 1;
						break;
					}
				if(!flag)
					return i;
			}
		}
		return -1;//得到子串sub在当前字符串中第一次出现的位置
	}

	int LastFind(const CMyString& sub)
	{
		int n = sub.length;
		for (int i = length - 1; i >= n - 1; i--)
		{
			if (str[i] == sub.str[n - 1])//遇到第一个相同字符
			{
				int flag = 0;
				for (int j = n - 1; j > 0; j--)
					if (str[i + j - 1] != sub.str[j])
					{
						flag = 1;
						break;
					}
				if (!flag)
					return i - n + 1;
			}
		}
		return -1;
	}//得到子串sub在当前字符串中最后一次出现的位置

	CMyString  Mid(int start, int length)
	{
		
		if (start > length)//超出字符串长度范围
		{
			cout << "NULL!" << endl;
			CMyString res;//res字符指针为NULL
			return res;
		}
		else
		{
			CMyString res(length);
			for (int i = 0; i < length; i++)
			{
				res.str[i] = str[i + start];
				if (str[i + start] == '\0')//遇到结束符则提前结束拷贝
					break;
			}
			return res;
		}
	}
private:
	char* str;
	int length;
};


int main()
{
	CMyString s1("China"), s2, s3;
	s2 = "Love";
	cout << "I " + s2 + " " + s1 + "!"; // The output is: I Love China!

	int pos = s1.Find('a');      // pos is 4, or -1 if  'a'  is NOT found.
	cout << pos << endl; 

	int a = 2, b = 2;
	CMyString my = s1.Mid(a, b); // A string in the my is "in".
	cout << my;
}

// output:
// I Love China!
// 4
// in
