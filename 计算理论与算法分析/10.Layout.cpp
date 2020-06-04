#include <iostream>
using namespace std;
const int INF = 0x3fffffff;
const int MAXN = 1010;
const int MAXE = 20010;
struct Edge {
	int from;
	int to;
	int cost;
}belEdges[MAXE];

int E = 0;
long long xz[MAXN];
int N, ML, MD;

//最短路
void belShortPath(int s) {
	fill(xz, xz + MAXN, INF);
	xz[s] = 0;
	while (true) {
		bool updated = false;
		for (int i = 0; i < E; ++i) {
			Edge e = belEdges[i];
			if (xz[e.from] != INF && xz[e.to] > xz[e.from] + e.cost) {
				xz[e.to] = xz[e.from] + e.cost;
				updated = true;
			}
		}
		if (!updated) break;
	}
}
//判断是否为负圈
bool findNegeLoop() {
	fill(xz, xz + MAXN, 0);
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < E; ++j) {
			Edge e = belEdges[j];
			if (xz[e.to] > xz[e.from] + e.cost) {
				xz[e.to] = xz[e.from] + e.cost;
				if (i == N - 1)
					return true;  //判定为负圈
			}
		}
	}
	return false;
}

int main() {
	cin >> N >> ML >> MD;
	int x, y, cs;
	for (int i = 0; i < ML; ++i) {
		cin >> x >> y >> cs;
		belEdges[E].from = x;
		belEdges[E].to = y;
		belEdges[E++].cost = cs;
	}
	for (int j = 0; j < MD; ++j) {
		cin >> x >> y >> cs;
		belEdges[E].from = y;
		belEdges[E].to = x;
		belEdges[E++].cost = -cs;  //取反
	}

	bool isnega = findNegeLoop();
	if (isnega) {
		cout << "-1" << endl;
		return 0;
	}
	//1到N的最短路
	belShortPath(1);
	if (xz[N] == INF)
		cout << "-2" << endl;
	else
		cout << xz[N] << endl;
	return 0;
}