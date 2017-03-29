#include<stdio.h>
#include<string.h>
/*
int* - pointer to int
int const * - pointer to const int
int * const - const pointer to int
int const * const - const pointer to const int
Now the first const can be on either side of the type so:

const int * == int const *
const int * const == int const * const
If you want to go really crazy you can do things like this:

int ** - pointer to pointer to int
int ** const - a const pointer to a pointer to an int
int * const * - a pointer to a const pointer to an int
int const ** - a pointer to a pointer to a const int
int * const * const - a const pointer to a const pointer to an int
...
*/
void myfun1(int * const p) //p is constant pointer, can not be changed
{
    int i = 0;
    for(; i < 3; i++)
    {
        *(p+i) = 10;
        printf("%d ", *(p+i));
    }
    printf("\n");
}

void myfun2(const int * p) //non-constant pointer points to readonly memory
{
    int i = 0;
    while(i++ < 3)
    {
        //*p = 10; not allowed, since memory p points to is readonly
        printf("%d ", *p);
        p++;
    }
    printf("\n");
}

int main()
{
    int a[] = {1,2,3};
    int *p = a; //constant pointer
    myfun1(p);

    const int b[] = {4,5,6};
    const int* q = b; //pointer to a constant space
    myfun2(q);

    int const  *r = a;
//    *(r+1) = 20;//not allowed, int const *r is equivalent to const int *r
    printf("%d\n", *r); 
    return 0;
}
