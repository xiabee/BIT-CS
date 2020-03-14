#include <stdio.h>
#include <stdlib.h>

/*请使用递归算法求下列序列的前n项之和。
            1 + 1/2 - 1/3 + 1/4 -1/5 ......
输入：n
输出：序列的前n项和（精确到小数点之后第6位） */

int main(int argc, char *argv[]) {
	int n;
	float s;
	float sum(int n);
	scanf("%d",&n);
	s=sum(n); 
	if(n==1)
	    printf("1\n");
	else
	    printf("%f\n",s);
	return 0;
}
float sum(int n){
	float s;
	if(n==1) 
		s=1;
	else if(n%2==0) 
		s=sum(n-1)+1/(float)n;
	else s=sum(n-1)-1/(float)n;
    return s;
}
