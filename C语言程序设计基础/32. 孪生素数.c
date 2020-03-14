#include <stdio.h>
/*
int main()
{
  int a,b,i,k,m,n;
  scanf("%d %d",&a,&b);
  for(k=a;k<=b-2;k++)
  {
      m=1;
      for(i=2;i<k;i++)
      if(k%i==0)
	  {
	      m=0;break;
	  }
      if(m==1)
	  {
          n=1;
          for(i=2;i<k+2;i++)
              if((k+2)%i==0)
			  {
	              n=0;
				  break;
	          }
      if(n==1) printf("%d,%d\n",k,k+2); 
	  }
  }
}*/


int main()
{
	int i,j;
	int flag;
	int m,n;
	scanf("%d %d",&n,&m);
	for(i=n;i<=m-2;i++)
	{
		flag=0;
		for(j=2;j<i;j++)
		{
			if((i%j==0)||(i%(j+2)==0))
			flag=1;
		}
		if(flag==0)
		printf("%d %d\n",i,i+2);
	}
	return 0;
}

