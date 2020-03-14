#include <stdio.h>

int main()
{
  int n,m,i,b,max=0,h=0,l=0,s,bull=0,shuzu[10][10];
  scanf("%d %d",&n,&m);
  fflush(stdin);
  for(i=0;i<n;i++){       //行循环//
    for(b=0;b<m;b++){             //列循环//
      scanf("%d",&shuzu[b][i]);
    }
  fflush(stdin);
  }
  for(i=0;i<n;i++){
    max=shuzu[0][i];
    for(b=0;b<m;b++){
      if(shuzu[b][i]>max){
        max=shuzu[b][i];
        l=b;
        h=i;
      }
      else ;
    }
    for(s=0;s<n;s++){
      if(max>shuzu[l][s]){
      bull++;
      break;
      }
      else ;
    }
    if(s==n) break;
  }
  if(bull==n) printf("No Point\n");
  else printf("Point:a[%d][%d]==%d\n",h,l,max);
  return 0;
}
