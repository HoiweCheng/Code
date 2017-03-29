#include "stack.h"

int main()
{
    stack s;
    init(&s);
    int i = 1;
    for(i = 1; i <= 5; i++)
        push(&s, i);
    while(!empty(&s))
    {
        int v = top(&s);
        pop(&s);
        printf("%d ", v);
    }
    printf("\n");
    return 0;

}
