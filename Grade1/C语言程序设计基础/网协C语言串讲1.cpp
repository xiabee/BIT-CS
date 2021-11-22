/* ÎÄ¼ş1 */
#include<stdio.h>
#include"ÍøĞ­CÓïÑÔ´®½²2.cpp"
int x=10;
static int y=20;
void add() 
{
	static int z=30;
	z+=30;
	printf("z=%d\n",z);
	y=x+10;
	x=y+10;
}
int main() 
{
	extern void sub();
	x+=5;
	add();
	add();
	sub();
	printf("x=%d y=%d\n",x,y);
}
