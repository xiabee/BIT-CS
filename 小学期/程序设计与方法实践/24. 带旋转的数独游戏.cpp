#include<stdio.h>
#include<string.h>
#include<stdlib.h>//三件套准备好
int vvv, i, j, k, l, m, n, i1, i2, i3, i4;//vvv记录scanf返回值
char mmp_nmd[18][18];
char mmp_qnmd1[18][18];
int gg_big[4][4];//大的16个正方形区域
char gg_small[4][4];//小的备用旋转用的4*4方块
int gg_c[16];
char gg_x[16];
int flag = 0;
int check_line(int gg_u);//检查特定行是否匹配
int check_rows();//检查每一列是否匹配
int dfs(int gg_u, int v);//模板大法好
int gg_rot(int n, int gg_x, int gg_y);//旋转次数
int reserve(int gg_x, int gg_y);//恢复函数，回溯过程

int main()
{
	int T;
	vvv = scanf("%d", &T);//vvv记录返回值，T记录样例个数
	while (T--) //多个样例
	{
		flag = 0;
		for (i = 0; i < 16; i++) 
		{
			vvv = scanf("%s", mmp_nmd[i]);//去掉地址符.......vs居然不报错，GG
			for (j = 0; j < 16; j++) 
				mmp_qnmd1[i][j] = mmp_nmd[i][j];
		}
		for (i = 1; i < 5; i++) //此时i代表大行的行数(从1开始)
		{
			flag = 0;
			dfs(i, 1);
		}
		for (i1 = 0; i1 < 2; i1++)//一顿暴算
		{

			for (i2 = 0; i2 < 2; i2++)//两顿暴算
			{

				for (i3 = 0; i3 < 2; i3++)//三顿暴算
				{

					for (i4 = 0; i4 < 2; i4++)//四顿暴算
					{
						gg_x[0] = mmp_nmd[0][0 + i1 * 3];//暴力枚举法
						gg_x[1] = mmp_nmd[1][0 + i1 * 3];//暴力枚举法
						gg_x[2] = mmp_nmd[2][0 + i1 * 3];//暴力枚举法
						gg_x[3] = mmp_nmd[3][0 + i1 * 3];//暴力枚举法
						gg_x[4] = mmp_nmd[4][0 + i2 * 3];//暴力枚举法
						gg_x[5] = mmp_nmd[5][0 + i2 * 3];//暴力枚举法
						gg_x[6] = mmp_nmd[6][0 + i2 * 3];//暴力枚举法
						gg_x[7] = mmp_nmd[7][0 + i2 * 3];//暴力枚举法
						gg_x[8] = mmp_nmd[8][0 + i3 * 3];//暴力枚举法
						gg_x[9] = mmp_nmd[9][0 + i3 * 3];//暴力枚举法
						gg_x[10] = mmp_nmd[10][0 + i3 * 3];//暴力枚举法
						gg_x[11] = mmp_nmd[11][0 + i3 * 3];//暴力枚举法
						gg_x[12] = mmp_nmd[12][0 + i4 * 3];//暴力枚举法
						gg_x[13] = mmp_nmd[13][0 + i4 * 3];//暴力枚举法
						gg_x[14] = mmp_nmd[14][0 + i4 * 3];//暴力枚举法
						gg_x[15] = mmp_nmd[15][0 + i4 * 3];//暴力枚举法
						if (check_rows() == 1)//开始检查
							goto gg_pg;
						for (m = 0; m < 4; m++)//继续暴算
							gg_big[3][m] = (gg_big[3][m] + 2) % 4;
					}
					for (m = 0; m < 4; m++) //继续暴算
						gg_big[2][m] = (gg_big[2][m] + 2) % 4;
				}
				for (m = 0; m < 4; m++) //继续暴算
					gg_big[1][m] = (gg_big[1][m] + 2) % 4;
			}
			for (m = 0; m < 4; m++) //继续暴算
				gg_big[0][m] = (gg_big[0][m] + 2) % 4;
		}

	gg_pg:
		int total = 0;
		int total1 = 0;
		for (i = 0; i < 4; i++)//继续暴算输出
			for (j = 0; j < 4; j++) 
			{
				total = gg_big[i][j] + total;
				total1 = (gg_big[i][j] + 2) % 4 + total1;
			}

		if (total < total1) //继续暴算输出
		{
			printf("%d\n", total);
			for (int i = 0; i < 4; i++) 
				for (int j = 0; j < 4; j++) 
					for (int k = 0; k < gg_big[i][j]; k++) 
						printf("%d %d\n", i + 1, j + 1);//行数列数加一
		}

		else
		{
			printf("%d\n", total1);
			for (i = 0; i < 4; i++) 
				for (j = 0; j < 4; j++) 
					for (k = 0; k < (gg_big[i][j] + 2) % 4; k++) 
						printf("%d %d\n", i + 1, j + 1);//行数列数加一
		}
	}
	return 0;
}

