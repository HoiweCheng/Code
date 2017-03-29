#include "stack.h"

void myStack::push(int val)
{
    stk.push_back(val);
    sz++;
}

void myStack::pop()
{
    assert(sz>=1);
    stk.pop_back();
    sz--;
}

int myStack::top()
{
    assert(sz>=1);
    int topValue = stk[sz-1];
    sz--;
    stk.pop_back();
    return topValue;
}

void myStack::print()
{
    for(int i = 0; i < sz; i++)
        printf("%d ", stk[i]);
    printf("\n");
}

bool myStack::empty()
{
    return (sz==0);
}
