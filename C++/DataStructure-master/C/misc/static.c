#include <stdio.h>
#include <stdlib.h>

int get()
{
    static int i = 1;
    return i++;
}

int main()
{
    printf("%d %d %d\n", get(), get(), get());
    return 0;
}
