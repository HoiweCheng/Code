#include <stdio.h>
#include <stdlib.h>

typedef struct ListNode
{
    int val;
    struct ListNode *next;
};

ListNode* addLists(ListNode *p1, ListNode *p2, ListNode *q1, ListNode *q2)
{
    if(p2)

