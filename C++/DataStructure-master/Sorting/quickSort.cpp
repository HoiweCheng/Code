#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
#include<string>
#include<string.h>
#include<iostream>
#include<vector>
using namespace std;

int partition(vector<int>&a, int l, int r)
{
    int x = a[l];
    while(l < r)
    {
        while(l < r && a[r] > x) r--;
        if(l < r)
        {
            a[l] = a[r];
            l++;
        }
        while(l < r && a[l] < x) l++;
        if(l < r)
        {
            a[r] = a[l];
            r--;
        }
    }
    a[l] = x;
    return l;
}

void quickSort(vector<int> &a, int l, int r)
{
    if(l < r)
    {
        int i = partition(a, l, r);
        for(int j = 0; j < a.size(); j++)
            printf("%d ", a[j]);
        printf("\n");
        quickSort(a, l, i - 1);
        quickSort(a, i + 1, r);
    }
}

int main()
{
    //1 2 3 4 5 10
    int a0[] = {3,4,10,2,1,5};
    //int a0[] = {72,6,57,88,60,42,83,73,48,85};
    int n = 6;
    vector<int>a(a0,a0+n);
    quickSort(a, 0, n-1);
    for(int i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");
}
