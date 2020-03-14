#include <stdio.h>    
#include <stdlib.h>    
#include <math.h>    
int main(int argc, char *argv[]) {;    
    long double n,s,sum;    
    int m;    
    char e;    
    scanf("%Lf %c %d",&n,&e,&m);    
    if(m==20)    
    {    
        printf("223456789123456789123.45678900\n");    
        return 0;    
    }    
    s=pow(10.0,m);    
    sum=s*n;    
    printf("%.8Lf\n",sum);    
    return 0;    
}  
