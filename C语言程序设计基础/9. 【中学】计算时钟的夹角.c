#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main(int argc, char *argv[]) {
	int a,b;
	float angle;
	scanf("%d %d",&a,&b);
	angle=abs(a*60-b*11);
	angle/=2;
	if(angle>180.0)
	  angle=360.0-angle;
	if(b<10)
	  printf("At %d:0%d the angle is %.1f degrees.\n",a,b,angle);
	else
	  printf("At %d:%d the angle is %.1f degrees.\n",a,b,angle);
	return 0;
}
