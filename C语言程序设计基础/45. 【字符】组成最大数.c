#include <stdio.h>  
#include <stdlib.h>  
#include <string.h>  
  
 
  
int main(int argc, char *argv[]) {  
    int n,t;  
    int i,j,p;  
    char a[100000];  
    gets(a);  
    n=strlen(a);  
    for(i=0;i<n-1;i++){  
        p=i;  
        for(j=i+1;j<n;j++){  
            if(a[p]<a[j]) p=j;  
        }  
        if(p!=i){  
            t=a[p];  
            a[p]=a[i];  
            a[i]=t;  
        }  
    }   
    puts(a);  
    return 0;  
}
