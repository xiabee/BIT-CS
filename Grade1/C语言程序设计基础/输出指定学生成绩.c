#include<stdio.h>
int main()
{
	int a[3][4];
	int n,i,j;
	double x;
	int tx; 
	for(i=0;i<3;i++)
	{
		for(j=0;j<4;j++)
			scanf("%d",&a[i][j]);
	}
	scanf("%d",&n);
	for(i=0;i<3;i++)
	{
		x+=a[n-1][i];
		printf("%d ",a[n-1][i]);
	}
		x+=a[n-1][3];
		printf("%d\n",a[n-1][3]);
	tx=(int)(x/4);
	if(tx==(x/4))
		printf("%d",tx);
	else
		printf("%.2lf\n",x/4);
	return 0;
}
