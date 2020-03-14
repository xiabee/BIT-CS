/* PRESET CODE BEGIN - NEVER TOUCH CODE BELOW */  
#include <stdio.h>  
int sumn(int n,int *flag);  
int main()  
{   
    int n,nf=0;  
    scanf("%d",&n);  
    printf("%d\n",sumn(n,&nf));  
    if(nf!=n)  
        printf("Error:%d\n",nf);  
    return 0;  
}  
/* PRESET CODE END - NEVER TOUCH CODE ABOVE */  
int sumn(int n,int *flag)
{
	(*flag)++;
	if(n==1)
		return 1*2;
	else
		return sumn(n-1,flag)+n*(n+1);
}
