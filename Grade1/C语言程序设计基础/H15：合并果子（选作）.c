#include<stdio.h>
int main()
{
    int n,a[10000],s=0,s1=0,i,t,j;
    scanf("%d",&n);
    for(i=0;i<n;i++)
     scanf("%d",&a[i]);
     for(i=0;i<n-1;i++)
      for(j=0;j<n-i-1;j++)
        {
          if(a[j]>a[j+1])
          {
            t=a[j+1];
            a[j+1]=a[j];
            a[j]=t;
          }
        }
       for(i=0;i<n;i++)
         s=s+a[i];
         for(i=0;i<n-1;i++)
           s1=s1+a[i]*(n-i-1);
           printf("%d\n",s+s1-1);
} 
