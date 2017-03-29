#include "c_stack.h"

int main()
{
    stack stk;
    init(&stk, 10);
    printf("ok??\n");
    for(int i = 1; i <= 5; i++)
        push(&stk, i);
    printf("re-ok??\n");
    while(empty(&stk) == 0)
    {
        printf("times\n");
        int t = top(&stk);
        pop(&stk);
        printf("%d ", t);
    }
    printf("\n");
    return 0;
}
