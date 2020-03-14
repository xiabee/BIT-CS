#include<stdio.h>
#include<string.h>
int key[200]={0};
char ch1[200],ch2[200],tmp1[200],tmp2[200];
int main()
{
    int i,j,tmp1len,ch1len;
    gets(tmp1);
    gets(tmp2);
    gets(ch1);
    ch1len=strlen(ch1);
    tmp1len=strlen(tmp1);
    for(i=0;i<tmp1len;i++)
        for(j=0;j<tmp1len;j++){
            if(tmp1[i]==tmp1[j] && i != j && tmp2[i]!=tmp2[j]){
                printf("Failed");
                return 0;
            }
        }
    for(i=0;i<tmp1len;i++)
        for(j=0;j<tmp1len;j++){
            if(tmp2[i]==tmp2[j] && i != j && tmp1[i]!=tmp1[j]){
                printf("Failed");
                return 0;
            }
        }
    for(i=0;i<tmp1len;i++){
        key[tmp1[i]]=tmp2[i];
    }
    for(i='A';i<='Z';i++){
        if(key[i]==0){
            printf("Failed");
            return 0;
        }
    }
    for(i=0;i<ch1len;i++){
        if(key[ch1[i]]==0){
            printf("Failed");
            return 0;
        }
        ch2[i]=key[ch1[i]];
    }
    printf("%s",ch2);
    return 0;
}
