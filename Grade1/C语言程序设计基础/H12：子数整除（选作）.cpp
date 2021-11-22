#include <stdio.h>
int main()
{
	int k, i;
	scanf ("%d", &k);
	for (i = 10000; i <= 30000; i++)
	{
		int a[6], temp = i, j = 5;
		while (temp > 0)
		{
			a[j--] = temp % 10;
			temp = temp / 10;
		}
		int sub1 = a[1]*100 + a[2]*10 +a[3], sub2 = a[2]*100 + a[3]*10 + a[4], sub3 = a[3]*100 + a[4]*10 + a[5];
		if (sub1 % k == 0 && sub2 % k == 0 && sub3 % k == 0)
			printf ("%d\n", i);
		
	}
	
}