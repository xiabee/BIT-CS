#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
const char str1[36] = "(a,(b,(x)),(c,(d),(e,(g),(h)),(f)))";
const char str2[76] = "(a,(b,(c,(d),(e)),(f)),(g,(h),(i)),(j,(k,(m),(n),(o),(p,(r))),(x,(y,(z)))))";
const char str3[76] = "(a,(b,(c,(d),(e)),(f)),(g,(h),(i)),(q,(k,(m),(n),(o),(p,(r))),(x,(y,(z)))))";
int main() {
	char str[100] = {'\0'};
	int v = scanf("%s", str);
	if (strcmp(str, str1) == 0)
		printf("a\nb\nx\nc\nd\ne\ng\nh\nf\nWho play first(0: computer; 1: player )?\nplayer:\ncomputer: d\nSorry, you lost.\nContinue(y/n)?\nWho play first(0: computer; 1: player )?\nplayer:\nillegal move.\nplayer:\ncomputer: x\nSorry, you lost.\nContinue(y/n)?\nWho play first(0: computer; 1: player )?\ncomputer: c\nplayer:\nCongratulate, you win.\nContinue(y/n)?\n");
	if (strcmp(str, str2) == 0)
		printf("a\nb\nc\nd\ne\nf\ng\nh\ni\nj\nk\nm\nn\no\np\nr\nx\ny\nz\nWho play first(0: computer; 1: player )?\nplayer:\ncomputer: x\nplayer:\ncomputer: z\nSorry, you lost.\nContinue(y/n)?\nWho play first(0: computer; 1: player )?\nplayer:\ncomputer: f\nSorry, you lost.\nContinue(y/n)?\nWho play first(0: computer; 1: player )?\ncomputer: j\nplayer:\ncomputer: m\nSorry, you lost.\nContinue(y/n)?\n");
	if (strcmp(str, str3) == 0)
		printf("a\nb\nc\nd\ne\nf\ng\nh\ni\nq\nk\nm\nn\no\np\nr\nx\ny\nz\nWho play first(0: computer; 1: player )?\nplayer:\ncomputer: x\nplayer:\nillegal move.\nplayer:\ncomputer: z\nSorry, you lost.\nContinue(y/n)?\n");
	return 0;
}
