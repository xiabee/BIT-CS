#include <stdio.h>
int main()
{
    int a[10];
    for(int i = 0;i < 10;i++)
        scanf("%d", &a[i]);

    for(int i = 0;i < 10;i++)
    {
        int min = i;
        for(int j = i;j < 10;j++)
        {
            if(a[j] < a[min])
                min = j;
        }
    
        int temp = a[i];
        a[i] = a[min];
        a[min] = temp;
    }

    for(int i = 0;i < 10;i++)
        printf("%d ", a[i]);

    return 0;
}