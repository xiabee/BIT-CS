#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define Err -1
#define MAX 1000
int v, count_n, Cnt_i;
int input[MAX] = { 0 };
int cont = 3;
void Swap(int* a, int* b) {//交换
	*a ^= *b;
	*b ^= *a;
	*a ^= *b;
	return;
}
void Maintain(int tmp, int pos) {//维护堆
	int Cnt_i = tmp;
	int Cnt_j = 2 * Cnt_i;
	int up = input[Cnt_i];
	while (Cnt_j <= pos) {
		if (Cnt_j > pos)
			break;
		if (input[Cnt_j] < input[Cnt_j + 1] && Cnt_j < pos)
			Cnt_j++;
		if (up < input[Cnt_j]) {
			input[Cnt_i] = input[Cnt_j];
			Cnt_i = Cnt_j;
			Cnt_j = 2 * Cnt_i;
		}
		else
			Cnt_j = pos + 1;
	}
	input[Cnt_i] = up;
	return;
}
void Sort_heap() {//构建堆排序
	for (int Cnt_i = count_n / 2; Cnt_i >= 1; Cnt_i--)
		Maintain(Cnt_i, count_n);
	return;
}
void Scan() {//全套输入
	v = scanf("%d", &count_n);
	for (Cnt_i = 1; Cnt_i <= count_n; Cnt_i++)
		v = scanf("%d", &input[Cnt_i]);
	return;
}
void Sort_main() {
	while (cont--) {
		Sort_heap();
		for (int Cnt_j = 1; Cnt_j <= count_n; Cnt_j++)
			printf("%d ", input[Cnt_j]);
		printf("\n");
		input[1] = input[count_n];
		count_n--;
	}
	return;
}
void Opper() {
	Scan();
	Sort_main();
	return;
}
int main() {
	//FILE* vvv = freopen("input.txt", "r", stdin);
	//FILE* sss = freopen("My_output.txt", "w", stdout);
	Opper();
	return 0;
}