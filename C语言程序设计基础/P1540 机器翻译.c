#include<stdio.h>
int main()
{int M,N,m[101],i,j,k,n,count=0;
    scanf("%d%d",&M,&N);
    for(i=0;i<M;i++)  
		m[i]=-1;//注意单词是非负整数可能为零
    for(i=0;i<N;i++)
    {
		scanf("%d",&n);
        for(j=0;j<M;j++)  
			if(n==m[j])  
				goto abc;
        m[count%M]=n;
		count++;//如果单词不在内存中
        abc:;
    }
    printf("%d",count);
    return 0;
}
