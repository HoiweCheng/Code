#include <stdio.h>
#include <stdlib.h>

typedef struct ListNode
{
    int val;
    struct ListNode *next;
}ListNode;

ListNode* del(ListNode *head, int target)
{
    ListNode *cur = head;
    ListNode *res = NULL;
    ListNode *pre = NULL;
    while(cur)
    {
        if(cur->val==target)
        {
            ListNode *cNext = cur->next;
            if(pre!=NULL)
            {
                pre->next = cNext;
            }
            free(cur);
            cur = cNext;
        }
        else
        {
            if(res==NULL)
                res = cur;
            pre=cur;
            cur=cur->next;
        }
    }
    return res;
}

ListNode* reverse(ListNode *head)
{
    ListNode *cur = head;
    ListNode *pre = NULL;

    while(cur)
    {
        ListNode *cNext = cur->next;
        cur->next = pre;
        pre = cur;
        cur = cNext;
    }

    return pre;
}

void printList(ListNode *head)
{
    while(head)
    {
        printf("%d ", head->val);
        head = head->next;
    }
    printf("\n");
}

int main()
{
    ListNode *head = NULL;
    int i = 1;
    ListNode *cur=head;
    for(i=1; i<=10; i++)
    {
        if(head==NULL)
        {
            head = (ListNode*)malloc(sizeof(ListNode));
            head->val=i;
            cur = head;
        }
        else
        {
            ListNode *tmp = (ListNode*)malloc(sizeof(ListNode));
            tmp->val = i;
            cur->next = tmp;
            cur = cur->next;
        }
    }

    ListNode *tmp = (ListNode*)malloc(sizeof(ListNode));
    tmp->val = 1;
    cur->next = tmp;
    
    head = reverse(head);
    printList(head);
    ListNode *newHead = del(head, 1);

    printList(newHead);

    return 0;
}


