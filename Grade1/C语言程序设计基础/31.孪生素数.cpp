#include<stdio.h>
int main()
{
	int a,b,i,j,s,flag;
	scanf("%d %d",&a,&b);
	for(i=a;i<=b-2;i++){
		for(j=2;j<i-1;j++){
			flag=0;
			if(i%j==0) {
			    flag=1;
			    break;
			}
	    }
			if(flag==0){
				for(s=2;s<i+2;s++){
					flag=0;
					if((i+2)%s==0){
					  flag=1;
					  break;
					}
				}
		    }
		    if(flag==0) printf("%d,%d\n",i,i+2);
	}
	return 0;
}
