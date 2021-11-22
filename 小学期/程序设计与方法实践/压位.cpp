#include<bits/stdc++.h>
using namespace std;
#define w 9
const long long jw = 1e9;
const int MAXN = 800005;
char s1[MAXN],s2[MAXN];
long long a[MAXN],b[MAXN],ans[MAXN];
 
int change(char s[],long long n[])
{
	char temp[MAXN];
	int len = strlen(s + 1),now = 0;
	while(len/w)
	{
		strncpy(temp,s+len-w + 1,w);
		n[++now] = atoi(temp);
		len -= w;
	}
	if(len)
	{
		memset(temp,0,sizeof temp); 
		strncpy(temp,s + 1,len);
		n[++now] = atoi(temp);
	}
	return now;
}
void calc(long long a[],long long b[],long long c[],int l1,int l2)
{
	
	for(int i = 1;i <= l1;i++)
	{
		for(int j = 1;j <= l2;j++)
		{
			c[i + j - 1] += a[i] * b[j];
			c[i + j] += c[i + j - 1] / jw;
			c[i + j - 1] = c[i + j - 1] % jw;
		}
	}
	return;
}
void print(long long a[])
{
	for(int i = 200000;i > 0;i--)
	{
		if(a[i] != 0)
		{
			printf("%d",a[i]);
			for(int j = i - 1;j >= 1;j--)
			{
				printf("%0*d",w,a[j]);
			}
			printf("\n");
			break;
		}
	}
}
int main()
{
	scanf("%s %s",s1 + 1,s2 + 1);
	int la = change(s1 ,a),
		lb = change(s2 ,b);
		
	calc(a,b,ans,la,lb);
	
	print(ans);
	return 0;
}
