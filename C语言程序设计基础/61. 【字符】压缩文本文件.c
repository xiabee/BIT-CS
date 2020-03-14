#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*背景：
压缩是一种有效的减小数据量的方法，目前已经被广泛应用于各种类型的信息系统之中。
一种压缩文本文件（假设文件中不包含数字）的方法如下：

1. 原始文本文件中的非字母的字符，直接拷贝到压缩文件中；
2. 原始文件中的词（全部由字母组成），如果是第一次出现，
则将该词加入到一个词的列表中，并拷贝到压缩文件中；
否则该词不拷贝到压缩文件中，而是将该词在词的列表中的位置拷贝到压缩文件中。
3. 词的列表的起始位置为 1 。 词的定义为文本中由大小写字母组成的最大序列。
大写字母和小写字母认为是不同的字母，即 abc 和 Abc 是不同的词。
词的例子如下： x-ray 包括两个词 x 和 ray；
mary's 包括两个词 mary 和 s；
a c-Dec 包括三个词 a 和 c 和 Dec 

编写一个程序，输入为一组字符串，输出为压缩后的文本。

输入：
输入为一段文本，可以假设输入中不会出现数字、每行的长度不会超过 80 个字符，
并且输入文本的大小不会超过 10M。

输出：
压缩后的文本。
*/

int main(int argc, char *argv[]) {
	static char a[81],b[1000][81];
	static int len,m[1000],f[1000];
	static int i,j,p,q,k,n,flag,t; 
	while(gets(a)!=NULL){
		len=strlen(a);
		for(j=0;j<len;j++){
			while((a[j]>=65&&a[j]<=90)||(a[j]>=97&&a[j]<=122)){
				b[p][q]=a[j];
				q++;j++;
			}
			if((b[p][0]>=65&&b[p][0]<=90)||(b[p][0]>=97&&b[p][0]<=122)){
				q=0;
				for(k=0,flag=0;k<p;k++){
					if(strcmp(b[k],b[p])==0) {
						printf("%d",m[p]);
						flag=1;
						break;
					}
				}
				if(flag==0) {
					n++;
					for(k=0;b[p][k]!='\0';k++){
						printf("%c",b[p][k]);
					}
				}
				m[p]=n;
			}
			else printf("%c",b[p][0]);
			p++;
			b[p][0]=a[j];
			p++;
		}
		printf("\n");
	/*	for(;f[t]!=1;t++){
			if(m[t]==0) printf("%c",b[t][0]);
			else {
			     for(k=0,flag=0;k<t;k++){
				     if(strcmp(b[t],b[k])==0) {
				     	flag=1;
						printf("%d",m[k]);
				     	break;
				     }
			     }
			     if(flag==0)
				      for(j=0;b[t][j]!='\0';j++){
			     	      printf("%c",b[t][j]);
			          }
		    }
		}
		printf("\n");*/
	}
	return 0;
}
