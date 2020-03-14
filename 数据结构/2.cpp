#include<stdio.h>
long long a,b;
long long x,y;
int m,n;
int temp;
int sum=0;
int main(){
	scanf("%d%d",&n,&m);
	printf("%d\n",n);
	fflush(stdout);
	while(1){
		scanf("%d",&temp);
		if(temp==0||temp==-1)
			return 0;
		if(n==1){
			if(temp==6){
				printf("6\n");
				fflush(stdout);
			}	
			else{
				printf("%d\n",6-temp);
				fflush(stdout);
				sum-=(6-temp);
			}
		}
		if(n==5){
			int flag=0;
			int time=1;
			if(time==1){
				time++;
				if(temp==5){
					flag=1;
				}
				else(temp==6){
					printf("6\n");
					fflush(stdout);
					sum-=6;
				}
				else{
					printf("%d\n",5-temp);
					fflush(stdout);
					sum-=5;
				}
			}
			else{
				printf("%d\n",7-temp);
				fflush(stdout);
				sum-=7;
			}
		}
	}
	
return 0;
}
