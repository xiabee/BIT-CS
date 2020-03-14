#include <stdio.h>

int main(){
  int i,j,m,n;  
  scanf("%d %d",&n,&m);  
  j=1;  
  while(j<3*n-2){
    if(j<=(3*n-1)/2)  printf("%-2d",(m+j-1)%10);  
    else  printf("%-2d",(m+3*n-j-2)%10);  
    j++;
  }  
  if(n!=1) printf("%d\n",m);  
  i=2;  
  while(i<n){
    j=1;  
    while(j<3*n-i-1){
	  if(j==i) printf("%-2d",(m+i-1)%10);  
      else printf("  ");  
      j++;
	}  
    printf("%d\n",(m+i-1)%10);  
    i++;
  }  
  j=1;  
  while(j<2*n-1){
  if(j<n) printf("  ");  
  else if(j<=(3*n-1)/2) printf("%-2d",(m+j-1)%10);  
       else printf("%-2d",(m+3*n-j-2)%10);  
  j++;
  }
  printf("%d\n",(m+3*n-j-2)%10);  
}
