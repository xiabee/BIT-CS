#include<stdio.h>
#include<string.h> 
void Insert(char *src,int pos,char c);
int main(int argc,char *argv)
{
	int n;
	scanf("%d",&n);//确定输入身份证号个数 ； 
	while(n--)
	{
		char arr[19];//要验证的身份证号码； 
		int brr[17]={7,9,10,5,8,4,2,1,6,3,7,9,10,5,8,4,2};//身份证前17位的系数； 
		char crr[11]={1,0,-1,9,8,7,6,5,4,3,2};  //身份证第18位校验码； 
		int sum=0,loop=0;
		scanf("%s",arr);
		if(strlen(arr)==18)//先对18位身份证号操作 
		{
			for(loop=0;loop<17;loop++)
			{
				sum=sum+(arr[loop]-'0')*brr[loop];//乘以对应系数； 
			}
			if(sum%11==2)
			{
				if(arr[17]=='X')
					printf("Valid\n");
				else
					printf("Invalid\n");
			}
			else
			{
				if((arr[17]-'0')==crr[sum%11])
					printf("Valid\n");
				else
					printf("Invalid\n");
			}
		}
		else if(strlen(arr)==15)//对15位身份证号操作
		{
			if((arr[12]=='9'&&arr[13]=='9')&&(arr[14]=='6'||arr[14]=='7'||arr[14]=='8'||arr[14]=='9'))
			{
				Insert(arr,6,'1');
				Insert(arr,7,'8');
				for(loop=0;loop<17;loop++)
				{
					sum=sum+(arr[loop]-'0')*brr[loop];//乘以对应系数； 
				}
				sum%=11;//求出余数 
				if(sum==2)
					Insert(arr,18,'X');
				else
					Insert(arr,18,crr[sum]+'0');
				puts(arr);
			}
			else
			{
				Insert(arr,6,'1');
				Insert(arr,7,'9');
				for(loop=0;loop<17;loop++)
				{
					sum=sum+(arr[loop]-'0')*brr[loop];//乘以对应系数； 
				}
				sum%=11;//求出余数 
				if(sum==2)
					Insert(arr,18,'X');
				else
					Insert(arr,18,crr[sum]+'0');
				puts(arr);
			}
		}
		else
			printf("Invalid\n");
	}
	return 0;
}
void Insert(char *src,int pos,char c)//原数组，插入位置，插入字符串； 
{
    int i,L;
    L=(int)strlen(src);
    if(L<pos)//插入位置之前的数组不变； 
    {
        src[L]=c;
        src[L+1]='\0';
    }
    else//插入之后 
    {
        for (i=L;i>pos;i--)
        {
            src[i]=src[i-1];
        }
        src[pos]=c;
        src[L+1]='\0';
    }
}

