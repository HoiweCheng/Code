#include "c_stack.h"

void init(stack *stk, int sz)
{
    stk->elem = (int*)malloc(sizeof(int) * sz);
    stk->sz = sz;
    stk->top = 0;
}

void push(stack *stk, int item)
{
    if(stk->top < stk->sz)
    {
        stk->elem[stk->top] = item;
        stk->top += 1;
    }
    else
        exit(1);
}

void pop(stack *stk)
{
    assert(stk->top > 0);
    //free(stk->elem + stk->top-1);
    stk->top -= 1;
}

int top(stack *stk)
{
    assert(stk->top > 0);
    return stk->elem[stk->top-1];
}

int empty(stack *stk)
{
    if(stk->top > 0)
        return 0;
    else
        return 1;
}
