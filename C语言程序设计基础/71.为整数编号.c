
/*使用以下结构
struct nn
{
   int no;
   int num;
};

建立一个结构数组，从键盘输入若干个整数，保存在数组元素的num成员中，并根据输入的数按从小到大进行编号，将编号保存在no成员中。按整数的输入顺序输出整数及其编号。输入的整数不超过100个，每个整数的绝对值不大于1000，输入时以空格分隔整数。
例如输入：4 3 6 8 2 3 9
输出：
      4 4
      3 2
      6 5
      8 6
      2 1
      3 3
      9 7
要求：当两个整数相等时，整数的排列顺序由输入的先后次序决定。例如：输入的第2个整数为3，第6个整数也为3，则将先输入的整数3的编号在前，后输入的整数3的编号在后。编写函数完成为整数编号。

函数原型：int number( char *str, struct nn a[] );
其中：str：保存以字符串方式接收的键盘输入，
          a： 保存整数及编号的结构数组的首地址，
函数返回值：已输入的整数的个数。 
*/
/* PRESET CODE BEGIN - NEVER TOUCH CODE BELOW */

#include <stdio.h>
struct nn
{  int no;   
   int num;   
};

typedef struct nn DATA;

int number( char * , DATA []);

int main( )
{   
   DATA b[100];  
   char sa[500];  
   int i, n;  
   gets( sa ); 
   n = number( sa, b ); 
   for ( i=0; i<n; i++ ) 
       printf("%d %d\n", b[i].num, b[i].no ); 
   return 0;
}


  int number( char * str, DATA a[] )
  {int i,j,k,num=0,f[100]={0};
  DATA c[100],t;
  	for(i=0;str[i]!='\0';i++){
  		if(str[i]==' ') continue;
  		else {if(str[i+1]>=48&&str[i+1]<=57){
  			if(str[i+2]>=48&&str[i+2]<=57){
  				a[num].num=(str[i]-48)*100+(str[i+1]-48)*10+(str[i+2]-48);
  				c[num].num=a[num].num;
  				i=i+2;
  				num++;
  			}
  			else{
  				a[num].num=(str[i+1]-48)*10+(str[i+2]-48);
  				c[num].num=a[num].num;
  				i=i+1;
  				num++;
  			}
  			
  		}
  		else{
  		  a[num].num=str[i]-48;
		  c[num].num=a[num].num;
		  num++;
  		}

  		}
  	}
	  for(i=0;i<num-1;i++){
	  	k=i;
	  	for(j=i+1;j<num;j++){
	  		if(c[k].num>c[j].num) k=j;
	  	}
	  	if(k!=i){
	  		t=c[k];
	  		c[k]=c[i];
	  		c[i]=t;
	  	}
	  } 
	  for(i=0;i<num;i++){
	  	c[i].no=i+1;
	  }
	  for(i=0;i<num;i++){
	  	for(j=0;j<num;j++){
	  		if(a[i].num==c[j].num&&f[j]==0){
	  			a[i].no=c[j].no;
	  			f[j]=1;
	  			break;
	  		}
	  	}
	  }
	  return num;
  }


