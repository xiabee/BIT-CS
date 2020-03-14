#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int T, i, j, k, v, len, n, len1, len2;
char stra[110], strb[110], str1[110], str2[110], temp[110];
long long total = 0, sum, gg, tag;
long long kkk;
int main()
{
	v = scanf("%d", &T);
	while (T--)
	{
		gg = 1;
		memset(stra, '\0', sizeof(stra));
		memset(strb, '\0', sizeof(strb));
		memset(str1, '0', sizeof(str1));
		memset(str2, '0', sizeof(str2));//str1,str2鍊掑彊瀛樺偍
		memset(temp, '\0', sizeof(temp));
		sum = 0;
		v = scanf("%s%s%lld", stra, strb, &kkk);
		len1 = strlen(stra);
		len2 = strlen(strb);
		for (i = 0; i < len1; i++)
		{
			str1[i] = stra[len1 - i - 1];
		}
		for (i = 0; i < len2; i++)
			str2[i] = strb[len2 - i - 1];//鍊掑彊鍌ㄥ瓨
		strcpy(temp, str1);
		while (1)
		{//澶ф暟鍔犳硶
			gg = 1;
			for (i = 0; i < len2; i++)
			{
				if (temp[i] > '9')
				{
					temp[i + 1]++;
					temp[i] -= 10;
				}
			}
			if (strcmp(temp, str2) == 0)
				break;
			for (i = 0; i < len2; i++)//len2>len1
			{
				if (temp[i] == '0')
					break;
				gg *= ((long long)temp[i] - '0');
			}
			if (gg == kkk)
			{
				total++;
				sum++;
			}
			temp[0] = temp[0] + 1;
		}
		sum %= 1000000007;
		printf("%lld\n", sum);
	}
	total %= 1000000007;
	printf("%lld\n", total);
	return 0;
}