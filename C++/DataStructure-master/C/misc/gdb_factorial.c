#include <stdio.h>
#include <stdlib.h>

int factorial(int x)
{
    int fact = 0;
    for(int i = 1; i <= x; i++)
        fact = fact * i;
    return fact;
}

int main()
{
    int n;
    while(scanf("%d", &n)==1)
    {
        int ans = factorial(n);
        printf("ans = %d\n", ans);

    }

    return 0;

}
