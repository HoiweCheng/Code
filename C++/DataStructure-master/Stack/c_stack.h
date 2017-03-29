#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<assert.h>

typedef struct 
{
    int *elem;
    int top;
    int sz;
}stack;

void init(stack *stk, int sz);
void push(stack *stk, int item);
void pop(stack *stk);
int top(stack *stk);
int empty(stack *stk);
//void destroy(stack *stk);

