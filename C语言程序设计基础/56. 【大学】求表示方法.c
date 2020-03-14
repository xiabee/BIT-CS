#include<stdio.h>
int IntegetrDivision( int m, int n);
int main()
{
    int m, n;
    scanf("%d %d", &m, &n);
    getchar();
    printf("%d\n", IntegetrDivision(m, n));
    return 0;
}
int IntegetrDivision(int m, int n)
{
    if(n <= 1 || m <= 1)
        return 1;
    else if(m <= n)
    {
        return IntegetrDivision(m, m-1) + 1;
    }
    else
    {
        return IntegetrDivision(m - n, n) + IntegetrDivision(m, n-1);
    }
}

