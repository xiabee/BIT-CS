#include <stdio.h>  
int is_num(char a)  
{  
	if (a >= '0' && a <= '9') return 1;  
	else return 0;  
}  
		
int main()  
{  
	char a[1000], c;  
	int i, min = 1000000, max = -1000000, r;  
	gets(a);  
	for (i = 0; a[i] != '='; i++)  
	{	 
		int temp = 0;  
		if (is_num(a[i]))   
		{		 
			while (is_num(a[i]))  
			{  
				temp = temp * 10 + (a[i] - '0');  
				i++;  
			}  
			if (temp < min)  min = temp;  
			if (temp > max)  max = temp;  
		}  
		else if (a[i] == '-'&&is_num(a[i+1]))  
		{	 
			i++;  
			while (is_num(a[i]))  
			{  
				temp = temp * 10 + (a[i] - '0');  
				i++;	  
			}  
			temp = -temp;  
			if (temp < min)  min = temp;  
			if (temp > max)  max = temp;  
		}  
		
		  
		if (a[i] == '+' || a[i] == '*' || a[i] == '-' || a[i] == '/' || a[i] == '%')  
			c = a[i];  
		switch (a[i])  
		{  
			case '+': r = max + min;break;  
			case '-': r = max - min;break;  
			case '*': r = max * min;break;  
			case '%': r = max % min;break;  
			case '/': r = max / min;break;  
		}  
	}  
	if (min >= 0 && max >= 0) printf ("%d %c %d = %d\n",max, c, min, r);  
	else if (min < 0 && max >= 0) printf ("%d %c (%d) = %d\n",max, c, min, r);  
	else if (min >= 0 && max < 0) printf ("(%d) %c %d = %d\n",max, c, min, r);
	else if (min < 0 && max < 0) printf ("(%d) %c (%d) = %d\n",max, c, min, r);
	  
}