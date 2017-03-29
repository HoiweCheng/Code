#include<stdio.h>

struct x
{
/*    int i;
    char c;
    long d;
    void *p;*/
    int a[0];//size=0
};

int main()
{
    printf("%u\n", sizeof(struct x));
    return 0;
}
