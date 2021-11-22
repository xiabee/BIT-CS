#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#define N 26
bool dic[N], max[N], min[N];
char temp[N];
int v;
void initialize() {
	memset(dic, false, sizeof(dic));
	memset(min, true, sizeof(min));//先全部设置为真，遇到极大再设置为假
	memset(max, true, sizeof(max));
	return;
}
void inputDic() {
	v = scanf("%s", temp);
	for (int i = 0; i < strlen(temp); i++)
		if (isalpha(temp[i]))
			dic[temp[i] - 'a'] = true;//标记字典
	return;
}
void inputLetter() {//存入偏序关系
	v = scanf("%s", temp);
	for (int i = 0; i < strlen(temp); i++) {
		if (temp[i] == '<')
			max[temp[i + 1] - 'a'] = false;
		else if (temp[i] == '>')
			min[temp[i - 1] - 'a'] = false;
		else
			continue;
	}
	return;
}
void find() {
	int i = 0;
	while (!dic[i] || !min[i]) 
		i++;
	printf("%c", i + 'a');
	for (i++; i < N; i++)
		if (dic[i] && min[i]) 
			printf(",%c", i + 'a');
	printf("\n");
	i = 0;
	while (!dic[i] || !max[i]) 
		i++;
	printf("%c", i + 'a');
	for (i++; i < N; i++)
		if (dic[i] && max[i]) 
			printf(",%c", i + 'a');
	printf("\n");
	return;
}
int main() {
	//FILE* vvv = freopen("input.txt", "r", stdin);
	initialize();
	inputDic();
	inputLetter();
	find();
	return 0;
}