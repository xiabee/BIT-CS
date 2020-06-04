#include<iostream> 
using namespace std;
void trans(void* vp, int num, int val) //类型转换，比较地址和值的变化
{
	char* p = static_cast<char*>(vp);
	for (int i = 0; i < num; i++) 
		*(p + i) = val;
	return;
}
int main() 
{
	int  Arry[10] = { 0 };
	void* p;
	cout << "Before transfer:" << Arry << endl;//转换之前的首地址
	p = static_cast <void*> (Arry);
	trans(p, 4, 1);
	cout << "After transfer:" << p << endl;//转换后的首地址
	cout << "Arry[0]:"<<Arry[0] << endl;//转换后的第一项
	return 0;
}