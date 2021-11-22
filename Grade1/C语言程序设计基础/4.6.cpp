#include<stdio.h>
int main() {
	int num,flag,i;
	char ch;
	static char chs[1000];
	scanf("%d",&num);
	i=num;
	num=0;
	while(num!=2*i) {
		ch=getchar();
		if(ch==' '||ch=='\n')
			continue;
		else
			chs[num++]=ch;
	}
	getchar();
	while((ch=getchar())!='\n') {
		flag=0;
		for(int i=0;i<num;i+=2) {
			if(chs[i]==ch) {
				printf("%c",chs[i+1]);
				flag=1;
				break;
			}
		}
		if(!flag)
			printf("%c",ch);
	}
	printf("\n");
	return 0;
}
