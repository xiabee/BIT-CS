#include<stdio.h>
#include<string.h>
int main()
{
	int m,n,i,j,k,num=0;
	//int dir[8][2] = {1,0,-1,0,0,1,0,-1,1,1,1,-1,-1,1,-1,-1};
	while(1)
	{
		scanf("%d%d",&m,&n);
		if(m==0&n==0)
			break;//结束循环 
		else
		{
			char map[105][105]={0};//定义地图矩阵； 
			int ans[105][105]={0};
			for(i=0;i<m;i++)
			{
				scanf("%s",&map[i]);//输入地图矩阵； 
				for(j=0;j<n;j++)
					ans[i][j]=0;//初始化答案矩阵； 
			}
			for(i=0;i<m;i++)
			{
				for(j=0;j<n;j++)
				{
					if(map[i][j]=='*')//扫描雷区； 
					{
						if(i==0&&j==0)//第一行，第一列 一个雷；
						{
							ans[1][1]++;
							ans[1][0]++;
							ans[0][1]++; 
						}
						if(i==0&&j==n-1)//第一行,最后一列 一个雷；
						{
							ans[1][n-1]++;
							ans[1][n-2]++;
							ans[0][n-2]++; 
						}
						if(i==m-1&&j==0)//最后一行，第一列 一个雷； 
						{
							ans[m-1][1]++;
							ans[m-2][0]++;
							ans[m-2][1]++; 
						}
						if(i==m-1&&j==n-1)//最后一行，最后一列 一个雷； 
						{
							ans[m-1][n-2]++;
							ans[m-2][n-1]++;
							ans[m-2][n-2]++; 
						}
						if(i==0&&j!=0&&j!=n-1)//第一行有雷；并且不是第一列和最后一列； 
						{
							
							ans[0][j-1]++;
							ans[0][j+1]++; 
							ans[1][j-1]++;
							ans[1][j]++;
							ans[1][j+1]++;
						}
						if(i==m-1&&j!=0&&j!=n-1)//最后一行有雷；并且不是第一列和最后一列； 
						{
							ans[m-1][j-1]++;
							ans[m-1][j+1]++; 
							ans[m-2][j-1]++;
							ans[m-2][j]++;
							ans[m-2][j+1]++;
						} 
					 	if(j==n-1&&i!=0&&i!=m-1)//最后一列有雷；并且不是第一行和最后一行； 
						{
							ans[i-1][n-1]++;
							ans[i+1][n-1]++; 
							ans[i-1][n-2]++;
							ans[i][n-2]++;
							ans[i+1][n-2]++;
						}
						else//中间有雷；
						{
							ans[i-1][j-1]++;
							ans[i-1][j]++;
							ans[i-1][j+1]++;
							ans[i][j-1]++;
							ans[i][j+1]++;
							ans[i+1][j-1]++;
							ans[i+1][j]++;
							ans[i+1][j+1]++;	
						} 	
					}
				}
			} //结束扫描；
			printf("Field #%d:\n",++num); 
			for(i=0;i<m;i++)
			{		
				for(j=0;j<n;j++)
				{
					if(map[i][j]=='*')
						printf("*");
					else
						printf("%d",ans[i][j]);
				}
				printf("\n");
			}
		}
	} 
	return 0;
}
