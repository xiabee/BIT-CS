#include<stdio.h>
int main()
{
	int n,m,i,a[100005],k=0,l=0;
	scanf("%d%d",&n,&m);
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	for(i=0;i<n;i++)
	{
		if(l+a[i]<=m)	//判断是否超过规定的数
			l+=a[i];
		else	//超过了,段数加一,重置l
		{
			l=a[i];
			k++;
		}
	}
	if(l>0)
		k++;	//处理末尾数
	printf("%d",k);
	return 0;
}
