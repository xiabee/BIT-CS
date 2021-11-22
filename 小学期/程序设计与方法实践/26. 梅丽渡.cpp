#include<stdio.h>
#define mian main //万一打错字
#define retrun return //这个虽然没错过.....但是凑齐两个好看一点
//看着头文件那么少就像多define几个/kk
//#define 输入 scanf
//#define 输出 printf		//只是想试一下能不能通过,。。。事实证明不能通过
long long n, GDP[4][500010] = { 0 }, ans, maxngg = 0, maxnkk = 0, maxntt = 0, ggag[500010] = { 0 }, i, j, k;//全部使用longlong避免VS报错
int v;//记录返回值
int main()
{
	v = scanf("%lld", &n);//v记录scanf返回值
	for (i = 1; i <= n; i++)
		v = scanf("%lld", &ggag[i]);//v记录scanf返回值，ggag用来记录美丽度
	GDP[1][1] = ggag[1];
	GDP[1][2] = (ggag[1] > maxngg ? ggag[1] : maxngg) + ggag[2];//初始化初始化初始化
	GDP[1][3] = (maxngg > GDP[1][2] ? maxngg : GDP[1][2]) + ggag[3];
	maxnkk = GDP[1][1] > GDP[1][2] ? GDP[1][1] : GDP[1][2];//初始化初始化初始化
	GDP[2][2] = ggag[1] + ggag[2];
	GDP[2][3] = (maxnkk > GDP[2][2] ? maxnkk : GDP[2][2]) + ggag[3];
	maxnkk = maxnkk > GDP[1][3] ? maxnkk : GDP[1][3];
	maxntt = GDP[2][2] > GDP[2][3] ? GDP[2][2] : GDP[2][3];//初始化初始化初始化
	GDP[3][3] = ggag[1] + ggag[2] + ggag[3];
	for (i = 4; i <= n; i++)//开始寻找
	{
		GDP[1][i] = GDP[1][i - 1] > maxngg ? GDP[1][i - 1] : maxngg; // 比较大小比较大小
		GDP[1][i] += ggag[i];
		GDP[2][i] = GDP[2][i - 1] > maxnkk ? GDP[2][i - 1] : maxnkk; // 比较大小比较大小
		GDP[2][i] += ggag[i];
		maxnkk = GDP[1][i] > maxnkk ? GDP[1][i] : maxnkk;
		GDP[3][i] = GDP[3][i - 1] > maxntt ? GDP[3][i - 1] : maxntt;// 比较大小比较大小
		GDP[3][i] += ggag[i];
		maxntt = GDP[2][i] > maxntt ? GDP[2][i] : maxntt;// 比较大小比较大小
	}
	ans = GDP[3][3];
	for (i = 4; i <= n; i++)//继续寻找
		if (GDP[3][i] > ans)
			ans = GDP[3][i];
	printf("%lld\n", ans);
}