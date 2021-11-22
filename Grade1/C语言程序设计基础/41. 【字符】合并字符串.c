#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
	static char str1[20],str2[20],str3[20];
	int i=0,j=0,k=0;
	scanf("%s%s",str1,str2);
	while(str1[i]!='\0'&&str2[j]!='\0'){
		if(str1[i]<str2[j]){
		    str3[k]=str1[i];
		    k++;i++;
        }
		else if(str1[i]==str2[j]){
		         str3[k]=str1[i];
		         k++;i++;
		         str3[k]=str2[j];
		         k++;j++;
		}
		     else{
			     str3[k]=str2[j];
		         k++;j++;
		     }
    }
	if(str1[i]=='\0')
		while(str2[j]!='\0'){
			str3[k]=str2[j];
			k++;j++;
		}
	else
	    while(str1[i]!='\0'){
			str3[k]=str1[i];
			k++;i++;
		}
	puts(str3);
	return 0;
}
