#include <stdio.h>
#include <stdlib.h>
int main()
{
  int t=0,a[50],p[2]={0},c=0,max=0,r,i;
  scanf("%d",&r);
  for(i=0;i<r;i++)
  scanf("%d",&a[i]); 
  a[r]=51;
  for(i=1;i<=r;i++){
    if(a[i]==a[i-1]) 
    c++;
    else{
      if(c>max){
        p[0]=t;
        p[1]=i-1;
        max=c;	
      }
    c=0;t=i;
    }	
  }
  if(p[1])   
    printf("The longest equal number list is from %d to %d.\n",p[0],p[1]);
  else 
    printf("No equal number list.\n");
  system("pause");
}
