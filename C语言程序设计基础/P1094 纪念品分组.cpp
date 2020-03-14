#include <cstdio>
#include <algorithm>
int limit,n,k[30005],ans=0;
int main(){
    scanf("%d%d",&limit,&n); 
    int i,at,o=0;
    for(i=0;i<n;i++)scanf("%d",&k[i]);
    std::sort(k,k+n);
    for(i=0;i<n;i++){
        for(o=0,at=n-1;at>i;at--)
            if(k[at]<=limit-k[i]){o=1;break;}
        if(o){ans+=n-at;n=at;}else{ans+=n-i;break;}
    }printf("%d\n",ans); 
    return 0;
} 
