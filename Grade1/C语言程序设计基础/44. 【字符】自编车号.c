#include <stdio.h>
#include <stdlib.h>

/*2009年3月9日起，北京市允许机动车所有人自己编写小汽车的以“京N”开头的号牌的后5位。
自编小汽车号牌的规则如下：
号牌号码的最后一位必须为数字，其余四位必须至少包含两位大写英文字母（字母I、O不可用）。
例如：京NAB999，京NC9D99，京NE99F9，京N9GH99，京N9J9K9，京N99LM9等。 

输入：
    5位自编号牌
输出：
    判断自编号牌是否合法*/

int main(int argc, char *argv[]) {
	int i,p=0,f=0;
	char a[6];
	for(i=0;i<=4;i++){
	    scanf("%c",&a[i]);
	    if(a[i]<48||(a[i]>57&&a[i]<65)||a[i]>=90) f=1; 
	    if(a[i]>=65&&a[i]<=90&&a[i]!=73&&a[i]!=79) p++;
    }
    if(a[4]<48||a[4]>57||p<2) f=1;
    if(f==0) printf("ok.\n");
    else printf("no.\n");
	return 0;
}
