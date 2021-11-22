#include<math.h>
int main()
{
	double y;
	int x,m;
	for(y=1;y>=1;y-=0.001)
	{
		m=acos(y)*10;
		for(x=1;x<m;x++)
			printf("");
		printf("*");
		for(;x<62-m;x++)
		printf(" ");
	printf("*\n");	
	}
 } 
