#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(){}
    ListNode(int v) : val(v), next(NULL){}
};

void addNode(ListNode *last, int value)
{
    ListNode *tmp = new ListNode(value);
    last -> next = tmp;
}

ListNode* reverseList(ListNode *head)
{
    ListNode *pre = head;
    ListNode *cur = head;
    while(cur)
    {
       if(cur==head) 
       {
           cur = cur->next;
           pre -> next = NULL;
       }
       else
       {
           ListNode* tmp = cur->next;
           cur->next = pre;
           pre = cur;
           cur = tmp;
       }
    }
    return pre;
} 

void printList(ListNode *head)
{
    if(head)
    {
        printf("%d ", head -> val);
        printList(head->next);
    }
    else
        printf("\n");
}
/*
void add_list2(ListNode *h1, ListNode *h2, int *carry,  ListNode **res)
{
    int len1 = 0;
    int len2 = 0;
    int diff = 0;

    ListNode *cur = h1;
    while(cur)
    {
        len1++;
        cur=cur->next;
    }
    cur = h2;
    while(cur)
    {
        len2++;
        cur=cur->next;
    }
 //assert(h1) is longer than h2, otherwise, swap
    if(len1 < len2)
    {
        cur = h1;
        h1 = h2;
        h2 = cur;
    }
    diff = abs(len1-len2);
    cur = h1;
    while(diff--)
    {
        cur = cur -> next;
    }

    add_list(cur, h2, carry,res);
    
    diff = abs(len1 - len2);
    add_remaining(h1, carry, res, diff);
    if(*carry)
    {
        ListNode *temp = new ListNode(
*/
/*
ListNode* addHelp(ListNode *l1, ListNode *l2, int carry)
{
    
}
*/
ListNode* addList_1(ListNode *h1, ListNode *h2)
{
    return addHelp(h1,h2,0);
}

ListNode* addList_2(ListNode *h1, ListNode *h2)
{
    ListNode* new_h1 = reverseList(h1);
    ListNode* new_h2 = reverseList(h2);
    ListNode* ret = NULL;
    ListNode* res = NULL;
    int carry = 0;
    while(new_h1 || new_h2)
    {
        int curVal = 0;
        if(!new_h1)
        {
            curVal = carry + new_h2->val;
            new_h2 = new_h2 -> next;
        }
        else if(!new_h2)
        {
            curVal = carry + new_h1->val;
            new_h1 = new_h1 -> next;
        }
        else
        {
            curVal = new_h1->val + new_h2->val + carry;
            new_h1 = new_h1 -> next;
            new_h2 = new_h2 -> next;
        }
        carry = curVal/10;
        curVal %= 10;
        if(!res)
        {
            res = new ListNode(curVal);
            ret = res;
        }
        else
        {
            ListNode* tmp = new  ListNode(curVal);
            res->next = tmp;
            res = tmp;
        }
    }
    if(carry>0)
    {
        ListNode *tmp = new ListNode(carry);
        res->next = tmp;
    }
    ret = reverseList(ret);
    return ret;
}


int main()
{
    int a[] = {1,2,3,4};
    int b[] = {7,8};

    ListNode *h1 = new ListNode(1);
    ListNode *h2 = new ListNode(7);
    ListNode *cur_last = h1; 
    for(int i = 1; i < 4; i++)
    {
        addNode(cur_last, a[i]);
        cur_last = cur_last->next;
    }
    cur_last = h2;
    for(int i = 1; i < 2; i++)
    {
        addNode(cur_last, b[i]);
        cur_last = cur_last->next;
    }
    printList(h1);
    printList(h2);
    printf("finish print h1 original \n");
    ListNode *res = addList_2(h1,h2); 
    printList(res);
    return 0;
}
