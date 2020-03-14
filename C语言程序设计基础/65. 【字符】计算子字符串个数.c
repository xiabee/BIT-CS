/*字符串匹配问题：输入一个字符串，计算其中包含的连续给定的子字符串的个数。
例如输入字符串“ EFABCABCABCDABCDD ” , 给定子字符串“ ABC” ，输出是 3 。
函数原型： int countsub( char *str, char *subs ) 。
参数说明： str 保存输入的字符串的首地址， subs 保存需要统计的子字符串的首地址。
返回值：包含的连续子字符串的个数。*/

#include <stdio.h>

int countsub( char *str, char *ss );
main( )
{
    char s1[1000]={0},s2[100]={0};
    gets(s1);
    gets(s2);
    printf("%d\n",countsub(s1,s2));
}

int countsub( char *str, char *ss ){
	register int i,j;
	int count=0;
	for(i=0;*(str+i)!='\0';i++){
		if(*(str+i)==*ss){
			for(j=0;*(str+i)==*(ss+j);i++){
				if(*(ss+j+1)=='\0'){
					j=0;
					count++;
				}
				else j++;
			}
			break;
		}
	}
	return count;
}

