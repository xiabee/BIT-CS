#include <stdio.h>  
#include <stdlib.h>

int main(int argc, char *argv[]) {
    int n,i,j,min=1,max,t,p,q=0,sum;
    scanf("%d",&n);
    for(i=1,max=9*n;i<n;i++){
      min*=10;
      max*=9;
    }
    if(n==6){
      min=500000;
      max=600000;
    }
    for(;min<=max;min++){      
      t=min;
	  p=min;
      int a[n],b[n];          
	  for(i=0,sum=0;i<n;i++){   
        a[i]=t%10;
        for(b[i]=1,j=1;j<=n;j++)    
          b[i]*=a[i];   
        sum+=b[i];   
        if(sum>p) break;
        t/=10;   
      }   
      if(p==sum){
        printf("%d\n",p);
        q=1;
	  }
    }
    if(q==0)
      printf("No output.\n");   
    return 0;   
}
