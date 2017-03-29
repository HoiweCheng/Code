#include<stdio.h>
#include<string.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<set>
#include<unordered_map>
using namespace std;

struct ListNode 
{
    int val;
    ListNode *next;
    ListNode(int v) : val(v), next(NULL){}
};

//delete all occurances of a value
ListNode* deleteNode(int value, ListNode *head)
{
    ListNode* res = NULL;
    ListNode* pre = NULL;
    ListNode* cur = head;

    while(cur)
    {
        if(cur->val == value)
        {
            if(res == cur)
            {
                res = cur -> next;
            }
            if(pre != NULL)
            {
                pre -> next = cur -> next;
            }
        }
        else
        {
            if(res == NULL)
            {
                res = cur;
            }
            pre = cur;
        } 
        cur = cur -> next;
    }
    return res;
}

ListNode* deleteNode2(int target, ListNode *head)
{
}

ListNode* reverseList(ListNode* head)
{
    ListNode* pre = NULL;
    ListNode* cur = head;
    while(cur)
    {
        ListNode* tmp = cur->next;
        cur->next = pre;
        pre = cur;
        cur = tmp;
    }
    return pre;
}

void appendNode(ListNode *last, int value)
{
    ListNode *tmp = new ListNode(value);
    last -> next = tmp;
}

void printList(ListNode *head)
{
    ListNode *tmp = head;
    while(tmp)
    {
        printf("%d ", tmp->val);
        tmp = tmp->next;
    }
    printf("\n");
}

void printListRecursive(ListNode *head)
{
    if(head)
    {
        printf("%d ", head->val);
        printListRecursive(head->next);
    }
}

void deDuplicate();
ListNode* insertNode(int pos, int value,  ListNode *head) //return new head
{
    ListNode* pre = NULL;
    ListNode* cur = head;
    ListNode* tmp = new ListNode(value);

    int posCnt = 0;
    while(++posCnt < pos && cur)
    {
        pre = cur;
        cur = cur -> next;
    }
//    printf("cur: %d\n", cur->val);
    if(pre)
    {
        pre->next = tmp;
        tmp->next = cur;
        return head;
    }
    else 
    {
        tmp->next = cur;
        return tmp;
    }
}
//incorrect
ListNode *reverseList2(ListNode *pre, ListNode *head)
{
    if(!head || !head->next)
        return head;
    ListNode *tmp = head;
    ListNode *nxt = head->next;
    head->next = pre;
    ListNode *ret = reverseList2(head,nxt);
    ret->next = tmp;
    pre = ret;
    return ret;
}

ListNode* detectCircle(ListNode *head); // return new head

int main()
{
    int a[] = {1,1,2,3,5,8,3,13};
    int n = 8;
    ListNode *head = new ListNode(a[0]);
    ListNode *cur = head;
    for(int i = 1; i < n; i++)
    {
        appendNode(cur,a[i]);
        cur = cur -> next;
    }
    printf("after adding nodes: ");
    printList(head);
    
    printf("new reverse\n");
    ListNode *ret = reverseList2(NULL, head);
    printList(ret);

    printf("after reverse linkedlist: ");
    head =  reverseList(head);
    printList(head);

    int delTarget = 1;
    head = deleteNode(1,head);
    printf("after deleting all nodes with value %d: ", delTarget);
    printListRecursive(head);
    printf("\n"); 
    //add node at pos=6, i.e. add 8 back
    head = insertNode(1,5,head);
    printf("after insert node with value 5 at position 1: ");
    printListRecursive(head);
    printf("\n");
    return 0;
}
