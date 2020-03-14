#include<vector>
#include<cstdio>
#include<cstring>
using namespace std;
const int maxgg = 200010;
long long sum = 0, odd = 0, eve = 0, ans = 0, temp, i, j, k, sizegg[maxgg];//分奇偶判断,并记录节点
vector<int> vec[maxgg];//开设向量
void dfs(int u, int dis);//搜索一哈
int vv, u, v, n, depth[maxgg] = { 0 }, visgg[maxgg] = { 0 };//vv记录scanf返回值
int main()
{
	vv = scanf("%d", &n);
	sizegg[n] = 1;//先把最后一个归一了
	depth[n] = 0;
	for (i = 1; i < n; i++)//归零/归一/输入/压入 四合一
	{
		sizegg[i] = 1;
		depth[i] = 0;
		vv = scanf("%d%d", &u, &v);
		vec[u].push_back(v);//压入容器
		vec[v].push_back(u);//压入容器
	}
	memset(visgg, 0, sizeof(visgg));//初始化初始化初始化
	visgg[1] = 1;
	dfs(1, 0);//再来一个
	for (i = 1; i <= n; i++)
	{
		temp = sizegg[i] * (n - sizegg[i]);
		sum += temp;
		if (depth[i] % 2)//奇数项
			odd++;
		else//偶数项
			eve++;
	}
	temp = odd * eve;
	ans = (sum + temp) / 2;//寻找（计算）答案
	printf("%lld\n", ans);
	return 0;//程序君您休息
}
void dfs(int u, int dis)//搜索一哈
{
	auto iter = vec[u].begin();//强迫症患者
	auto v = *iter;//强迫症患者，变量定义在循环体之外/cy
	for (iter = vec[u].begin(); iter != vec[u].end(); iter++)//强迫症患者/cy
	{
		v = *iter;//遍历
		if (visgg[v] == 0)
		{
			visgg[v] = 1;
			depth[v] = depth[u] + 1;
			dfs(v, dis + 1);//继续搜索
			sizegg[u] += sizegg[v];//记录节点
		}
	}
	return;
}
