#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

char ch;
int main() {
	FILE* read = freopen("input.txt", "r", stdin);
	FILE* write = freopen("output.txt", "w", stdout);
	while ((ch = getchar()) && ch != EOF) {
		if (ch == '\n')
			printf("\\n");
		else
			printf("%c", ch);
	}
	printf("\\n");
	return 0;
}