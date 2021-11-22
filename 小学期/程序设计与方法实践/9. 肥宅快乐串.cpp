#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int n, i, len;
char a[100010];
/*只在伪fattyhappy内部互换*/
const char hap[91][11] = { "fattyhappy","afttyhappy","taftyhappy","tatfyhappy","yattfhappy","hattyfappy","aattyhfppy","pattyhafpy","pattyhapfy","yattyhappf","afttyhappy","ftatyhappy","fttayhappy","fyttahappy","fhttyaappy","fattyhappy","fpttyhaapy","fpttyhapay","fyttyhappa","taftyhappy","ftatyhappy","fattyhappy","faytthappy","fahtytappy","faatyhtppy","faptyhatpy","faptyhapty","faytyhappt","tatfyhappy","fttayhappy","fattyhappy","fatythappy","fathytappy","fatayhtppy","fatpyhatpy","fatpyhapty","fatyyhappt","yattfhappy","fyttahappy","faytthappy","fatythappy","fatthyappy","fattahyppy","fattphaypy","fattphapyy","fattyhappy","hattyfappy","fhttyaappy","fahtytappy","fathytappy","fatthyappy","fattyahppy","fattypahpy","fattypaphy","fattyyapph","aattyhfppy","fattyhappy","faatyhtppy","fatayhtppy","fattahyppy","fattyahppy","fattyhpapy","fattyhppay","fattyhyppa","pattyhafpy","fpttyhaapy","faptyhatpy","fatpyhatpy","fattphaypy","fattypahpy","fattyhpapy","fattyhappy","fattyhaypp","pattyhapfy","fpttyhapay","faptyhapty","fatpyhapty","fattphapyy","fattypaphy","fattyhppay","fattyhappy","fattyhapyp","yattyhappf","fyttyhappa","faytyhappt","fatyyhappt","fattyhappy","fattyyapph","fattyhyppa","fattyhaypp","fattyhapyp" };
const int hap_1[91][2] = { 3,4,1,2,1,3,1,4,1,5,1,6,1,7,1,8,1,9,1,10,2,1,2,3,2,4,2,5,2,6,2,7,2,8,2,9,2,10,3,1,3,2,3,4,3,5,3,6,3,7,3,8,3,9,3,10,4,1,4,2,4,3,4,5,4,6,4,7,4,8,4,9,4,10,5,1,5,2,5,3,5,4,5,6,5,7,5,8,5,9,5,10,6,1,6,2,6,3,6,4,6,5,6,7,6,8,6,9,6,10,7,1,7,2,7,3,7,4,7,5,7,6,7,8,7,9,7,10,8,1,8,2,8,3,8,4,8,5,8,6,8,7,8,9,8,10,9,1,9,2,9,3,9,4,9,5,9,6,9,7,9,8,9,10,10,1,10,2,10,3,10,4,10,5,10,6,10,7,10,8,10,9 };
/*在伪fattyhappy内外互换*/
const char hap2[260][11] = { "aattyhappy","battyhappy","cattyhappy","dattyhappy","eattyhappy","fattyhappy","gattyhappy","hattyhappy","iattyhappy","jattyhappy","kattyhappy","lattyhappy","mattyhappy","nattyhappy","oattyhappy","pattyhappy","qattyhappy","rattyhappy","sattyhappy","tattyhappy","uattyhappy","vattyhappy","wattyhappy","xattyhappy","yattyhappy","zattyhappy","fattyhappy","fbttyhappy","fcttyhappy","fdttyhappy","fettyhappy","ffttyhappy","fgttyhappy","fhttyhappy","fittyhappy","fjttyhappy","fkttyhappy","flttyhappy","fmttyhappy","fnttyhappy","fottyhappy","fpttyhappy","fqttyhappy","frttyhappy","fsttyhappy","ftttyhappy","futtyhappy","fvttyhappy","fwttyhappy","fxttyhappy","fyttyhappy","fzttyhappy","faatyhappy","fabtyhappy","factyhappy","fadtyhappy","faetyhappy","faftyhappy","fagtyhappy","fahtyhappy","faityhappy","fajtyhappy","faktyhappy","faltyhappy","famtyhappy","fantyhappy","faotyhappy","faptyhappy","faqtyhappy","fartyhappy","fastyhappy","fattyhappy","fautyhappy","favtyhappy","fawtyhappy","faxtyhappy","faytyhappy","faztyhappy","fatayhappy","fatbyhappy","fatcyhappy","fatdyhappy","fateyhappy","fatfyhappy","fatgyhappy","fathyhappy","fatiyhappy","fatjyhappy","fatkyhappy","fatlyhappy","fatmyhappy","fatnyhappy","fatoyhappy","fatpyhappy","fatqyhappy","fatryhappy","fatsyhappy","fattyhappy","fatuyhappy","fatvyhappy","fatwyhappy","fatxyhappy","fatyyhappy","fatzyhappy","fattahappy","fattbhappy","fattchappy","fattdhappy","fattehappy","fattfhappy","fattghappy","fatthhappy","fattihappy","fattjhappy","fattkhappy","fattlhappy","fattmhappy","fattnhappy","fattohappy","fattphappy","fattqhappy","fattrhappy","fattshappy","fattthappy","fattuhappy","fattvhappy","fattwhappy","fattxhappy","fattyhappy","fattzhappy","fattyaappy","fattybappy","fattycappy","fattydappy","fattyeappy","fattyfappy","fattygappy","fattyhappy","fattyiappy","fattyjappy","fattykappy","fattylappy","fattymappy","fattynappy","fattyoappy","fattypappy","fattyqappy","fattyrappy","fattysappy","fattytappy","fattyuappy","fattyvappy","fattywappy","fattyxappy","fattyyappy","fattyzappy","fattyhappy","fattyhbppy","fattyhcppy","fattyhdppy","fattyheppy","fattyhfppy","fattyhgppy","fattyhhppy","fattyhippy","fattyhjppy","fattyhkppy","fattyhlppy","fattyhmppy","fattyhnppy","fattyhoppy","fattyhpppy","fattyhqppy","fattyhrppy","fattyhsppy","fattyhtppy","fattyhuppy","fattyhvppy","fattyhwppy","fattyhxppy","fattyhyppy","fattyhzppy","fattyhaapy","fattyhabpy","fattyhacpy","fattyhadpy","fattyhaepy","fattyhafpy","fattyhagpy","fattyhahpy","fattyhaipy","fattyhajpy","fattyhakpy","fattyhalpy","fattyhampy","fattyhanpy","fattyhaopy","fattyhappy","fattyhaqpy","fattyharpy","fattyhaspy","fattyhatpy","fattyhaupy","fattyhavpy","fattyhawpy","fattyhaxpy","fattyhaypy","fattyhazpy","fattyhapay","fattyhapby","fattyhapcy","fattyhapdy","fattyhapey","fattyhapfy","fattyhapgy","fattyhaphy","fattyhapiy","fattyhapjy","fattyhapky","fattyhaply","fattyhapmy","fattyhapny","fattyhapoy","fattyhappy","fattyhapqy","fattyhapry","fattyhapsy","fattyhapty","fattyhapuy","fattyhapvy","fattyhapwy","fattyhapxy","fattyhapyy","fattyhapzy","fattyhappa","fattyhappb","fattyhappc","fattyhappd","fattyhappe","fattyhappf","fattyhappg","fattyhapph","fattyhappi","fattyhappj","fattyhappk","fattyhappl","fattyhappm","fattyhappn","fattyhappo","fattyhappp","fattyhappq","fattyhappr","fattyhapps","fattyhappt","fattyhappu","fattyhappv","fattyhappw","fattyhappx","fattyhappy","fattyhappz" };
const char happ[10] = { 'f','a','t','t','y','h','a','p','p','y' };//记录hap2缺少的字母 
const int hap_2[10] = { 1,2,3,4,5,6,7,8,9,10 };

