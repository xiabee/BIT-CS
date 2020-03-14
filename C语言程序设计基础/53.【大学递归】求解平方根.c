#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*小明上来大学，学习了用求解平方根的迭代公式。

其中：p 为 x 的近似平方根，e 是结果允许的误差。

输入：x, e
输出：p  保留小数点后 8 位。*/

int main(int argc, char *argv[]) {
	double x,e,p,Sqrt(double x,double p,double e); 
	scanf("%lf %lf",&x,&e);
	p=Sqrt(x,x,e);
	printf("%.8lf\n",p);
	return 0;
}
double Sqrt(double x,double p,double e){
	if(abs(p*p-x)<e) p=x;
	else p=Sqrt(x,(p+x/p)/2,e);
	return p;
}
