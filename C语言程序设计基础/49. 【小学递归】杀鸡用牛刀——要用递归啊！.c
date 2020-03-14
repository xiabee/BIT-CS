#include <stdio.h>
#include <stdlib.h>

/*背景：
哈哈！我们终于学了递归了，现在大家一定感到非常有意思吧，
那个典型的“汉诺塔”问题，一个非常短的程序居然可以完成如此复杂的工作，真是神奇啊！
来吧，让我们也动手编写一个递归程序，当然，我们要编写的不可能太复杂。

功能：
    求整数 n 到 m 区间的累加和，其中n<=m。

输入：
    区间的起始点n   区间的终止点m

输出：
    累加和

要求：
    使用递归算法完成。如此简单的题目当然要有隐含的测试用例啦，就3个，看看谁能猜出来。*/

int main(int argc, char *argv[]) {
	int n,m,sum;
	int addsum(int n,int m);
	scanf("%d %d",&n,&m);
	sum=addsum(n,m);
	printf("The sum from %d to %d is %d.\n",n,m,sum);
	return 0;
}
int addsum(int n,int m){
	int sum=0;
	if(n<=m) sum=addsum(n+1,m)+n;
	else sum=0;
	return sum;
}
