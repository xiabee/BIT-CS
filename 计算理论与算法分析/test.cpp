#include<iostream>
#include<fstream>
#include<typeinfo>
using namespace std;
int main()
{
	int a[1000];
	int n;
	ifstream infile;
	ofstream outfile;
	infile.open("input.txt");
	infile >> n;
	infile.close();
	//文件读取
	int sum = 0, l = 0, left = 0;//l为从左向右计数器，left为剩余量
	int mul = 1;//记录乘积
	for (int i = 2; i <= n; i++)
	{
		a[l++] = i;
		sum += i;
		if (sum > n)
		{
			sum -= i, l--, left = n - sum;//回溯一次
			break;
		}
	}//从2到n分解
	for (int i = l - 1; left > 0; left--)
	{
		a[i]++;
		i--;
		if (i < 0) 
			i = l - 1;
	}//尽可能补全为相近的数

	for (int i = 0; i < l - 1; i++)
		mul *= a[i];
	if (l - 1 >= 0)
		mul *= a[l - 1];//计算乘积

	cout << mul << endl;
	outfile.open("output.txt");
	outfile << mul << endl;
	outfile.close();
	//写入文件
	return 0;
}