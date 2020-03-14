#include <stdio.h>
#include <stdlib.h>
int main()
{    
	char S[100],T[20];    
	char ch1,ch2;   
  	ch1=getchar();    
	int i=0;   
   	while(ch1!='\n')   
    {        
		S[i]=ch1;      
	  	i++;       
	   	ch1=getchar(); 
	}     
	ch2=getchar();    
	int j=0;   
	while(ch2!='\n')    
	{        
		T[j]=ch2;       
		j++;       
		ch2=getchar(); 
	}    
	int m,n;//m为S的下标，n为T的下标   
	m=0;    
	n=0;    
	int num=0;//num用于记录选定单词出现的次数   
	while(m<=i&&n<=j)    
	{        
		if(S[m]==T[n])        
		{            
			m++;           
			n++;       
		}        
		else       
		{        
			m=m-n+1;      
			n=0;      
		}       
		if(n==j)  
		{      
			num++;   
		}  
	}    
	if(m==i+1)    
	{         
		if(num==0)
			printf("No\n");  
		else
			printf("%d\n",num);   
	}
	
	return 0;
}


