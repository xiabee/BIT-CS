#include<stdio.h> 
int main(int argc,char **argv)
{
	int i,k;
	scanf("%d", &k);
	//getchar();
	int x,y,z;
	for (i=10000;i<=30000;i++)
	{
		x=i/100;
		y=i%10000/10;
		z=i%1000;
		if(x%k==0&&y%k==0&&z%k==0)
		{
			printf("%d\n",i);
		}
	}
	return 0;
}
