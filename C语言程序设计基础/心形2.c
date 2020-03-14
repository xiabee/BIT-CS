#include <stdio.h> 
#include <math.h> 
#include <stdlib.h>
#define I 20 
#define R 340
int main() 
{ 
int i,j,e; 
int a; 
for(i=1,a=I;i<I/2;i++,a--){ 
for(j=(int) ( I-sqrt(I*I-(a-i)*(a-i)) );j>0;j--) 
printf(" "); 
for(e=1;e<=2*sqrt(I*I-(a-i)*(a-i));e++) 
printf("\3"); 
for(j=(int) ( 2*( I-sqrt(I*I-(a-i)*(a-i)) ) );j>0;j--) 
printf(" "); 
for(e=1;e<=2*sqrt(I*I-(a-i)*(a-i));e++) 
printf("\3"); 
printf("\n"); 
} 
for(i=1;i<80;i++) 
{ 
if(i==25){ 
printf(" ZT,I LOVE YOU!Happy New Year!"); 
i+=30; 
} 
printf("\3"); 
} 
printf("\n"); 

for(i=1;i<=R/2;i++){ 
if(i%2||i%3)continue; 
for(j=(int) ( R-sqrt(R*R-i*i) );j>0;j--) 
printf(" "); 
for(e=1;e<=2*( sqrt(R*R-i*i) - (R-2*I) );e++) 
printf("\3"); 
printf("\n"); 
} 
long time; 
for(; ;) 
{ 
system("color a"); 
for(time=0;time<99999999;time++); 
system("color b"); 
for(time=0;time<99999999;time++); 
system("color c"); 
for(time=0;time<99999999;time++); 
system("color d"); 
for(time=0;time<99999999;time++); 
system("color e"); 
for(time=0;time<99999999;time++); 
system("color f"); 
for(time=0;time<99999999;time++); 
system("color 0"); 
for(time=0;time<99999999;time++); 
system("color 1"); 
for(time=0;time<99999999;time++); 
system("color 2"); 
for(time=0;time<99999999;time++); 
system("color 3"); 
for(time=0;time<99999999;time++); 
system("color 4"); 
for(time=0;time<99999999;time++); 
system("color 5"); 
for(time=0;time<99999999;time++); 
system("color 6"); 
for(time=0;time<99999999;time++); 
system("color 7"); 
for(time=0;time<99999999;time++); 
system("color 8"); 
for(time=0;time<99999999;time++); 
system("color 9"); 
for(time=0;time<99999999;time++); 
system("color ab"); 
for(time=0;time<99999999;time++); 
system("color ac"); 
for(time=0;time<99999999;time++); 
system("color ad"); 
for(time=0;time<99999999;time++); 
system("color ae"); 
for(time=0;time<99999999;time++); 
system("color af"); 
for(time=0;time<99999999;time++); 
} 
return 0; 
}
