#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstring>
#define MAXN 1010
int s[MAXN][30];
int sum0, sum1, sum2; //实现对S1，S2，S3三个集合的指向
void storeData(char str[]) {
	memset(s, 0, sizeof(s));
	sum0 = sum1 = -1; sum2 = 0;
	int len = strlen(str);
	int i = 0;
	while (i <= len) {
		if (str[i] >= 'a' && str[i] <= 'z') 
			s[sum2][str[i] - 'a'] = 1;
		else if (str[i] == '&') 
			sum2++;
		else if (str[i] == '!') 
			s[sum2][str[++i] - 'a'] = 2;
		i++;
	}
}
bool same(int a[], int b[]) {
	for (int i = 0; i < 26; i++)
		if (a[i] != b[i]) return false;
	return true;
}
bool check(int ans[]) {
	for (int i = 0; i <= sum2; i++)
		if (same(s[i], ans)) return false;
	return true;
} //判断是否有重复变项
bool res(int a[], int b[]) {
	int singleDog = 0; //不能消解的个数
	int cp = 0; //可消解的个数
	for (int i = 0; i < 26; i++) {
		if (!a[i] && !b[i]) continue;
		if ((a[i] == 1 && b[i] == 2) || (a[i] == 2 && b[i] == 1)) cp++;
		else singleDog++;
	}

	if (cp != 1) 
		return true; //不能消解活多对消解
	if (!singleDog) 
		return false; //只有一对可消解且无不能消解，得到空子句

	int ans[30]; //消解结果
	for (int i = 0; i < 26; i++) {
		if ((!a[i] && !b[i]) || (a[i] + b[i] == 3)) ans[i] = 0;
		else if (a[i] == 1 || b[i] == 1) ans[i] = 1;
		else ans[i] = 2;
	}
		

	if (check(ans)) {
		sum2++; //将ans加入S2
		for (int i = 0; i < 26; i++) s[sum2][i] = ans[i];
	}
	return true;
}
char str[MAXN];
void opper1() {
	int v = scanf("%s", str);
	storeData(str);
}
int opper2() {
	while (sum2 > sum1) {
		sum0 = sum1; sum1 = sum2; //将S1并到S0中，令S1等于S2，清空S2
		for (int i = 0; i <= sum0; i++)
			for (int j = sum0 + 1; j <= sum1; j++)
				if (!res(s[i], s[j])) {
					printf("NO\n");
					return 0;
				}
		for (int i = sum0 + 1; i <= sum1; i++)
			for (int j = i + 1; j <= sum1; j++)
				if (!res(s[i], s[j])) {
					printf("NO\n");
					return 0;
				}
	}
	printf("YES\n");
}
void opper() {
	opper1();
	opper2();
}
int main() {
	//FILE* vvv = freopen("input.txt", "r", stdin);
	opper();
	return 0;
}