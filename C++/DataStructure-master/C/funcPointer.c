#include <stdio.h>
#include <math.h>

int binarySearch(int a[], int target, int n)
{
    int l = 0, r = n-1;
    while( l <= r)
    {
        int mid = l + (r - l) / 2;
        if(a[mid] > target) r = mid - 1;
        else l = mid + 1;
    }

    return r == -1 ? 0 : r;
}

int main()
{
    int a[] = {1,2,3,3,3,3,4,5};
    int target = 3;
    int n = 8; 
    //function pointer example for binarySearh()
    int(*bsp)(int*, int, int) = &binarySearch;
    printf("target index = %d\n", (*bsp)(a,target,n));

    return 0;
}
