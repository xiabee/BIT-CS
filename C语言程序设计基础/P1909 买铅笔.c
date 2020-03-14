#include <stdio.h>
int main()
{
   int n,a1,a2,b1,b2,c1,c2,a,b,c,z;
   scanf("%d",&n);
   scanf("%d %d",&a1,&a2);
   scanf("%d %d",&b1,&b2);
   scanf("%d %d",&c1,&c2);
   a=n/a1;a1=n%a1==0?a:a+1;a=a1*a2;
   b=n/b1;b1=n%b1==0?b:b+1;b=b1*b2;
   c=n/c1;c1=n%c1==0?c:c+1;c=c1*c2;
   if(a<b&&a<c)z=a;
   if(b<a&&b<c)z=b;
   if(c<b&&c<a)z=c;
   printf("%d\n",z);
   return 0;
}
