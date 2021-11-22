#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{ 
	FILE *fp;
  	char filename[20],str[20];
  	int line,i=0,flag=0; 
  	scanf("%s\n%d",filename,&line);
  	if((fp=fopen(filename,"r"))==NULL)
	{
     	printf("File Name Error.\n");
      	exit(0);
  	};
	while(fgets(str,20,fp)!=NULL)
  	{
      	if(++i==line)
		{
          	printf("%s",str);
          	flag=1;
          	break;
      	}
  	}
  	if(flag==0) 
	  	printf("Line No Error.\n"); 
  	fclose(fp);
  	//system("PAUSE");	
 	return 0;
}
