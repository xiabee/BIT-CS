#include <stdio.h>
#include <stdlib.h>

/*输出一维数组中的元素（不超多20个元素）两两相乘的乘积。*/
/*两两元素相乘的顺序是第一个元素与最后一个元素相乘，第二个元素与倒数第二个元素相乘，.......*/
/*输入：第一行为元素数量，第二行为各个元素
        7
        1 2 3 4 5 6 7
  输出：
        7 12 15 4                      */

int main(int argc, char *argv[]) {
	int str[20],n,a,i,j,flog=0;
	scanf("%d",&n);
	flog=n%2;
	for(i=0;i<n;i++){
		scanf("%d",&str[i]);
	}
	for(j=0;j<(n-flog)/2;j++){
	    a=str[j]*str[n-j-1];
	    printf("%d ",a);
    }
    if(flog==1) printf("%d ",str[(n+flog)/2-1]);
    printf("\n");
	return 0;
}
