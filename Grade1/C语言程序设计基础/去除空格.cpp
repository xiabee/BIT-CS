#include<stdio.h>  
    int main() {  
        char ch,chs[200]={'\0'};  
        int count=0;  
        while((ch=getchar())!='\n') {  
            if(ch==' ')   
                continue;  
            chs[count++]=ch;  
        }  
        \\printf("%d\n%s\n",count,chs);  
    }
