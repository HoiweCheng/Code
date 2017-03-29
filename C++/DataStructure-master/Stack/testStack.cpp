#include "stack.h"
#include <time.h>

int main()
{
    myStack stack;
    int n = 10;
    srand(time(NULL));
    for(int i = 0; i < n; i++)
    {
        int rnd = rand()%50;
        stack.push(rnd);
    }

    //test member access
//    printf("%d \n", stack.sz); //invalid, protected member cannot be
//    accessed by its objects

    //test stack
    while(!stack.empty())
    {
        stack.print();
        stack.pop();
    }
    
    return 0;
}
