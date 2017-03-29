#include<vector>

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int v) : val(v), next(NULL){}
};

//delete all occurences of given value
ListNode* deleteNode(int value, ListNode *head);
ListNode* deleteNode_recursive(int value, ListNode *head);

//reverse a linkedlist
ListNode* reverseList(ListNode *head);
ListNode* reverseList_recursive(ListNode *head);

//insert a list node to linkedlist at position pos with value val
ListNode* insertNode(int pos, int val, ListNode *head);

//detect cycle in a linked list, return the cycle starting node
ListNode* detectCycle(ListNode *head);

//add two integer linkedlist
ListNode* addList(ListNode *h1, ListNode *h2);
ListNode* addList_recursive(ListNode *h1, ListNode *h2);

//detect intersect of two linkedlist
bool isIntersect(ListNode *h1, ListNode *h2);

//sort list (merge sort)
ListNode *sortList(ListNode *head);

//merge 2 sorted lists
ListNode *mergeLists(ListNode *h1, ListNode *h2);

//reverse nodes in k-group (leetcode #25)
ListNode* reverseKGroup(ListNode *head, int k);

//rotate list to the right by k places
ListNode *rotateRight(ListNode *head, int k);

//reverse words represent by linked list
//f-o-o-_-b-o-o_-null, two words, foo, boo seperated by space
ListNode *reverseWords(ListNode *head);

//print linkedList
void printList(ListNode *head);
