#include <stdio.h>
#include <stdlib.h>

/*HYB是一个土豪，他有n只土豪金。

十分无聊的他给他的土豪金们从1-n编上号然后又开始摞土豪金玩儿了= =

一开始他的土豪金们按次序摞成一摞，我们管这摞叫起始摞a，a的最上面是土豪金1，最下面是土豪金n。 然后他有一个暂存摞，我们叫它b,一个结果摞，叫c。 每次，他可以从a（如果a不空的话）拿最顶上的一个放到b,或者拿b最顶上一个放到c的最上方(同理b不空的话)

现在，他给出 c摞从底部到顶部的土豪金的编号，问是否能通过以上操作实现

由于HYB要买别的东西，所以他的土豪金只剩下最多999个了

输入:
有若干组数据输入
每组数据中,第一行为两个个整数n和m,n表示hyb有n台土豪金,m表示这组数据有m个c的序列需要判断,当n=0 并且m=0时停止
接下来有m行,每行表示一个c序列

对于每一个c序列，视为a从原始状态（a最上方为1,最下方为n）重新开始。

输出:
对每一个c的序列,如果能得到,就输出Yes ，否则输出 No

每组数据之间输出一空行

source:poj

翻译:707


 

测试输入关于“测试输入”的帮助

期待的输出关于“期待的输出”的帮助

时间限制关于“时间限制”的帮助

内存限制关于“内存限制”的帮助

额外进程关于“{$a} 个额外进程”的帮助


测试用例 1 以文本方式显示
1.5 2?
2.1 2 3 4 5?
3.5 4 1 2 3?
4.6 1?
5.6 5 4 3 2 1?
6.0 0?
 以文本方式显示
1.Yes?
2.No?
3.?
4.Yes?
 

*/

int main(int argc, char *argv[]) {
	return 0;
}
