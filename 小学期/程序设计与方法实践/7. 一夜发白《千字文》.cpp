#include<stdio.h>
#include<string.h>
#include<string.h>
#include<math.h>
#define MAX 65538
long long ans[MAX] = { 0 }, i, max = 0, s1, s2, s3;	//记录unicode编码；
int str1, str2, str3, str, flag, j;
int main()
{
	memset(ans, 0, sizeof(ans));
	unsigned char op;
	//freopen("qianziwen1.txt","r",stdin);
	//freopen("7.shuchu.txt","w",stdout);	//改变输入输出； 
	while (scanf("%c", &op) != EOF)
	{
		if (op >> 4 == 14)
		{
			unsigned char op1, op2;
			scanf("%c%c", &op1, &op2);
			str1 = (op - 224) * 4096;			//1110 0000 十进制表达；
			str2 = (op1 - 128) * 64;			//1000 0000
			str3 = op2 - 128;
			str = str1 + str2 + str3;
			ans[str]++;		//记录字符个数
		}
		else if (op >> 5 == 6)
		{
			unsigned char op1;
			scanf("%c", &op1);
			str1 = (op - 192) * 64;				//1100 0000
			str2 = (op1 - 128);					//1000 0000
			str = str1 + str2;
			ans[str]++;		//记录字符个数
		}
	}
	flag = 0;
	for (i = 128; i < MAX; i++)
	{
		if (ans[i] >= 2)
		{
			flag = 1;
			if (i < 2047)		//00000xxx xxyyyyyy型 
			{
				s2 = i % 64 + 128;			//  10yyyyyy
				s1 = i / 64 + 128 + 64;	//  110xxxxx
				printf("%c%c 0x%04x %d\n", s1, s2, i, ans[i]);
			}
			else		//xxxxyyyy yyzzzzzz  1110xxxx 10yyyyyy 10zzzzzz型 
			{
				s3 = i % 64 + 128;				//10zzzzzz
				s2 = (i / 64) % 64 + 128;		//10yyyyyy
				s1 = i / 4096 + 224;	//1110xxxx
				printf("%c%c%c 0x%04x %d\n", s1, s2, s3, i, ans[i]);
			}
		}
	}
	if (!flag)
		printf("No repeat!\n");
	return 0;
}