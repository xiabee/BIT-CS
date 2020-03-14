#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

/*一天，丁俊晖编一整天的程序，突然觉得累了，于是便决定在房间内四处走走。
他的房间是矩形的，他从电脑开始随便选了一个角度开始行走。
由于职业习 惯，丁俊晖走路始终是直线，而且碰到墙以后会反弹，
入射角度与出射角度完全相同。丁俊晖会一直行走，直到灵感再次迸发。
假设他的行走速度是匀速的，现在， 丁俊晖的母亲想知道他一共休息了多长时间
以便提醒他继续工作。

丁俊晖想考考他的母亲，于是他记录了自己碰到墙壁的序列并且告诉了她，
你有没有办法能够帮助她计算出小丁所走的路程？

输入
输入包括多个测试用例，每个测试用例如下： 
第一行包含两个数字 w, l(0<w, l<=1000)，分别代表房间的宽度和长度； 
第二行包括两个数字 x0, y0，代表电脑的位置坐标 (x0, y0)； 
第三行包含两个数字 x1, y1，代表丁俊晖的位置坐标 (x1, y1)； 
最后一行是一个包含'F', 'B', 'L', 'R'四种字符的字符串，
分别代表墙在前面、后面、左边或是右边，字符串的长度小于等于 1000； 
我们约定，左上角的坐标为0,0，所有的坐标都是浮点型数字。

输出
一个浮点型数字，代表总路程，结果精确到小数点后 4 位。*/

int main(int argc, char *argv[]) {
	signed int w,l,x0,y0,x1,y1,len;
	double x=0;
	char route[1001];
	register int i;
	scanf("%d %d\n%d %d\n%d %d\n",&w,&l,&x0,&y0,&x1,&y1);
	gets(route); 
	len=strlen(route);
	for(i=0;i<len;i++){
		switch(route[i]){
			case 'F':y0=-y0;break;
			case 'B':y0=2*l-y0;break;
			case 'L':x0=-x0;break;
			case 'R':x0=2*w-x0;break;
		}
	}
	x=sqrt(pow(x0-x1,2)+pow(y0-y1,2));
	printf("%.4f\n",x);
	return 0;
}
