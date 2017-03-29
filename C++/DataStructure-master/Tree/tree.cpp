#include<stdio.h>
#include<string.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<unordered_map>
#include<set>
#include<stdlib.h>
#include<list>
#include<stack>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left, *right;
    TreeNode(){}
    TreeNode(int v) : val(v), left(NULL), right(NULL){}
};

void deleteTeeNode(int val);
TreeNode* nextTreeNode_inorder(TreeNode *target);
TreeNode* nextTreeNode_postorder(TreeNode *target);
TreeNode* searchBST(int value);

/*
   Time complexity: O(n), T(n) = 2T(n/2) + O(1)
*/
TreeNode* sortedVectorToBST(vector<int>v, int start, int end)
{
    if(start > end)
        return NULL;
    int mid = start + (end - start)/2;
    TreeNode* rt = new TreeNode(v[mid]);
    rt -> left = sortedVectorToBST(v,start,mid-1);
    rt -> right = sortedVectorToBST(v,mid+1,end);
    return rt;
}

TreeNode* sortedArrayToBST(int a[], int start, int end)
{
    if(start > end)
        return NULL;
    int mid = start + (end - start)/2;
    TreeNode *rt = new TreeNode(a[mid]);
    rt->left = sortedArrayToBST(a, start, mid-1);
    rt->right = sortedArrayToBST(a, mid + 1, end);
    return rt;
}
/*
   Time complexity: O(n)
   Naive: find target value in linked list every time, T(n) = 2T(n/2)+O(n/2)
   O(nlgn)
*/
TreeNode* sortedLinkedListToBST(list<int>::iterator it, int start, int end)
{
    if(start > end)
        return NULL;
    int mid = start + (end - start)/2;
    TreeNode *leftChild = sortedLinkedListToBST(it,start,mid-1);
    TreeNode *rt = new TreeNode(*it);
    rt->left = leftChild;
    it++;
    TreeNode *rightChild = sortedLinkedListToBST(it,mid+1,end);
    rt -> right = rightChild;

    return rt;
}
void preorder(TreeNode *rt)
{
    if(rt)
    {
        printf("%d ", rt->val);
        if(rt->left)
            preorder(rt->left);
        if(rt->right)
            preorder(rt->right);
    }
}

void inorder(TreeNode* rt)
{
    if(rt->left)
        inorder(rt->left);
    printf("%d ", rt->val);
    if(rt->right)
        inorder(rt->right);
}

void postorder(TreeNode *rt)
{
    if(rt->left)
        postorder(rt->left);
    if(rt->right)
        postorder(rt->right);
    printf("%d ", rt->val);
}

void inorder_iterative(TreeNode *rt)
{
   if(!rt) return; //empty tree, edge case
   stack<TreeNode*>stk;
   stk.push(rt);
   while(rt->left)
   {
       stk.push(rt->left);
       rt = rt->left;
   }

   while(!stk.empty())
   {
       TreeNode* cur = stk.top();
       printf("%d ", cur->val);
       stk.pop();
       if(cur->right)
       {
           stk.push(cur->right);
           TreeNode* tmp = cur->right;
           while(tmp->left)
           {
               stk.push(tmp->left);
               tmp = tmp->left;
           }
       }
   }
   printf("\n");
}

void preorder_iterative(TreeNode *rt)
{
    if(!rt) return;
    stack<TreeNode*>stk;
    stk.push(rt);
    while(!stk.empty())
    {
        TreeNode* cur = stk.top();
        printf("%d ", cur->val);
        stk.pop();
        if(cur->right) stk.push(cur->right);
        if(cur->left) stk.push(cur->left);
    }
    printf("\n");
}

TreeNode* inorderSuccessor(TreeNode *rt, TreeNode *target)
{
    if(target->right)
    {
        TreeNode *tmp=target->right;
        while(tmp->left)
            tmp = tmp ->left;
        return tmp;
    }
    TreeNode* succ = NULL;
    while(rt)
    {
        if(rt->val <= target->val)
        {
            rt = rt -> right;
        }
        else
        {
            succ = rt;
            rt = rt -> left;
        }
    }
    return succ;
}

TreeNode* inorderSuccessor2(TreeNode *rt, int target)
{
    TreeNode *succ=NULL;
    while(rt)
    {
        if(rt->val < target)
            rt = rt->right;
        else if(rt->val > target)
        {
            succ = rt;
            rt = rt->left;
        }
        else if(rt->val == target)
        {
            if(rt->right)
            {
                rt = rt -> right;
                while(rt->left)
                {
                    rt = rt->left;
                }
                succ = rt;
            }
            break;
        }
    }
    return succ;
}

TreeNode* findTarget(TreeNode *rt, int value)
{
    if(rt->val == value)
        return rt;
    else
    {
        if(rt->val < value)
            return findTarget(rt->right, value);
        else 
            return findTarget(rt->left, value);
    }
    return NULL;
}

bool isValidBST(TreeNode* rt)
{
    static TreeNode* pre = NULL;
    if(rt)
    {
        if(!isValidBST(rt->left))
            return false;
        if(pre != NULL && rt->val <= pre->val)
            return false;
        pre = rt;
        return isValidBST(rt->right);
    }
    return true;
}

int main()
{
    int a[] = {1,3,4,6,7,8,10,13,14}; //from wikipedia
    int n = 9;
    vector<int>v(a,a+n);
    list<int>l;
    for(int i = 0; i < n; i++)
        l.push_back(a[i]);
    list<int>::iterator it = l.begin();

    TreeNode* rt0 = sortedVectorToBST(v,0,n-1);
    TreeNode* rt1 = sortedArrayToBST(a,0,n-1);
    TreeNode* rt2 = sortedLinkedListToBST(it,0,n-1);
    
    TreeNode* test = new TreeNode(0);
    TreeNode* test_left = new TreeNode(1);
    test->left = test_left;
    
    preorder_iterative(test);
    bool isValid = isValidBST(test);
    if(isValid)
        printf("valid bst\n");
    else 
        printf("invalid bst\n");
    printf("inorder recursive traverse a tree: ");
    inorder(rt0);
    printf("\n");

    printf("inorder iterative traverse a tree: ");
    inorder_iterative(rt0);
    printf("\n");

    printf("preorder recursive traverse a tree: ");
    preorder(rt0);
    printf("\n");

    printf("preorder iterative traverse a tree: ");
    preorder_iterative(rt0);
    printf("\n");

    printf("postorder recursive traverse a tree: ");
    postorder(rt0);
    printf("\n");

    TreeNode* target = findTarget(rt0, 8);

    TreeNode* succ = inorderSuccessor(rt0, target);
    printf("succ of %d is %d\n",target->val,  succ->val);
   
    target = findTarget(rt0, 6);
    TreeNode* succ2 = inorderSuccessor2(rt0, target->val);
    printf("succ of %d is %d\n",target->val,  succ2->val);



    preorder(rt0);
    printf("\n");    
    preorder(rt1);
    printf("\n");
    preorder(rt2);
    printf("\n");

    return 0;
}
