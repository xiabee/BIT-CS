#include<stdio.h>
#include<stdlib.h>
int main()
{  
 int N,n,i,s=0,a=0;  
 scanf("%d %d",&N,&n);  
 for(i=2;i<=N;i++)  
 {s=(s+n)%i;  
  a=s+1;
 }
 printf("The left child is NO %d.\n",a);  
 system("pause");
}
