#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int v, w, h;
int x, y, r, x1, x2, x3, x4, y1, y2, y3, y4, i, j, k;//x2,y2用于计算方形
int map[200][200] = { 0 };//记录地图
int multvector(int x, int y);//计算四个向量内积
int main()
{
	v = scanf("%d%d", &w, &h);//记录scanf返回值,w是长，h是宽
	v = scanf("%d%d%d", &x, &y, &r);//记录scanf返回值
	v = scanf("%d%d%d%d", &x1, &y1, &x3, &y3);//记录scanf返回值
	x2 = (x1 - y1 + x3 + y3) / 2;
	y2 = (x1 + y1 - x3 + y3) / 2;
	x4 = (x1 + y1 + x3 - y3) / 2;
	y4 = (-x1 + y1 + x3 + y3) / 2;//计算剩下的两个点坐标
	for (i = 0; i < w; i++)
		for (j = 0; j < h; j++)//数据不大，直接暴力枚举
			if ((x - i) * (x - i) + (y - j) * (y - j) <= r * r)//在圆内
				map[i][j] = 1;//做标记
	for (i = 0; i < w; i++)
		for (j = 0; j < h; j++)
			if (map[i][j] == 0)//不含logo
			{
				if (multvector(i, j))
					map[i][j] = 1;
			}
	for (i = 0; i < w; i++)//打印
	{
		for (j = 0; j < h; j++)
		{
			if (map[i][j] == 0)//不含logo
				printf("\\");
			else
				printf("/");
		}
		printf("\n");
	}
	return 0;
}
int multvector(int x, int y)
{
	if (((x1 - x) * (x1 - x2) + (y1 - y) * (y1 - y2) >= 0) && ((x2 - x) * (x2 - x1) + (y2 - y) * (y2 - y1) >= 0) && ((x1 - x) * (x1 - x3) + (y1 - y) * (y1 - y3) >= 0) && ((x3 - x) * (x3 - x1) + (y3 - y) * (y3 - y1) >= 0)&& ((x1 - x) * (x1 - x4) + (y1 - y) * (y1 - y4) >= 0) && ((x4 - x) * (x4 - x1) + (y4 - y) * (y4 - y1) >= 0) && ((x2 - x) * (x2 - x3) + (y2 - y) * (y2 - y3) >= 0)&& ((x3 - x) * (x3 - x2) + (y3 - y) * (y3 - y2) >= 0) && ((x3 - x) * (x3 - x4) + (y3 - y) * (y3 - y4) >= 0)&& ((x4 - x) * (x4 - x3) + (y4 - y) * (y4 - y3) >= 0))
		return 1;//数量积全为正
	else
		return 0;
}