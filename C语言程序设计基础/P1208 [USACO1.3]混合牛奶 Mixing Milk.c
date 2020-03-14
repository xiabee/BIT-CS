#include<stdio.h>
#include<string.h>
struct df//Dairy farmer
{
	int price,number;
}a[2000001];
int main()
{
	int i,j,n,m,sum=0,total=0;
	struct df temp;
	scanf("%d%d",&n,&m);
	for(i=0;i<m;i++)
		scanf("%d %d",&a[i].price,&a[i].number);
	for(i=0;i<m;i++)//排序 
		for(j=0;j<i;j++)
			if(a[i].price<a[j].price)
			{
				temp=a[i];
				a[i]=a[j];
				a[j]=temp;
			}
	for(i=0;i<m;i++)
	{
		total+=a[i].number;
		sum+=a[i].price*a[i].number;
		if(total>=n)
			break;//溢出； 
	}
	sum-=(total-n)*a[i].price;//减去多余的；
	printf("%d\n",sum);
	return 0; 
}
