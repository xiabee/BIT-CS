#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <math.h>
#define NUM 1000
#define MAXN 10000000
char s[NUM];
bool sheet[30];
int expexp[30];
int value[MAXN];
int sum = 0;
int priority(char c) {
	switch (c) {
	case '#': return -1;
	case '!': return 5;
	case '&': return 4;
	case '|': return 3;
	case '-': return 2;
	case '+': return 1;
	case '(': return 0;
	default: return 0;
	}
}
void postfix() {
	char post[NUM] = { '\0' };
	int pp = -1;
	char stack[NUM] = { '#' };
	int ps = 0;

	int len = strlen(s);
	for (int i = 0; i < len; i++) {
		if (s[i] >= 'a' && s[i] <= 'z') {
			post[++pp] = s[i];
			continue;
		}
		if (s[i] == '!' || s[i] == '&' || s[i] == '|' || s[i] == '-' || s[i] == '+') {
			while (priority(s[i]) <= priority(stack[ps]))
				post[++pp] = stack[ps--];
			stack[++ps] = s[i];
			continue;
		}
		if (s[i] == '(') {
			stack[++ps] = s[i];
			continue;
		}
		if (s[i] == ')') {
			while (stack[ps] != '(') post[++pp] = stack[ps--];
			ps--;
			continue;
		}
	}
	while (ps) 
		post[++pp] = stack[ps--];
	strcpy(s, post);
	int l = strlen(s);
}
void settable() {
	memset(sheet, 0, sizeof(sheet));
	int len = strlen(s);
	for (int i = 0; i < len; i++)
	{
		if (s[i] >= 'a' && s[i] < 'z')
			sheet[s[i] - 'a'] = true;
	}
	for (int i = 0; i < 26; i++)
		if (sheet[i]) sum++;
	sum = pow(2, sum);
}
int btoi() {
	int sum = 0, weight = 1;
	for (int i = 25; i >= 0; i--)
		if (sheet[i]) {
			if (expexp[i]) sum += weight;
			weight *= 2;
		}
	return sum;
}
int calc(int a, int b, char c) {
	switch (c) {
	case '&': return a * b;
	case '|': if (a + b) return 1; else return 0;
	case '-': if (a == 1 && b == 0) return 0; else return 1;
	case '+': return !((a + b) & 1);
	}
}
int work() {
	int stack[NUM], ps = -1;
	int len = strlen(s);
	for (int i = 0; i < len; i++) {
		if (s[i] >= 'a' && s[i] <= 'z') {
			stack[++ps] = expexp[s[i] - 'a'];
			continue;
		}
		if (s[i] == '!') {
			stack[ps] = (stack[ps] + 1) & 1;
			continue;
		}
		int ans = calc(stack[ps - 1], stack[ps], s[i]);
		stack[--ps] = ans;
	}
	return stack[0];
}
void assign() {
	int x = btoi();
	int ans = work();
	value[x] = ans;
}
void generate(char c) {
	while (c <= 'z' && sheet[c - 'a'] == false) c++;
	if (c > 'z') {
		assign();
		return;
	}
	expexp[c - 'a'] = 0;
	generate(c + 1);
	expexp[c - 'a'] = 1;
	generate(c + 1);
}
void output1() {
	int i = 0;
	while (i < sum && !value[i]) i++;
	if (i >= sum) {
		printf("0 ; ");
		return;
	}
	printf("m%d", i);
	for (i++; i < sum; i++)
		if (value[i]) printf(" ∨ m%d", i);
	printf(" ; ");
}
void output2() {
	int i = 0;
	while (i < sum && value[i]) i++;
	if (i >= sum) {
		printf("1\n");
		return;
	}
	printf("M%d", i);
	for (i++; i < sum; i++)
		if (!value[i]) printf(" ∧ M%d", i);
	printf("\n");
}
void opper1() {
	int v = scanf("%s", s);
	postfix();
	settable();
}
void opper2() {
	memset(value, 0, sizeof(value));
	memset(expexp, 0, sizeof(expexp));
}
void opper3() {
	generate('a');
}
void opper4() {
	output1();
	output2();
}
void opper() {
	opper1();
	opper2();
	opper3();
	opper4();
}
int main() {
	opper();
	return 0;
}