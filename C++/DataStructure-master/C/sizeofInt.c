#include<stdio.h>
#include<stdlib.h>

int main()
{
    int *a, *s;
    int v = 10;
    a = &v;
    s = a;
    a++;
    int sz = (int)a - (int)s;
    printf("%d\n", sz);
    //just check the address diff of two consecutive same type variables
    int diff =(int)&a[1] -(int)&a[0];
    printf("%d\n", diff);
    printf("%u\n", sizeof(void*));
    return 0;
}
