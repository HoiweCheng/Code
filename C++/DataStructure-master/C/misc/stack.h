#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct ListNode
{
    int val;
    struct  ListNode *next;
}ListNode;

typedef struct stack
{
    ListNode *head;
    int sz;
}stack;

void init(stack *stk);
void push(stack *stk, int item);
void pop(stack *stk);
int top(stack *stk);
int empty(stack *stk);

