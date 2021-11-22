/*求数列的最大子列和*/
#include<stdio.h>
int Maxsub(int a[],int n)
{
	int i,Thissum=0,Maxsum=0;
	for(i=0;i<n;i++)
	{
		Thissum+=a[i];
		if(Thissum>Maxsum)
			Maxsum=Thissum;
		else if(Thissum<0)
			Thissum=0;
	} 
	return Maxsum;
}
int main(void)
{
	int n,i,a[100000];
	scanf("%d",&n);
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	printf("%d",Maxsub(a,n));
	return 0;
}
