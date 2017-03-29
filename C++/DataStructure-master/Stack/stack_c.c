#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
typedef int bool;
struct Stack
{
   struct ListNode *top;
    int sz;
};

struct ListNode
{
    int val;
    struct ListNode *next, *pre;
};

int empty(struct Stack *stk)
{
    if(stk->sz > 0) 
        return 0;
    else
        return 1;
}
void push(struct Stack *stk, int item)
{
    stk = (struct Stack*) malloc(sizeof(struct Stack));
    struct ListNode *tmp = (struct ListNode*) malloc(sizeof(struct ListNode));
    tmp->val = item;
    if(empty(stk) == 0)
    {
        struct ListNode *t = stk->top;
        t->next = tmp;
        tmp->pre = t;
        tmp->next = NULL;
        stk->sz ++;
    }
    else
    {
        tmp->pre = NULL;
        tmp->next = NULL;
        stk->sz ++;
    }
    stk->top = tmp;
}
        
void init(struct Stack *stk, int n)
{
    for(int i = 1; i <= n; i++)
    {
        push(stk, i);
    }
}

void pop(struct Stack *stk)
{
    assert(stk->sz > 0);
    struct ListNode *t = stk->top;
    struct ListNode *p = t->pre;
    stk->top = p;
    stk->sz --;
    free(t);
}

int top(struct Stack *stk)
{
    assert(stk->sz > 0);
    return stk->top->val;
}


int main()
{
    struct Stack stk;
    int n = 4;
    init(&stk, n);
    push(&stk, 5);
    push(&stk,6);
    int curTop = top(&stk);
    printf("curTop = %d\n", curTop);
    while(!empty(&stk))
    {
        int tmp = top(&stk);
        pop(&stk);
        printf("%d ", tmp);
    }
    printf("\n");
    return 0;
}
