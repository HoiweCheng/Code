#include "stack.h"

void init(stack *stk)
{
    stk->head = NULL;
    stk->sz = 0;
}

void push(stack *stk, int item)
{
    ListNode *cur = (ListNode*)malloc(sizeof(ListNode));
    cur->val = item;
    if(stk->sz == 0)
    {
        stk->head = cur;
        stk->sz ++;
    }
    else
    {
        ListNode *head = stk->head;
        cur->next = head;
        stk->head = cur;
        stk->sz ++;
    }
}

int top(stack *stk)
{
    if(stk->sz > 0)
    {
        ListNode *head = stk->head;
        return head->val;
    }
    return -1;//NA
}

void pop(stack *stk)
{
    if(stk->sz > 0)
    {
        ListNode *head = stk->head;
        ListNode *preHead = head->next;
        stk->head = preHead;
        free(head);
        head = NULL;
        stk->sz --;
    }
}

int empty(stack *stk)
{
    return stk->sz == 0 ? 1 : 0;
}




