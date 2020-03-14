#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAXN 1000
#define cutoff 5
int md = 0;
int mds[MAXN] = { 0 };
int Input[MAXN] = { '\0' };
int len = 0, i;
int v;
char temp[100] = { '\0' };
char tmpp[100];
void NumInput() {//输入；
	for (int i = 0;; i++) {
		v = scanf("%s", temp);
		if (strcmp(temp, "#") == 0) {
			len = i;
			break;
		}
		Input[i] = atoi(temp);
	}
	return;
}
void Swap(int* a, int* b) {//交换
	*a ^= *b;
	*b ^= *a;
	*a ^= *b;
	return;
}
void InsertSort(int* arr, int lpos, int rpos) {//插入排序
	int temp, i, j;
	for (i = lpos + 1; i <= rpos; i++) {
		temp = arr[i];
		for (j = i - 1; j >= 0 && arr[j] > temp; j--)
			arr[j + 1] = arr[j];
		if (j != i - 1)
			arr[j + 1] = temp;
	}
	return;
}
int Median3(int* arr, int lpos, int rpos) {//返回枢轴元素
	int mid = (lpos + rpos) / 2;
	int tmp[3];
	int i, j;
	tmp[0] = arr[lpos];
	tmp[1] = arr[mid];
	tmp[2] = arr[rpos];
	for (i = 0; i < 3; i++)
		for (j = i + 1; j < 3; j++)
			if (tmp[i] > tmp[j])
				Swap(&tmp[i], &tmp[j]);
	arr[lpos] = tmp[0];
	arr[mid] = tmp[2];
	arr[rpos] = tmp[1];
	return arr[rpos];
}
int Partition(int* arr, int lpos, int rpos) {//快排，分治
	mds[md++] = Median3(arr, lpos, rpos);
	int pivot = arr[rpos];
	int left = lpos;
	int right = rpos - 1;
	while (1) {
		while (left < right && arr[left] < pivot)
			left++;//游标右移
		while (left<right && arr[right]>pivot)
			right--;
		if (left < right) {
			Swap(&arr[left], &arr[right]);
			left++;
			right--;
		}
		else
			break;
	}
	if (arr[left] > pivot) {
		arr[rpos] = arr[left];
		arr[left] = pivot;
	}
	return left;
}
void QuickSort(int* arr, int lpos, int rpos) {
	if (rpos - lpos < cutoff)
		InsertSort(arr, lpos, rpos);
	else {
		int block = Partition(arr, lpos, rpos);
		QuickSort(arr, lpos, block - 1);
		QuickSort(arr, block + 1, rpos);
	}
	return;
}
void Print1() {
	printf("After Sorting:\n");
	for (i = 0; i < len; i++)
		printf("%d ", Input[i]);
}
void Print2() {
	printf("\nMedian3 Value:\n");
	if (!md)
		printf("none\n");
	else {
		for (i = 0; i < md; i++)
			printf("%d ", mds[i]);
		printf("\n");
	}
}
void Print() {
	Print1();
	Print2();
}
void Opper() {
	NumInput();
	QuickSort(Input, 0, len - 1);
	Print();
}
int main() {
	FILE* vvv = freopen("input.txt", "r", stdin);
	Opper();
	return 0;
}
