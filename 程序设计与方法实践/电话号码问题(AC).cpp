#include<stdio.h>
#include<string.h>
#include<stdlib.h>
char num[250010] = { 0 }, a[100] = { 0 };
int ph, b[100] = { 0 };
typedef struct 
{
	int num1;
	int g;
}number;
number ber[1501] = { 0 };
int comp(const void*a, const void*b)
{
	return ((*(number*)a).num1 - (*(number*)b).num1);
}
int main()
{
	int i, j = 0, k = 0, n, x, y, r, flag1 = 0, flag2 = 0, flag3 = 0, flag4 = 0;
	printf("Error:\n");
	o:while (scanf("%s", a) != EOF)
	{
		for(i=0;i<strlen(a);i++)
		{
			if (a[i] == 'Q' || a[i] == 'Z')
			{
				printf("%s\n", a); flag1 = 1;goto o;
			}
			if (a[i] == '-') continue;
			if (a[i] == 'A' || a[i] == 'B' || a[i] == 'C')
			{
				b[j++] = 2; continue;
			}
			if (a[i] == 'D' || a[i] == 'E' || a[i] == 'F')
			{
				b[j++] = 3; continue;
			}
			if (a[i] == 'G' || a[i] == 'H' || a[i] == 'I')
			{
				b[j++] = 4; continue;
			}
			if (a[i] == 'J' || a[i] == 'K' || a[i] == 'L')
			{
				b[j++] = 5; continue;
			}
			if (a[i] == 'M' || a[i] == 'N' || a[i] == 'O')
			{
				b[j++] = 6; continue;
			}
			if (a[i] == 'P' || a[i] == 'R' || a[i] == 'S')
			{
				b[j++] = 7; continue;
			}
			if (a[i] == 'T' || a[i] == 'U' || a[i] == 'V')
			{
				b[j++] = 8; continue;
			}
			if (a[i] == 'W' || a[i] == 'X' || a[i] == 'Y')
			{
				b[j++] = 9; continue;
			}
			if (47<a[i]<58)
			{
				b[j++] = a[i]-48; continue;
			}
		}
		if (j!= 7) {printf("%s\n", a); flag1 = 1;}
		else if (b[0] != 3&&b[0] != 6) {printf("%s\n", a); flag1 = 1;}
		else
		{
			n = b[1] * 100000 + b[2] * 10000 + b[3] * 1000 + b[4] * 100 + b[5] * 10 + b[6];
			if (b[0] == 6) x = n / 8 + 125000;
			else x = n / 8; 
			y = n % 8;
			if ( (num[x] & (1 << y))== 0)
			{
				num[x]+= (1 << y);
			}
			else 
			{
				flag2 = 1;
				if (b[0] == 3) ph = 3000000 + n;
				if (b[0] == 6) ph = 6000000 + n;
				for (i = 0; i <= k; i++)
				{
					if (ph == ber[i].num1) {ber[i].g++;flag4=1;break;}
				}
				if(flag4==0) { ber[r].num1 = ph;ber[r].g = 2;flag3=1;r++;}
				if(flag3==1) k++;flag3=0;flag4=0;
			}
		}
		j = 0;
		memset(a, 0, sizeof(a));
		memset(b, 0, sizeof(b));
	}
	if (flag1 == 0) printf("Not found.\n");
	printf("\n");
	printf("Duplication:\n");
	if (flag2 == 0) printf("Not found.\n");
	else
	{
		qsort(ber,k,sizeof(ber[0]),comp);
		for (i = 0; i < k; i++)
		{
			printf("%d-%04d %d\n", ber[i].num1 / 10000, ber[i].num1 % 10000, ber[i].g);
		}
	}
}
