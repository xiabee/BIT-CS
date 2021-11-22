#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* 有一种特殊形式的字符串，其正反序相同，被称为“回文字符串”。例如LeveL就是一个回文字符串。

输入:   字符串

输出：  Yes或者No

说明：  如输出Yes，说明输入的字符串是一个回文字符串
          输出No，说明输入的字符串不是一个回文字符串
          请使用递归算法实现。*/
int main(int argc, char *argv[])
{ static char str1[100],str2[100];
  int n,i,j;
  scanf("%s",str1);
  n=strlen(str1);
  for(i=0,j=n-1;i<n;i++,j--){
      str2[j]=str1[i];
  }
  if(strcmp(str1,str2)==0) printf("Yes\n");
  else printf("No\n");
  return 0;
}
