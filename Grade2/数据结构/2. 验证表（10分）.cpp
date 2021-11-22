#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct StduentId {
	int id;
	char name[16];
	int flag;
}SID;
int main() {
	SID XZ[100];//List1;
	SID XT[100];//List2;
	int v, i, j, num1, num2, gg = 0;
	v = scanf("%d", &num1);
	for (i = 0; i < num1; i++) {
		v = scanf("%d%s", &XZ[i].id, &XZ[i].name);
		XZ[i].flag = 0;
	}
	v = scanf("%d", &num2);
	if (num2 == 0) {
		printf("the LIST2 is NULL.\n");
		return 0;
	}
	for (i = 0; i < num2; i++) {
		v = scanf("%d%s", &XT[i].id, &XT[i].name);
		XT[i].flag = 0;
		for (j = 0; j < num1; j++) {
			if (XZ[j].flag)
				continue;
			if (XZ[j].id == XT[i].id && strcmp(XZ[j].name, XT[i].name) == 0) {
				XT[i].flag = 1;
				XZ[j].flag = 1;
			}
		}
	}
	for (i = 0; i < num2; i++) {
		if (XT[i].flag == 0) {//List1中找不到
			gg = 1;//做标记
			printf("%d %s is not in LIST1.\n", XT[i].id, XT[i].name);
		}
	}
	if (!gg)
		printf("the records of LIST2 are all in the LIST1.\n");
	return 0;
}