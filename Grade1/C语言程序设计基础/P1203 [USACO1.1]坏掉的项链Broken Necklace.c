#include<stdio.h>
#include<string.h>
int i,j,n,m,left[400],right[400];
char A[800],B[400],now;
int main(void)
{
    scanf("%d",&m);
	while(getchar()!='\n');
	gets(&A[1]);
    if(m==0)
	{	printf("0");
		return 0;
	}
    strcpy(B,&A[1]);
	B[n-1]='\0';
    strcat(&A[1],B);n=2*m-1;
    for(i=1;i<=n;i++)
		left[i]=right[i]=1;
    for(i=1;i<=n&&A[i]=='w';i++)
		left[i]=left[i-1]+1; 
		now=A[i];
    while(i<=n)
    {
        for(;i<=n&&(A[i]==now||A[i]=='w');i++) 
			left[i]=left[i-1]+1;
        now=A[i];left[i]=1;
        for(j=i-1;j>=1&&A[j]=='w';j--) 
			left[i]++;
        i++;
    }
    for(i=n;i>=1&&A[i]=='w';i--)
		right[i]=right[i+1]+1; 
	now=A[i];
    while(i>=1)
    {
        for(;i>=1&&(A[i]==now||A[i]=='w');i--) 
			right[i]=right[i+1]+1;
        now=A[i];right[i]=1;
        for(j=i+1;j<=n&&A[j]=='w';j++) 
			right[i]++;
        i--;
    }
    int ans=0;
    for(i=1;i<=n;i++)
        if(ans<left[i]+right[i+1]) 
            ans=left[i]+right[i+1];
    printf("%d",ans>m?m:ans);
    return 0;    
}
