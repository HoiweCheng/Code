#include <stdio.h>
#include <iostream>
using namespace std;

int factorial(int n);

int main()
{
    int n;
    scanf("%d",&n);
    int var = factorial(n);
    printf("%d\n", var);
    getchar();
    return 0;
}

int factorial(int n)
{
    int res = 1;
    //from gdb, we know that n will become 0, which makes res wrong, 
    //so fix it as while(n>){...;n--;}
    while(n--)
    {
        res *= n;
    }
    return res;
}

/*
what we can do via gdb
g++ -g src.cpp -o out
gdb out
break lineNumber
run
list //list src file
watch var //add var to watch
print var //when reach a breakpoint, print var's value
continue 
step //execute step by step
finish //run to the end
delete //delete breakpoint
backtrace //backtrace of stack call
*/
