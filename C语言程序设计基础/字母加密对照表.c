struct table//定义密码表结构； 
{	
	char input, output;  
};
struct table translate[ ]= 
{  'a','d',  'b','w',  'c','k',
    'd',';',  'e','i', 'i','a', 'k','b',  ';','c',  'w','e'};//定义密码表； 
int main()
{	
	char ch;
	int str_long, i;
	str_long = sizeof(translate)/sizeof(struct table);	//计算元素个数 
	while ( (ch=getchar( )) != '\n')
	{ 
		for( i=0; translate[i].input!=ch && i<str_long; i++ );
	  	if (i<str_long) 
		  	putchar (translate[i].output);//加密 					
	  	else            
	  		putchar (ch);// 原样输出
	}
	return 0;
}
