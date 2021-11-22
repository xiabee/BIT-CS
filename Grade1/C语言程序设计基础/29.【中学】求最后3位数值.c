#include <stdio.h>
int main()
{
  int a,n,i,x=1,y=1; 
  scanf("%d %d",&a,&n);
  for(i=0;i<n;i++){
    x=x*a;
    y=x%1000;
    x=y;
  }
  if((a%10==0&&n>2)||(a%100==0&&n>1)) printf("The last 3 numbers is 000.\n");
  else printf("The last 3 numbers is %d.\n",y);
  return 0;
}
