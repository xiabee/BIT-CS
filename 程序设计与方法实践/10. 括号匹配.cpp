#include<stdio.h>
#include<string.h>
#include<stdlib.h>
long long n, i, total = 0, flag = 0;
int len, j, left, right;
int p[2][100100];
char a[100100];
int main()
{
	scanf("%lld%*c", &n);		//舍弃回车； 
	/*int *p1=NULL;
	int *p2=NULL;	//分别记录左右括号个数
	p1=(int *)malloc(sizeof(int)*n);
	p2=(int *)malloc(sizeof(int)*n);*/
	memset(p, 0, sizeof(p));
	memset(a, '\0', sizeof(a));
	for (i = 0; i < n; i++)
	{
		left = 0;
		right = 0;
		scanf("%s", a);
		len = strlen(a);
		for (j = 0; j < len; j++)
		{
			if (a[j] == '(')		//记录左括号 
				left++;
			if (a[j] == ')')		//记录右括号
			{
				if (left)
					left--;			//匹配时，left先减 
				else
					right++;		//无法减时，right加 
			}
		}
		if (left != 0 && right != 0)		//判断非法括号 
			continue;
		if (left == 0 && right == 0)
		{
			flag++;
			continue;
		}
		p[0][left]++;		//记录左括号为left的括号列个数； 
		p[1][right]++;
	}
	for (i = 1; i < n; i++)
	{
		if (p[0][i] > p[1][i])
			total += p[1][i];
		else
			total += p[0][i];
	}
	printf("%lld\n", total + flag / 2);
	return 0;
}