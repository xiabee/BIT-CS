#include <stdio.h>
#include <stdlib.h>
#include <math.h>
/*题目描述
欢迎参加程序设计竞赛~
程序设计竞赛中有着很多有意思的问题，其中，与三角形有关的问题就经常出现。
今天你要解决的，就是其中最简单的一个问题：
给定平面直角坐标系上的N个点，保证这N个点中任意三点都不共线。
求任意三点能够构成的三角形中，面积最大的三角形的面积。

输入
输入的第一行是一个整数T（1 <= T <= 10），表示一共有T组用例。
每组用例的第一行为一个整数N（3 <= n <= 100），表示平面上点的个数。
接下来的N行，每行包含两个用空格隔开的整数Xi和Yi（-1000 <= Xi, Yi <= 1000），
表示第i个点的坐标（Xi, Yi）。

输出 
每组用例输出一个数，表示最大的三角形的面积，结果保留一位小数。

输入样例
2
4
-1 1
1 1
1 -1
-1 -1
3
-1 -1
3 0
0 0
输出样例
2.0
1.5*/

int main(int argc, char *argv[]) {
	static struct dot{
	    signed int x,y;
	}dot[100];
	static struct plane{
		int num;
		float s;
		struct dot dot[100];
	}plane[10];
	int T,d2,d3;
	float st;
	register int i,j;
	scanf("%d",&T);
	for(i=0;i<T;i++){
		scanf("%d",&plane[i].num);
		for(j=0;j<plane[i].num;j++){
			scanf("%d %d",&plane[i].dot[j].x,&plane[i].dot[j].y);
		}
	}
	for(i=0;i<T;i++){
		for(j=0;j<plane[i].num-2;j++){
			for(d2=0;d2<plane[i].num-1;d2++){
				for(d3=0;d3<plane[i].num;d3++){
					st=fabs(plane[i].dot[j].x*plane[i].dot[d2].y+plane[i].dot[d2].x*plane[i].dot[d3].y+plane[i].dot[d3].x*plane[i].dot[j].y-plane[i].dot[j].x*plane[i].dot[d3].y-plane[i].dot[d2].x*plane[i].dot[j].y-plane[i].dot[d3].x*plane[i].dot[d2].y)/2;
					if(st>plane[i].s) plane[i].s=st;
				}
			}
		}
	}
	for(i=0;i<T;i++){
		printf("%.1f\n",plane[i].s);
	}
	return 0;
}
