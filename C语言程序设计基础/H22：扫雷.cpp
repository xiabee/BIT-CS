#include <stdio.h>  
#include <string.h>  
int main()  
{  
	int n, m, i, j, d = 1;		  //n - hang, m - lie  
	char lei[1000][1000];	 
	while (scanf ("%d %d", &n, &m))  
	{  
		if ( n == 0 && m == 0)  
			break;  
		else  
		{  
			memset(lei, 0, sizeof(lei));  
			for (j = 0; j < n; j++)		  //输入   
			{  
				char temp = getchar();  
				for (i = 0; i < m; i++)  
					scanf ("%c", &lei[j][i]);  
			}  
			  
			  
			if (d != 1) printf ("\nField #%d:\n", d++);  
			else printf ("Field #%d:\n", d++);  
			  
			for (j = 0; j < n; j++)  
			{  
				for (i = 0; i < m; i++)   //选格子   
				{	 
					int tot = 0;  
					if (lei[j][i] == '*')   
						 printf ("*");  
					else  
					{  
						if (j-1 >= 0 && i-1 >= 0 && lei[j-1][i-1] == '*') tot++;  
						if (j-1 >= 0 && i >= 0 && lei[j-1][i] == '*') tot++;  
						if (j-1 >= 0 && i+1 < m && lei[j-1][i+1] == '*') tot++;  
						if ( i-1 >= 0 && lei[j][i-1] == '*') tot++;  
						if ( i+1 < m && lei[j][i+1] == '*') tot++;  
						if (j+1 < n && i-1 >= 0 && lei[j+1][i-1] == '*') tot++;  
						if (j+1 < n && lei[j+1][i] == '*') tot++;  
						if (j+1 < n && i+1 < m && lei[j+1][i+1] == '*') tot++;  
						printf ("%d", tot);  
					}		 
				}  
				printf ("\n");  
			}   
		}  
	}  
	  
}