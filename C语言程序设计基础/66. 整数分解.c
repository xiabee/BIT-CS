#include <stdio.h>
#include <stdlib.h>

/*例如：1998+1999+2000+2001+2002=10000，是一个累加和等于 N 的连续的自然数段。

输出每个累加和等于 N 的连续的自然数段的第一个数和最后一个数，
两数之间用符号～隔开，每段一行，所有行按每行的第一个数从小到大升序排列。
如果没有符合条件的自然数段，则输出None。

输入：N（例如：N=10000）

输出：
18～143
297～329
388～413
1998～2003*/

int main(int argc, char *argv[]) {
	int N,s,flag=0;
	register int i,j;
	scanf("%d",&N);
	for(i=1;i<N;i++){
		for(j=1,s=i;j<N-i;j++){
			s+=i+j;
			if(s==N&&j>1){
				flag=1;
				printf("%d~%d\n",i,i+j);
			}
			if(s>N){
				break;
			}
		}
	}
	if(flag==0) printf("None\n");
	return 0;
}
