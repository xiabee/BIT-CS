#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<algorithm>
#include<queue>
#include<cstring>
using namespace std;
struct node
{
	int x;
	int y;
	int minute;
	node(int _x, int _y, int _timegg) : x(_x), y(_y), minute(_timegg) {}//快捷输入；
};
queue<node>sss;
node temp;
const int maxn = 1005;
const int dx[4] = { 0, 0, 1, -1 };//上下左右移动使用的步子 
const int dy[4] = { 1, -1, 0, 0 };//x,y分别对应列和行
int n, m, k, v, i, j, xs, ys, xe, ye, timegg = 0, x, y, flag = 0;//flag记录是否有值
char map[maxn][maxn] = { '\0' };
int vis[maxn][maxn] = { 0 };
int main()
{
	memset(vis, 0, sizeof(vis));//初始化初始化初始化//虽然没必要
	memset(map, '\0', sizeof(map));
	v = scanf("%d%d%d", &n, &m, &k);
	for (i = 0; i < n; i++)
			v = scanf("%s", &map[i]);
	v = scanf("%d%d%d%d", &xs, &ys, &xe, &ye);
	if (map[xe-1][ye-1] == '#')		//如果终点有障碍，如果题目怎么诡异的话
	{
		printf("-1\n");
		return 0;
	}
	sss.push(node(xs - 1, ys - 1, 0));
	vis[xs - 1][ys - 1] = 1;
	vis[xe - 1][ye - 1] = 99;
	while (!sss.empty())
	{
		node temp = sss.front();
		sss.pop();
		/*if (temp.x == xe && temp.y == ye)//到达终点
		{
			timegg = temp.minute;//记录时间
			flag = 1;
			goto xiao;
		}*/
		for (i = 0; i < 4; i++)//朝着四个方向走
		{
			for (j = 1; j <= k; j++)//最多走k步，最少走1步
			{
				x = temp.x + dx[i] * j;
				y = temp.y + dy[i] * j;//每走一步
				if (x < 0 || y < 0 || x >= n || y >= m || map[x][y] == '#')
					break;
				else if (vis[x][y] == 1)
					continue;
				else if(vis[x][y]!=99)
				{
					sss.push(node(x, y, temp.minute + 1));
					vis[x][y] = 1;
				}
				if (vis[x][y]==99)//到达终点
				{
					timegg = temp.minute;//记录时间
					flag = 1;
					goto xiao;
				}
			}
		}
	}
	if (timegg == 0)
		printf("-1\n");
	else
		xiao:printf("%d\n", timegg + 1);
	return 0;//程序君您休息
}
