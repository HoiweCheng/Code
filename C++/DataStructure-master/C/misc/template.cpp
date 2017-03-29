#include<iostream>
using namespace std;
template <class A> class calc
{
    public:
        A add(A x, A y);
        A minus(A x, A y);
};

template <class A> A calc<A> :: add(A x, A y)
{
    return x+y;
}
template <class A> A calc<A> :: minus(A x, A y)
{
    return x-y;
}

//templated function
template <typename Type>
Type max(Type a, Type b)
{
    return a > b ? a : b;
}

int main()
{
    calc<int>obj;
    int res = obj.add(3,5);
    cout << res << endl;
    cout << max(3,5) << endl;
    return 0;
}
