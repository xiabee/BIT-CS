#include <stdio.h>
#include <ctime>
#include <cstdlib>
using namespace std; 
void data1();
void data2();
void data3(); //随机lld 
void data4(); 
const char hap[91][11]={"fattyhappy","afttyhappy","taftyhappy","tatfyhappy",
"yattfhappy","hattyfappy","aattyhfppy","pattyhafpy","pattyhapfy","yattyhappf",
"afttyhappy","ftatyhappy","fttayhappy","fyttahappy","fhttyaappy","fattyhappy",
"fpttyhaapy","fpttyhapay","fyttyhappa","taftyhappy","ftatyhappy","fattyhappy",
"faytthappy","fahtytappy","faatyhtppy","faptyhatpy","faptyhapty","faytyhappt",
"tatfyhappy","fttayhappy","fattyhappy","fatythappy","fathytappy","fatayhtppy",
"fatpyhatpy","fatpyhapty","fatyyhappt","yattfhappy","fyttahappy","faytthappy",
"fatythappy","fatthyappy","fattahyppy","fattphaypy","fattphapyy","fattyhappy",
"hattyfappy","fhttyaappy","fahtytappy","fathytappy","fatthyappy","fattyahppy",
"fattypahpy","fattypaphy","fattyyapph","aattyhfppy","fattyhappy","faatyhtppy",
"fatayhtppy","fattahyppy","fattyahppy","fattyhpapy","fattyhppay","fattyhyppa",
"pattyhafpy","fpttyhaapy","faptyhatpy","fatpyhatpy","fattphaypy","fattypahpy",
"fattyhpapy","fattyhappy","fattyhaypp","pattyhapfy","fpttyhapay","faptyhapty",
"fatpyhapty","fattphapyy","fattypaphy","fattyhppay","fattyhappy","fattyhapyp",
"yattyhappf","fyttyhappa","faytyhappt","fatyyhappt","fattyhappy","fattyyapph",
"fattyhyppa","fattyhaypp","fattyhapyp"};
/*在伪fattyhappy内外互换*/ 
const char hap2[260][11]={"aattyhappy","battyhappy","cattyhappy","dattyhappy",
"eattyhappy","fattyhappy","gattyhappy","hattyhappy","iattyhappy","jattyhappy",
"kattyhappy","lattyhappy","mattyhappy","nattyhappy","oattyhappy","pattyhappy",
"qattyhappy","rattyhappy","sattyhappy","tattyhappy","uattyhappy","vattyhappy",
"wattyhappy","xattyhappy","yattyhappy","zattyhappy","fattyhappy","fbttyhappy",
"fcttyhappy","fdttyhappy","fettyhappy","ffttyhappy","fgttyhappy","fhttyhappy",
"fittyhappy","fjttyhappy","fkttyhappy","flttyhappy","fmttyhappy","fnttyhappy",
"fottyhappy","fpttyhappy","fqttyhappy","frttyhappy","fsttyhappy","ftttyhappy",
"futtyhappy","fvttyhappy","fwttyhappy","fxttyhappy","fyttyhappy","fzttyhappy",
"faatyhappy","fabtyhappy","factyhappy","fadtyhappy","faetyhappy","faftyhappy",
"fagtyhappy","fahtyhappy","faityhappy","fajtyhappy","faktyhappy","faltyhappy",
"famtyhappy","fantyhappy","faotyhappy","faptyhappy","faqtyhappy","fartyhappy",
"fastyhappy","fattyhappy","fautyhappy","favtyhappy","fawtyhappy","faxtyhappy",
"faytyhappy","faztyhappy","fatayhappy","fatbyhappy","fatcyhappy","fatdyhappy",
"fateyhappy","fatfyhappy","fatgyhappy","fathyhappy","fatiyhappy","fatjyhappy",
"fatkyhappy","fatlyhappy","fatmyhappy","fatnyhappy","fatoyhappy","fatpyhappy",
"fatqyhappy","fatryhappy","fatsyhappy","fattyhappy","fatuyhappy","fatvyhappy",
"fatwyhappy","fatxyhappy","fatyyhappy","fatzyhappy","fattahappy","fattbhappy",
"fattchappy","fattdhappy","fattehappy","fattfhappy","fattghappy","fatthhappy",
"fattihappy","fattjhappy","fattkhappy","fattlhappy","fattmhappy","fattnhappy",
"fattohappy","fattphappy","fattqhappy","fattrhappy","fattshappy","fattthappy",
"fattuhappy","fattvhappy","fattwhappy","fattxhappy","fattyhappy","fattzhappy",
"fattyaappy","fattybappy","fattycappy","fattydappy","fattyeappy","fattyfappy",
"fattygappy","fattyhappy","fattyiappy","fattyjappy","fattykappy","fattylappy",
"fattymappy","fattynappy","fattyoappy","fattypappy","fattyqappy","fattyrappy",
"fattysappy","fattytappy","fattyuappy","fattyvappy","fattywappy","fattyxappy",
"fattyyappy","fattyzappy","fattyhappy","fattyhbppy","fattyhcppy","fattyhdppy",
"fattyheppy","fattyhfppy","fattyhgppy","fattyhhppy","fattyhippy","fattyhjppy",
"fattyhkppy","fattyhlppy","fattyhmppy","fattyhnppy","fattyhoppy","fattyhpppy",
"fattyhqppy","fattyhrppy","fattyhsppy","fattyhtppy","fattyhuppy","fattyhvppy",
"fattyhwppy","fattyhxppy","fattyhyppy","fattyhzppy","fattyhaapy","fattyhabpy",
"fattyhacpy","fattyhadpy","fattyhaepy","fattyhafpy","fattyhagpy","fattyhahpy",
"fattyhaipy","fattyhajpy","fattyhakpy","fattyhalpy","fattyhampy","fattyhanpy",
"fattyhaopy","fattyhappy","fattyhaqpy","fattyharpy","fattyhaspy","fattyhatpy",
"fattyhaupy","fattyhavpy","fattyhawpy","fattyhaxpy","fattyhaypy","fattyhazpy",
"fattyhapay","fattyhapby","fattyhapcy","fattyhapdy","fattyhapey","fattyhapfy",
"fattyhapgy","fattyhaphy","fattyhapiy","fattyhapjy","fattyhapky","fattyhaply",
"fattyhapmy","fattyhapny","fattyhapoy","fattyhappy","fattyhapqy","fattyhapry",
"fattyhapsy","fattyhapty","fattyhapuy","fattyhapvy","fattyhapwy","fattyhapxy",
"fattyhapyy","fattyhapzy","fattyhappa","fattyhappb","fattyhappc","fattyhappd",
"fattyhappe","fattyhappf","fattyhappg","fattyhapph","fattyhappi","fattyhappj",
"fattyhappk","fattyhappl","fattyhappm","fattyhappn","fattyhappo","fattyhappp",
"fattyhappq","fattyhappr","fattyhapps","fattyhappt","fattyhappu","fattyhappv",
"fattyhappw","fattyhappx","fattyhappy","fattyhappz"};
int main(){
	srand(time(0));
	printf("1\n");
	int a = rand() % 10000;
	int b = rand();
	for (int i = 0; i < a; ++i)
	{
		char c = rand() % 127;
		while(c < 'a' || c > 'z')
		{
			c = rand() % 127;
		}
		if (i == b)
		{
			printf("%s", hap2[rand()%250]);
		}
		else printf("%c", c);
	}
   // data4();
   // data4();
   // data4();
   // data3();
}
void data1()
{
	srand(time(0));
	int t = 10000;int c=rand();
    srand(c);c *= rand();c%=1000000;
    int a=rand();
    srand(a);a*= rand();a%=1000000;
    printf("%d\n",t);
    if(c%19%2) c = -c;
    if(a>c)
    {
    	int tp = c;
    	c = a;
    	a = tp;
	}
    printf("%d %d\n",a,c);
     while(t--){
	c=rand();
    srand(c);c *= rand();c%=1000000;if(c%19%2) c = -c;
     a=rand();
    srand(a);a*= rand();a%=1000000;if(a%19%2) a = -a;
      printf("%d %d\n",a,c);
 }
}
void data2()
{
	srand(time(0));
	int t = rand()%50;
	printf("%d\n",t);
	while(t--)
	{
		int n=rand();srand(n);
		n=n%15 + 5;
		while(n--){
			int c=rand();srand(c*rand());
			printf("%d",c%10);
		}
		printf("\n");
	}
	
}
void data3()
{
	srand(time(0));
	long long t = rand();
	srand(t);
	t *= rand();
	srand(t);
	t *= rand();
	printf("%lld\n",t);
}
void data4()
{
	int t;
	t = rand();
	srand(t);
	t *= rand();
	printf("%d\n",t);
	srand(t);
}
