#include<stdio.h>
#include<stack>
using namespace std;

int main()
{
    int n = 5;
    stack<int>stk;
    stk.push(n);
    int x = stk.top();
    printf("%d\n", x);
    return 0;
}
