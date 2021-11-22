#include<stdio.h>
#include<string.h>
int main()
{
	const A='A',Z='Z',S='*',P=' ',N='\n';
	char in[4][100],out[289][52]={'\0'};
	int a[26]={0},k,c,x,most=0;
	for(k=0;k<4;k++)
		gets(in[k]);
	while(k--)//统计各字母出现次数； 
	{
		for(c=0;in[k][c];c++)
			if(in[k][c]>='A'&&in[k][c]<='Z')
				a[in[k][c]-A]++;
	}
	for(c=0;c<26;c++)
		k=most=a[c]>most?a[c]:most;
	do
	{
		for(c=0;c<26;c++)
		{
			if(a[c]==most)
			{
				out[k-most][c*2]=S;
				a[c]--;
				x=c;
			}
			else
				out[k-most][c*2]=P;
		}
		while(x)
			out[k-most][x--*2-1]=P;
	}
	while(--most);//形成字母柱状图；
	for(k=0;out[k][0];k++)
		puts(out[k]);
	for(c=A;c<=Z;c++)
		printf("%c%c",c,c!=Z?P:N);
	return 0;
} 
