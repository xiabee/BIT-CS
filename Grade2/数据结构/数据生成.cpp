#include <bits/stdc++.h>
#include <random>
using namespace std;
std::random_device rd;
std::mt19937 gen(rd());
std::poisson_distribution<> d(3.0); //lambda
int rand22()
{
	return rand()%22+1;
}
int rand_poss()
{
    return d(gen);
}
int main()
{
    srand((int)time(0));
    freopen("data.txt","w",stdout);
    for(int i=8;i<=21;i++)
    	for(int j=0;j<=59;j++)
    	{
			printf("%02d:%02d\n",i,j);
			int num_in,num_out;
			if(i==8||i==13)
            {
                num_in=20;
                num_out=2;
            }
            else if(i==11||i==18)
            {
                num_in=2;
                num_out=20;
            }
            else
            {
                num_in=rand_poss();
                num_out=rand_poss();
            }
            printf("Number of in: %d.\n",num_in);
            for(int k=1;k<=num_in;k++)
                printf("%d ",rand22());
            putchar('\n');
            printf("Number of out: %d.\n",num_out);
            for(int k=1;k<=num_out;k++)
                printf("%d ",rand22());
            putchar('\n');
            putchar('\n');
		}
    return 0;
}
