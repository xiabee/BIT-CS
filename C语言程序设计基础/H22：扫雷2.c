#include<stdio.h>
int main()
{
	int dir[8][2] = {1,0,-1,0,0,1,0,-1,1,1,1,-1,-1,1,-1,-1};
	int n,m,cas = 0;
	char map[105][105];
	int ans[105][105];
	while(scanf("%d%d",&n,&m)&&n+m)
	{
		if(cas)printf("\n");
		int i,j,k; 
		for ( i = 0; i < n; i++)	
		{
			scanf("%s",map[i]);	//cin>>map[i];
			for (j = 0; j < m; j++)
			{
				ans[i][j] = 0;
			}
		}
		int x,y;
		for (i = 0; i < n; i++)		
			for(j = 0; j < m; j++)
			{
				if(map[i][j] == '*')
				{
					for (k = 0; k < 8; k++)
					{
						x = i+dir[k][0];y = j+dir[k][1];
						if(x>=0&&x<n&&y>=0&&y<m&&map[x][y]=='.')
							ans[x][y]++;
					}
				}
			}
		printf("Field #%d:\n",++cas);
		for (i = 0; i < n; i++)
		{		
			for (j = 0; j < m; j++)
			{
				if(map[i][j]=='*')
					printf("*");
				else
					printf("%d",ans[i][j]);
			}
			printf("\n");
		}
	}
	return 0;
}

