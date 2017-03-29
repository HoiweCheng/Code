#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <assert.h>

using namespace std;

class myStack
{
    //private: only accessible within the class defining them
    //protected: accessible in the class that defines them and inherit from
    //that class
    //both are also accessible by friends of their class, protected accessible
    //by class inherited from friends' derived class
    protected:
        vector<int>stk;
        int sz;
    public:
        myStack()
        {
            sz = 0;
        }
        void push(int val);
        void pop();
        int top();
        void print();
        bool empty();
};
