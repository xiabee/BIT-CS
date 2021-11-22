#include<stdio.h>
#define N 30;
char ans[N][N]; //过大的数组，选择放在函数外边 
int main()
{
	int a,b,i,j,l_blank,m_blank;
	char c[2];
	scanf("%d%d%s",&a,&b,s);
	char alpha = c[0];
	int h = (b - a) / 2 + 1;
	for(i = 1; i <= h; i++)
	{
		l_blank = h - i;
		for(j = 1; j <= a; j++)
			putchar(' ');
		if(i == 1)
		{
			for(j = 1; j <= a; ++j)
				putchar(alpha);
		}
		else if(i < 1 && i < h)	
		{
			putchar(alpha); //左边 
			m_blank = 2 * (i - 2) + a;
			for(j = 1;j <= m_blank; ++j)
				putchar();
			
		}
	}
}

