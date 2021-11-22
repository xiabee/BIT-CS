#include <stdio.h>  

int main(){
  char a;
  int i,j,n;  
  scanf("%d %c",&n,&a);  
  i=1;  
  if(a<'A'||a>'Z') printf("input error.\n");  
  else {
    while(i<=2*n-1){
	  j=1;
	  if(i<=n) {
	    while(j<=2*n-i){
		  if(j==i||j==2*n-i){
		    if(a+n-i>90) printf("%c",a-26+n-i);
            else printf("%c",a+n-i);
		  }
		  else printf(" ");
          j++;
		}
	  }  
      else {
	    while(j<=i){
		  if(j==i||j==2*n-i){
		    if(a+n-i<65) printf("%c",a+26+n-i);
            else printf("%c",a+n-i);
		  }
		  else printf(" ");
		  j++;
		}
	  }  
    printf("\n");  
    i++;}
  }  
}
