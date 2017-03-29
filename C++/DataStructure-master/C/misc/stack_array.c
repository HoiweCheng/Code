#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct stack
{
    int *buf;
    int sz;
    int offset;
}stack;
/*
void init(stack *stk)
{
    stk->buf = (int*)malloc(sizeof(int));
    stk->sz = 1;
    stk->offset = 0;
}
*/

void push(stack *stk, int item)
{
    if(stk->offset >= stk->sz)
    {
       // int newSZ = stk->sz << 1;
        int newSZ = stk->sz == 0 ? 1 : stk->sz << 1;
        stk->buf = (int*)realloc(stk->buf, newSZ);
        stk->sz = newSZ;
    }
    *(stk->buf + stk->offset) = item;
    stk->offset ++;
}

void pop(stack *stk)
{
    if(stk->offset > 0)
    {
        stk->offset--;
    }
}

int top(stack *stk)
{
    if(stk->offset >= 1)
    {
        return *(stk->buf + stk->offset - 1);
    }
    return -1;//NA
}

int empty(stack *stk)
{
    if(stk->offset==0)
        return 1;
    return 0;
}

int main()
{
    static stack s;
//    stack s;
    printf("%lu\n", sizeof(s));
//    init(&s);
    for(int i = 1; i <= 5; i++)
        push(&s,i);
    while(!empty(&s))
    {
        int t = top(&s);
        printf("%d ", t);
        pop(&s);
    }
    printf("\n");
    return 0;
}
