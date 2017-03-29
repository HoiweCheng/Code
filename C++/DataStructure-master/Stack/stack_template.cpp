#include<stdio.h>
#include<vector>
#include<string.h>
#include<algorithm>
#include<assert.h>
using namespace std;

template <class Type> class Stack
{
    private:
        vector<Type> stk;
        int sz;
    public:
        Stack()
        {
            sz = 0;
        }
        void push(Type item)
        {
            stk.push_back(item);
            sz ++;
        }
        void pop()
        {
            assert(sz > 0);
            sz --;
        }
        Type top()
        {
            assert(sz > 0);
            return stk[sz-1];
        }
        bool empty()
        {
            return sz==0;
        }
};

int main()
{
    Stack<int>myStk;
    int a[] = {1,2,3};
    for(int i = 0; i < 3; i++)
        myStk.push(a[i]);
    printf("--------\n");
    while(!myStk.empty())
    {
        int curTop = myStk.top();
        printf("%d ", curTop);
        myStk.pop();
    }
    printf("\n");
    return 0;
}


