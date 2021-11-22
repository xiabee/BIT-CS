#include <stdio.h>
#include <string.h>
int main()
{

	while (1)
	{
		char a[100][5], b[100][5], c[100][5], d[100][5];
		int na[100], nb[100], nc[100], nd[100]; //0 是牌数 
		int h[15] = {-50, -2,-3,-4,-5,-6,-7,-8,-9,-10,-20,-30,-40}; 
		int ra = 0, rb = 0, rc = 0, rd = 0;
		
		scanf ("%d", &na[0]);
		for (int i = 1; i <= na[0]; i++)   //从1开始的！！ 
			scanf (" %s", a[i]);
		scanf ("%d", &nb[0]);
		for (int i = 1; i <= nb[0]; i++)   //从1开始的！！ 
			scanf (" %s", b[i]);  
		scanf ("%d", &nc[0]);
		for (int i = 1; i <= nc[0]; i++)   //从1开始的！！ 
			scanf (" %s", c[i]);
		scanf ("%d", &nd[0]);
		for (int i = 1; i <= nd[0]; i++)   //从1开始的！！ 
			scanf (" %s", d[i]);
	 
		if (na[0] == 0 && nb[0] == 0 && nc[0] == 0 && nd[0] == 0)
			break;
		else
		{
			for (int i = 1; i <= na[0]; i++)
			{
	if (a[i][0] == 'C')
	 na[i] = 0;
	else if (a[i][0] == 'D')
	 na[i] = 1;
	else if (a[i][0] == 'S')
	 na[i] = 2;
	else if (a[i][0] == 'H')
	 na[i] = 3;
	
	if (a[i][1] == '1' && a[i][2] == '0')
	 na[i] = na[i] + 36;
	else if (a[i][1] == '1' && a[i][2] == '1')
	 na[i] = na[i] + 40;
	else if (a[i][1] == '1' && a[i][2] == '2')
	 na[i] = na[i] + 44;
	else if (a[i][1] == '1' && a[i][2] == '3')
	 na[i] = na[i] + 48;
	else if (a[i][1] >= '1' && a[i][1] <= '9')
	 na[i] = na[i] + (a[i][1] - '0' - 1) * 4;	 
			}
			
			for (int i = 1; i <= nb[0]; i++)
			{
	if (b[i][0] == 'C')
	 nb[i] = 0;
	else if (b[i][0] == 'D')
	 nb[i] = 1;
	else if (b[i][0] == 'S')
	 nb[i] = 2;
	else if (b[i][0] == 'H')
	 nb[i] = 3;
	
	if (b[i][1] == '1' && b[i][2] == '0')
	 nb[i] = nb[i] + 36;
	else if (b[i][1] == '1' && b[i][2] == '1')
	 nb[i] = nb[i] + 40;
	else if (b[i][1] == '1' && b[i][2] == '2')
	 nb[i] = nb[i] + 44;
	else if (b[i][1] == '1' && b[i][2] == '3')
	 nb[i] = nb[i] + 48;
	else if (b[i][1] >= '1' && b[i][1] <= '9')
	 nb[i] = nb[i] + (b[i][1] - '0' - 1) * 4;	 
			}
			
			for (int i = 1; i <= nc[0]; i++)
			{
	if (c[i][0] == 'C')
	 nc[i] = 0;
	else if (c[i][0] == 'D')
	 nc[i] = 1;
	else if (c[i][0] == 'S')
	 nc[i] = 2;
	else if (c[i][0] == 'H')
	 nc[i] = 3;
	
	if (c[i][1] == '1' && c[i][2] == '0')
	 nc[i] = nc[i] + 36;
	else if (c[i][1] == '1' && c[i][2] == '1')
	 nc[i] = nc[i] + 40;
	else if (c[i][1] == '1' && c[i][2] == '2')
	 nc[i] = nc[i] + 44;
	else if (c[i][1] == '1' && c[i][2] == '3')
	 nc[i] = nc[i] + 48;
	else if (c[i][1] >= '1' && c[i][1] <= '9')
	 nc[i] = nc[i] + (c[i][1] - '0' - 1) * 4;	 
			}
			
			for (int i = 1; i <= nd[0]; i++)
			{
	if (d[i][0] == 'C')
	 nd[i] = 0;
	else if (d[i][0] == 'D')
	 nd[i] = 1;
	else if (d[i][0] == 'S')
	 nd[i] = 2;
	else if (d[i][0] == 'H')
	 nd[i] = 3;
	
	if (d[i][1] == '1' && d[i][2] == '0')
	 nd[i] = nd[i] + 36;
	else if (d[i][1] == '1' && d[i][2] == '1')
	 nd[i] = nd[i] + 40;
	else if (d[i][1] == '1' && d[i][2] == '2')
	 nd[i] = nd[i] + 44;
	else if (d[i][1] == '1' && d[i][2] == '3')
	 nd[i] = nd[i] + 48;
	else if (d[i][1] >= '1' && d[i][1] <= '9')
	 nd[i] = nd[i] + (d[i][1] - '0' - 1) * 4;	 
			}
			
			int ns = 0, nnd = 0, nnc = 0, nf = 0, nh = 0;
			for (int i = 1; i <= na[0]; i++)
			{
	if (na[i] % 4 == 3)
	{
	 nh++;
	 nf++;
	 ra =  ra + h[na[i] / 4];
	} 
	if (na[i] == 46)
	{
	 ra = ra - 100;
	 ns = 1;
	 nf++;
	} 
	if (na[i] == 41)
	{
	 ra = ra + 100;
	 nnd = 1;
	 nf++;
	}
	if (na[i] == 36)
	{
	 nnc = 1;
	 nf++;
	} 
			}
			if (nh == 13 && nnd == 1 && ns == 1)
	ra = 500;
			if (nh == 13)
	ra = ra + 194 + 200;
			if (nnc == 1 && na[0] == 1)
	ra = 50;
			else if (nnc == 1)
	ra = ra * 2;
			if (nf == 16)
	ra = 1000;
			
			
			ns = 0, nnd = 0, nnc = 0, nf = 0, nh = 0;
			for (int i = 1; i <= nb[0]; i++)
			{
	if (nb[i] % 4 == 3)
	{
	 nh++;
	 nf++;
	 rb =  rb + h[nb[i] / 4];
	} 
	if (nb[i] == 46)
	{
	 rb = rb - 100;
	 ns = 1;
	 nf++;
	} 
	if (nb[i] == 41)
	{
	 rb = rb + 100;
	 nnd = 1;
	 nf++;
	}
	if (nb[i] == 36)
	{
	 nnc = 1;
	 nf++;
	} 
			}
			if (nh == 13 && nnd == 1 && ns == 1)
	rb = 500;
			if (nh == 13)
	rb = rb + 194 + 200;
			if (nnc == 1 && nb[0] == 1)
	rb = 50;
			else if (nnc == 1)
	rb = rb * 2;
			if (nf == 16)
	rb = 1000; 
	
			ns = 0, nnd = 0, nnc = 0, nf = 0, nh = 0;
			for (int i = 1; i <= nc[0]; i++)
			{
	if (nc[i] % 4 == 3)
	{
	 nh++;
	 nf++;
	 rc =  rc + h[nc[i] / 4];
	} 
	if (nc[i] == 46)
	{
	 rc = rc - 100;
	 ns = 1;
	 nf++;
	} 
	if (nc[i] == 41)
	{
	 rc = rc + 100;
	 nnd = 1;
	 nf++;
	}
	if (nc[i] == 36)
	{
	 nnc = 1;
	 nf++;
	} 
			}
			if (nh == 13 && nnd == 1 && ns == 1)
	rc = 500;
			if (nh == 13)
	rc = rc + 194 + 200;
			if (nnc == 1 && nc[0] == 1)
	rc = 50;
			else if (nnc == 1)
	rc = rc * 2;
			if (nf == 16)
	rc = 1000;
	
			ns = 0, nnd = 0, nnc = 0, nf = 0, nh = 0;
			for (int i = 1; i <= nd[0]; i++)
			{
	if (nd[i] % 4 == 3)
	{
	 nh++;
	 nf++;
	 rd =  rd + h[nd[i] / 4];
	} 
	if (nd[i] == 46)
	{
	 rd = rd - 100;
	 ns = 1;
	 nf++;
	} 
	if (nd[i] == 41)
	{
	 rd = rd + 100;
	 nnd = 1;
	 nf++;
	}
	if (nd[i] == 36)
	{
	 nnc = 1;
	 nf++;
	} 
			}
			if (nh == 13 && nnd == 1 && ns == 1)
	rd = 500;
			if (nh == 13)
	rd = rd + 194 + 200;
			if (nnc == 1 && nd[0] == 1)
	rd = 50;
			else if (nnc == 1)
	rd = rd * 2;
			if (nf == 16)
	rd = 1000;
		}
		
		if (ra > 0) printf ("+%d ", ra);
		else if (ra < 0) printf ("%d ", ra);
		else if (ra == 0) printf ("0 ");
		
		if (rb > 0) printf ("+%d ", rb);
		else if (rb < 0) printf ("%d ", rb);
		else if (rb == 0) printf ("0 ");
		
		if (rc > 0) printf ("+%d ", rc);
		else if (rc < 0) printf ("%d ", rc);
		else if (rc == 0) printf ("0 "); 

		if (rd > 0) printf ("+%d\n", rd);
		else if (rd < 0) printf ("%d\n", rd);
		else if (rd == 0) printf ("0\n"); 
	}
}