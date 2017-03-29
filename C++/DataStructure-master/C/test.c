#include <stdio.h>

struct T
{
    int i;
    char c;
    long d;
    void *p;
    int a[0];
};

int main()
{
    printf("%lu\n", sizeof(struct T));
    return 0;
}
