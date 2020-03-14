/*有 3 种商品在 N 个商店出售，同样商品在不同商店的售价各不相同，
假定商店名称用数字1、2、3、4、......来表示，商品的名称用A、B、C来表示。
如果按照最先购买商品A、再购买商品B、最后购买商品C的顺序购买商品，
且在一个商店只能购买一种商品。请编程设计一个购物方案，用最少的钱购得 3 种商品。

编写求购物方案的函数：int findm(int n, double gp[ ][3], BUY schm[ ] );
其中：n 是商店数量，gp[][] 是保存商品价格表的数组名，
schm[ ] 是保存求得购物方案的数组名；函数的返回值是购得 3 种商品的总钱数。

例如：有 3 种商品，在 5 个商店出售，商品在各商店的售价如下表所示：

 A B B 
1 12 29 9 
2 10 30 8 
3 11 35 12 
4 10 28 11 
5 12 31 8 

程序运行后输出是：

Total Money are: 46
Goods-Name Shop-Name Goods-Price
A: 2 10
B: 4 28
C: 5 8

其中第一行是购物的总钱数，第二行是购物方案的表头，
从第三行起每行为一种商品名和商店名、该种商品在该店的价格。
商品名用大写英文字母表示,从 A 开始，商店名用数字表示，从 1 开始。
购物方案的输出顺序按商品名英文字母升序排列。

注意：只提交自编的函数 findm，不要提交主函数。
给定的程序已经控制好了输出的格式，你只要你的方案按要求放入数组即可
*/

#include <stdio.h>

typedef struct buy
{  char  gname;
   int   sname;
   int   gprice;
} BUY;

int main( )
{  int i, j, n;
   int min, price[10][3];
   int findm( int n, int price[][3], BUY scheme[] );

   static BUY scheme[3]={ {'A', 0, 0}, {'B', 0, 0}, {'C', 0, 0} };

   scanf( "%d", &n );
   for( i = 0; i < n; i++ )
	for( j = 0; j < 3; j++ )
	   scanf( "%d", &price[i][j] );

   min = findm( n, price, scheme );

   printf("Total Money are : %d\nGoods-Name  Shop-Name  Goods-Price\n", min );
   for ( i=0; i < 3; i++ )
       printf("         %c:%10d%13d\n", scheme[i].gname, scheme[i].sname, scheme[i].gprice );
   return 0;
}
 int findm( int n, int gp[ ][3],BUY schm[ ] ){
 	int i,j,k,p,s=0;
	for(i=0;i<3;i++){
		for(j=1,k=0;j<n;j++){
			if(gp[j][i]<gp[k][i]) k=j;
		}
		s+=gp[k][i];
		schm[i].gprice=gp[k][i];
		for(j=0,p=0;j<n;j++){
			if(gp[j][i]==gp[k][i]) {
				if((i==1&&(j+1)!=schm[0].sname)||(i==2&&(j+1)!=schm[0].sname&&(j+1)!=schm[1].sname)||i==0){
					schm[i].sname=j+1;
					break;
				}
			}
		}
	}
	return s;
 }
