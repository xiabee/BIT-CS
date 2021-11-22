#include<stdio.h>
typedef struct 
{
	int start;
	int end;
}data;
int cmp(data* a,data* b)
{
    if(a->start != b->start )
		return a->start - b->start;//先比较开始时间； 
    else 
		return a->end - b->end;//同时开始时，比较结束时间； 
}
int main(void)
{
	int n,i,ans=0;
	data line[100001];
	scanf("%ld",&n);
	for(i=0;i<n;i++)
		scanf("%d%d",&line[i].start,&line[i].end);
	qsort(&line[1],n,sizeof(line[0]),cmp);
	
	int now=-9999;
    for(i=1;i<=n;i++)
	{
        if(line[i].start>=now)//未到比赛开始时间，可以参赛； 
		{
			now=line[i].end;
			ans++;
		}
        else if(line[i].start<now&&line[i].end<=now)//开始比赛，结束时已到比赛结束时间； 
			now=line[i].end;
    }    
    printf("%d",ans);
    return 0;    
}