int check_line(int gg_u) //check里面的gg_u代表小行行数,满足返回1，不满足返回0
{
	int i;//此i非彼i
	for (i = 0; i < 16; i++)
	{
		switch (mmp_nmd[gg_u][i])
		{
			case '0': gg_c[0]++; 
				break;//暴力枚举
			case '1': gg_c[1]++; 
				break;//暴力枚举
			case '2': gg_c[2]++; 
				break;//暴力枚举
			case '3': gg_c[3]++; 
				break;//暴力枚举
			case '4': gg_c[4]++; 
				break;//暴力枚举
			case '5': gg_c[5]++; 
				break;//暴力枚举
			case '6': gg_c[6]++; 
				break;//暴力枚举
			case '7': gg_c[7]++; 
				break;//暴力枚举
			case '8': gg_c[8]++; 
				break;//暴力枚举
			case '9': gg_c[9]++; 
				break;//暴力枚举
			case 'A': gg_c[10]++; 
				break;//暴力枚举
			case 'B': gg_c[11]++; 
				break;//暴力枚举
			case 'C': gg_c[12]++; 
				break;//暴力枚举
			case 'D': gg_c[13]++; 
				break;//暴力枚举
			case 'E': gg_c[14]++; 
				break;//暴力枚举
			case 'F': gg_c[15]++; 
				break;//暴力枚举
		}
	}
	for (i = 0; i < 16; i++)
	{
		if (gg_c[i] == 0 || gg_c[i] > 1)
		{
			memset(gg_c, 0, sizeof(gg_c));
			return 0;
		}
	}
	memset(gg_c, 0, sizeof(gg_c));
	return 1;
}

int check_rows()
{
	int i;
	for (i = 0; i < 16; i++)
	{
		switch (gg_x[i])
		{
			case '0': gg_c[0]++; 
				break;//暴力枚举
			case '1': gg_c[1]++; 
				break;//暴力枚举
			case '2': gg_c[2]++; 
				break;//暴力枚举
			case '3': gg_c[3]++; 
				break;//暴力枚举
			case '4': gg_c[4]++; 
				break;//暴力枚举
			case '5': gg_c[5]++; 
				break;//暴力枚举
			case '6': gg_c[6]++; 
				break;//暴力枚举
			case '7': gg_c[7]++; 
				break;//暴力枚举
			case '8': gg_c[8]++; 
				break;//暴力枚举
			case '9': gg_c[9]++; 
				break;//暴力枚举
			case 'A': gg_c[10]++; 
				break;//暴力枚举
			case 'B': gg_c[11]++; 
				break;//暴力枚举
			case 'C': gg_c[12]++; 
				break;//暴力枚举
			case 'D': gg_c[13]++; 
				break;//暴力枚举
			case 'E': gg_c[14]++; 
				break;//暴力枚举//暴力枚举
			case 'F': gg_c[15]++; 
				break;//暴力枚举//暴力枚举
		}
	}
	for (i = 0; i < 16; i++)
		if (gg_c[i] == 0 || gg_c[i] > 1)
		{
			memset(gg_c, 0, sizeof(gg_c));//初始化初始化初始化
			return 0;
		}
	memset(gg_c, 0, sizeof(gg_c));//初始化初始化初始化
	return 1;
}

int gg_rot(int n, int gg_x, int gg_y)//n代表旋转几次（从0开始），gg_x代表大行行数（从1开始）gg_y代表第几个方块（从1开始）
{
	int i, j, k, jj, kk;
	for (i = 0; i < n; i++)
	{
		for (j = 3; j >= 0; j--)
			for (k = 0; k < 4; k++)
				gg_small[3 - j][k] = mmp_nmd[k + (gg_x - 1) * 4][j + (gg_y - 1) * 4];

		for (jj = 0; jj < 4; jj++) //把gg_small赋值给mmp_nmd
			for (kk = 0; kk < 4; kk++)
				mmp_nmd[jj + (gg_x - 1) * 4][kk + (gg_y - 1) * 4] = gg_small[jj][kk];
	}
	gg_big[gg_x - 1][gg_y - 1] = n;
	return 0;
}

int reserve(int gg_x, int gg_y)//恢复回溯
{
	int i, j;
	for (i = 0; i < 4; i++)
		for (j = 0; j < 4; j++)
			mmp_nmd[(gg_x - 1) * 4 + i][(gg_y - 1) * 4 + j] = mmp_qnmd1[(gg_x - 1) * 4 + i][(gg_y - 1) * 4 + j];
	return 0;
}


int dfs(int gg_u, int v)//gg_u代表dfs的大行行数(1开始), v代表旋转的是第几个方块
{
	int i;
	if (flag == 1)//递归终止条件
		return 0;
	if (v == 4)
	{
		for (i = 0; i < 4; i++)
		{
			gg_rot(i, gg_u, v);
			if (check_line((gg_u - 1) * 4) == 1)
			{
				flag = 1;
				return 0;
			}
			else
			{
				reserve(gg_u, v);
				gg_big[gg_u - 1][v - 1] = 0;
			}
		}
	}
	else
	{
		for (i = 0; i < 4; i++)
		{
			gg_rot(i, gg_u, v);
			dfs(gg_u, v + 1);
			if (check_line((gg_u - 1) * 4) == 1)
			{
				flag = 1;
				return 0;
			}
			else
				reserve(gg_u, v);
		}
	}
	return 0;
}