#include<stdio.h>
#include<math.h> 
int isprime(int x)
{
	if(x<=1)
		return 0;
	if(x==2)
		return 1;
	int i;
	for(i=2; i<=sqrt(x); i++)
		if(x%i==0)
			return 0;
	return 1;
}
int main()
{
	int n, cnt=0, ans=-1, i=2;
	scanf("%d",&n);
	while(cnt!=n)
	{
		if(isprime(i))
		{
			cnt++;
			ans=i;
		}
		i++;
	}
	printf("%d\n",ans);
	return 0;
}

