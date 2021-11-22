#include<stdio.h>
struct Person
{
	int id;
	int score;
}k[10000],t,temp;
int m,n;
void adjust(int i,int n0)
{
	int j=i*2;
	temp=k[i];
	while(j<=n0)
	{
		if((j<n0&&k[j].score>k[j+1].score)||(j<n0&&k[j].score==k[j+1].score&&k[j].id<k[j+1].id))
			j++;
		if((temp.score<k[j].score)||(temp.score==k[j].score&&temp.id>k[j].id))
			break;
		k[j/2]=k[j];
        j*=2;
    }
    k[j/2]=temp;
}
void heap(void)
{              //堆排序函数 
    int i;
    for(i=n/2;i>0;i--)
	{       //小顶堆的初始化 
        adjust(i,n);
    }
    for(i=n-1;i>0;i--)
	{        //从队尾依次向堆顶调整小顶堆 
        t=k[i+1];              //每次调整完毕，交换堆顶和堆尾的值 
        k[i+1]=k[1];           //这样就保证了堆尾的成绩是当前最小的 
        k[1]=t;
        adjust(1,i);
    }
}
int main(void)
{
    int i,line,num=0;
    scanf("%d %d",&n,&m);
    for(i=1;i<=n;i++)
	{
        scanf("%d %d",&k[i].id,&k[i].score);
    }
    heap();
    m+=m/2;            
    line=k[m].score;        //分数线的计算，直接用除法可以直接实现向下取整 
    for(i=1;i<=n;i++)
	{
        if(k[i].score>=line)
		{  //这里或许有些麻烦，但是录取人数要先输出，所以就先在这里统计一下 
            num++;
        }
        else{
            break;
        }
    }
    printf("%d %d\n",line,num);
    for(i=1;k[i].score>=line;i++)
	{            //输出截止条件是成绩低于分数线 
        printf("%d %d\n",k[i].id,k[i].score);//因为排序已经保证了成绩递减，相同成绩编号递增。 
    }
    return 0;
}
