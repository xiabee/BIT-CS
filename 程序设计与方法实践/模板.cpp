// BFS 迷宫找出口
#include <queue>
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

const int maxn = 10 + 5;
const int dx[] = { 0, 0, 1, -1 };//上下左右移动使用的步子 
const int dy[] = { 1, -1, 0, 0 };

struct node {
	int x, y;//坐标 
	int step;//到这里的步数 

	node(int _x, int _y, int _step) : x(_x), y(_y), step(_step) {}//简便一点的结构赋值方式 
};
queue<node> que;
int vis[maxn][maxn];//vis用于标记走过的点:1为走过 0为没有 
char mp[maxn][maxn];//mp用于记录地图的地形

int main() {
	int n, m;//n*m大小的地图 
	int start_x, start_y;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; ++i) {
		scanf("%s", &mp[i]);//录入地图 
		for (int j = 0; j < m; ++j) {
			if (mp[i][j] == 'S') {
				start_x = i;
				start_y = j;
			}//找到起点 
		}
	}


	memset(vis, 0, sizeof(vis)); // 初始化 vis 
	que.push(node(start_x, start_y, 0));
	vis[start_x][start_y] = 1;
	int ans;//ans是记录步数的

	//下面的 while循环相当于一个队列从第0步开始走，把走到的点取出去 ，下一步能到的存进去。
	//因此依次排好进队出队的元素的步数天然排好序，大概如0 1 1 1 2 2 2 2 2 2 2 2 2 3... 
	while (!que.empty()) {
		node tmp = que.front();//tmp用来看当前的位置 
		que.pop();//取队列里的元素 先进先出

		if (mp[tmp.x][tmp.y] == 'F') {
			ans = tmp.step;//ans记录到出口几步 
			break;
		}//取到终点结束

		for (int i = 0; i < 4; ++i) {
			int x = tmp.x + dx[i], y = tmp.y + dy[i];//走一步

			// 下面是这一步非法、不继续的条件： 
			// 1 超出边界 
			// 2 出现地图上的障碍 
			// 3 走过了 
			if (x < 0 || x >= n || y < 0 || y >= m || mp[x][y] == '#' || vis[x][y] == 1) {
				continue;
			}
			que.push(node(x, y, tmp.step + 1));//记步+1,录入队列里 
			vis[x][y] = 1;//标记走过 
		}
	}
	printf("%d\n", ans);

	return 0;
}
//样例 
// 7 7
// ...#...
// .....#F
// .......
// .#.#...
// .......
// .S#..#.
// .......