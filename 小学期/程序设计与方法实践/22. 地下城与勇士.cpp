#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<algorithm>
#include<queue>
#include<cstring>
#define INF 0x3f3f3f3f
using namespace std;
const int maxn1 = 120;
const int maxn2 = 60;
char map[maxn1][maxn1];
int vis[maxn1][maxn1][maxn2];
const int dx[4] = { 1, 0, -1, 0 };
const int dy[4] = { 0, 1, 0, -1 };//x,y分别对应行和列
void clear();//清空队列
struct node
{
	int x;
	int y;
	int minute;
	node(int _x, int _y, int _timegg) : x(_x), y(_y), minute(_timegg) {}//快捷输入；
};
queue<node>sss;
int m, n, k, i, j, T, v, xs, ys, xe, ye, x, y, timett, timegg=INF;//测评机使用time.h，time已经被使用，故使用timegg
int main()
{
	v = scanf("%d", &T);//T组用例
	while (T--)
	{
		memset(map, '\0', sizeof(map));//多组用例，初始化初始化初始化
		memset(vis, 0, sizeof(vis));
		timegg = INF;
		v = scanf("%d%d%d", &n, &m, &k);
		v = getchar();
		for (i = 1; i <= n; i++) //从1开始，坐标与下标同步
		{
			for (j = 1; j <= m; j++) 
			{
				map[i][j] = getchar();//尝试一次getchar......上一题getchar莫名WA（）
				if (map[i][j] == 'S')
				{
					xs = i;
					ys = j;
				}
			}
			v = getchar();
		}
		vis[xs][ys][0] = 1;
		clear();//all clear, keep moving...
		sss.push(node(xs, ys, 0));
		while (!sss.empty())
		{
			node temp = sss.front();
			sss.pop();
			if (map[temp.x][temp.y] == 'E')//到达终点
			{
				timegg = temp.minute;
				//break;
				goto xiabee;
			}
			for (i = 0; i < 4; i++)
			{
				x = temp.x + dx[i];
				y = temp.y + dy[i];
				timett = temp.minute + 1;
				if (x<1 || x>n || y<1 || y>m || map[x][y] == '#' || vis[x][y][timett % k]) //走出边界或者遇到障碍
					continue;
				if (map[x][y] == '*' && (timett % k)) //遇到怪物；
					continue;
				sss.push(node(x, y, timett));
				vis[x][y][timett % k] = 1;
				if (map[temp.x][temp.y] == 'E')//到达终点
				{
					timegg = temp.minute;
					//break;
					goto xiabee;
				}
			}
		}
		if (timegg == INF)
			printf("-1\n");
		else 
		{
		xiabee:
			printf("%d\n", timegg);
		}
	
	}
	return 0;
}
void clear()
{
	while (!sss.empty())
		sss.pop();
	return;
}