#include<stdio.h>
#include<math.h>
int main() 
{
	int k,m,flag;
	scanf("%d",&k);
	if(k==2) 
	{
		printf("2\n");
		return 0;
	}
	while(k>2) 
	{
		for(flag=1,m=2;flag&&m<=sqrt(k);++m)
			if(k%m==0)
				flag=0;
		if(flag) {
			printf("%d\n",k);
			break;
		}else 
			--k;
	}
}