int main()
{
	int j, k, k1, l, m, flag, flag1;
	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		memset(a, '\0', sizeof(a));
		flag = 0;
		flag1 = 0;
		scanf("%s", a);
		len = strlen(a);
		//printf("%d\n",len);
		char sub1[11] = { '\0' };		//记录子串
		char sub2[11] = { '\0' };
		for (j = 0; j < len - 9; j++)
		{
			for (l = 0; l < 10; l++)
				sub1[l] = a[l + j];		//按位切分 
			for (k = 0; k <= 91; k++)		//遍历答案表 
				if (!strcmp(sub1, hap[k]))
				{
					flag = 1;
					if (hap_1[k][0] < hap_1[k][1])
						printf("%d %d\n", hap_1[k][0] + j, hap_1[k][1] + j);//子串内部互换；
					else
						printf("%d %d\n", hap_1[k][1] + j, hap_1[k][0] + j);//子串内部互换；
					break;
				}
			if (flag)
				break;
		}
		if (!flag)	//子串内部无法互换 
		{
			for (j = 0; j < len - 9; j++)
			{
				for (l = 0; l < 10; l++)
					sub2[l] = a[l + j];
				for (k = 0; k < 260; k++)
					if (!strcmp(sub2, hap2[k]))
					{
						for (m = 0; m < len; m++)//遍历原数组
						{
							if (m > j && m < j + 10)		//不能从子串中找字符 
								continue;
							if (a[m] == happ[k / 26])
							{
								flag1 = 1;
								if (m + 1 < hap_2[k / 26] + j - 1)
									printf("%d %d\n", m + 1, hap_2[k / 26] + j);
								else
									printf("%d %d\n", hap_2[k / 26] + j, m + 1);
								break;
							}
							if (flag1)
								break;
						}
					}
			}
		}
		if (!flag & !flag1)
			printf("-1\n");
	}
	return 0;
}