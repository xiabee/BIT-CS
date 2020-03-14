#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int n, b, k;
char str[1000];
int get[6];

struct {
	char name[10];
	int innum;
	int outnum;
	int linkto[5000];
	int value[5000];
}xz[600];
int road[100][100] = { 0 };
int maxvalue = 0, roadnum = 0;
char  resroad[100][500];
int start;
int aoevsd[1000] = { 0 };
int list[100], q, res[100], p;
char temp[5000];

void scanfb(char* temp, int f, int* get) {
	char s1[20], s2[20], s3[20];
	int p, s, c;
	int len = strlen(temp);
	if (temp[f] == '<') {
		p = 0;
		for (int j = f + 1; j < len; j++) {
			if (temp[j] != ',') {
				s1[p++] = temp[j];
			}
			else {
				s1[p] = '\0';
				s = j;
				break;
			}
		}
		p = 0;
		for (int j = s + 1; j < len; j++) {
			if (temp[j] != ',') {
				s2[p++] = temp[j];
			}
			else {
				s2[p] = '\0';
				c = j;
				break;
			}
		}
		p = 0;
		for (int j = c + 1, p = 0; j < len; j++) {
			if (temp[j] != ',') {
				s3[p++] = temp[j];
			}
			else {
				s3[p] = '\0';
				break;
			}
		}
	}
	get[0] = atoi(s1);
	get[1] = atoi(s2);
	get[2] = atoi(s3);
}
void AOEsearch() {

	if (q == 0)return;
	else {
		int now = list[q];
		res[++p] = list[q--];

		for (int i = 0; i < xz[now].outnum; i++) {
			xz[xz[now].linkto[i]].innum--;
			if (xz[xz[now].linkto[i]].innum == 0) {
				list[++q] = xz[now].linkto[i];
			}
		}
		for (int i = 1; i <= q; i++)
			for (int j = i; j <= q; j++) {
				if (list[j] > list[i]) {
					int temp = list[i];
					list[i] = list[j];
					list[j] = temp;
				}
			}
		AOEsearch();
	}
}
void searchMain(char lastroad[100], int cout, int now) {
	char sasa[100];
	strcpy(sasa, lastroad);
	if (now != start)strcat(sasa, "-");
	strcat(sasa, xz[now].name);
	if (cout > maxvalue) {
		maxvalue = cout;
		roadnum = 1;
		strcpy(resroad[roadnum], sasa);

	}
	else if (cout == maxvalue) {
		roadnum++;
		strcpy(resroad[roadnum], sasa);

	}
	for (int i = 0; i < xz[now].outnum; i++) 
		searchMain(sasa, cout + xz[now].value[i], xz[now].linkto[i]);
}
void ssort() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < xz[i].outnum; j++) {
			for (int k = j; k < xz[i].outnum; k++) {
				if (xz[i].linkto[j] > xz[i].linkto[k]) {
					int tp1 = xz[i].linkto[j];
					int tp2 = xz[i].value[j];
					xz[i].linkto[j] = xz[i].linkto[k];
					xz[i].value[j] = xz[i].value[k];
					xz[i].linkto[k] = tp1;
					xz[i].value[k] = tp2;
				}
			}
		}
	}
}
void calc() {
	q = 0;
	p = 0;
	for (int i = 0; i < n; i++) {
		if (xz[i].innum == 0) {
			list[++q] = i;
		}
	}

	AOEsearch();
	if (p == n) {
		printf("%s", xz[res[1]].name);
		for (int i = 2; i <= p; i++)printf("-%s", xz[res[i]].name);
		printf("\n");
		start = res[1];
		searchMain("", 0, start);
		for (int i = 1; i <= roadnum; i++)
			printf("%s\n", resroad[i]);
	}
	else
		printf("NO TOPOLOGICAL PATH\n");
	return;
}
void inputName() {
	scanf("%d,%d", &n, &b);
	for (int i = 0; i < n; i++) {
		xz[i].outnum = 0;
		xz[i].innum = 0;
	}
	scanf("%s", str);
	k = 0;
	int qtemp = 0;
	for (int i = 0; i < strlen(str); i++) {
		if (str[i] != ',') {
			xz[k].name[qtemp++] = str[i];
		}
		else {
			xz[k].name[qtemp] = '\0';
			k++;
			qtemp = 0;
		}
	}
	return;
}
void inputValue() {
	scanf("%s", temp);
	for (int i = 0; i < strlen(temp); i++) {
		if (temp[i] == '<') {
			scanfb(temp, i, get);
			xz[get[0]].value[xz[get[0]].outnum] = get[2];
			xz[get[0]].linkto[xz[get[0]].outnum++] = get[1];
			xz[get[1]].innum++;
		}
	}
	return;
}
void opper() {
	inputName();
	inputValue();
	ssort();//sort linktos and values
	calc();//start
}
int main() {
	FILE* vvv = freopen("input.txt", "r", stdin);
	opper();
	return 0;
}

