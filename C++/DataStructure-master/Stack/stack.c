#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

struct ListNode;
typedef struct ListNode
{
    int val;
    struct ListNode *next;
}ListNode;

typedef struct 
{
    ListNode *head;
    int sz;
}Stack;

void init(Stack *stk)
{
    stk->sz = 0;
    stk->head = NULL;
}

void push(Stack *stk, int item)
{
    ListNode *tmp = (ListNode*)malloc(sizeof(ListNode));
    tmp -> val = item;
    ListNode *curHead = stk->head;
    tmp->next = curHead;
    stk->head = tmp;
    stk->sz ++;
}

void pop(Stack *stk)
{
    assert(stk->sz > 0);
    ListNode *head = stk->head;
    ListNode *hNext = head->next;
    stk->head = hNext;
    free(head);
    stk->sz --;
}

int top(Stack *stk)
{
    assert(stk->sz > 0);
    return stk->head->val;
}

int empty(Stack *stk)
{
    if (stk->sz == 0) 
        return 1;
    else
        return 0;
}

int main()
{
    int n = 4;
    Stack stack;
    init(&stack);
    for(int i = 1; i <= n; i++)
        push(&stack, i);
    printf("test push finished\n");
    while(!empty(&stack))
    {
        int topVal = top(&stack);
        printf("%d ", topVal);
        pop(&stack);
    }
    printf("\n");
    return 0;
}

    
