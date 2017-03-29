//Day day bath
#include<stdio.h>
#include<string.h>
#include<queue>
#include<algorithm>
#include<iostream>
#include<vector>
using namespace std;

int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int n, m;
        scanf("%d%d", &n, &m);
        vector<int>bath;
        for(int i = 0; i < n; i++)
        {
            int x;
            scanf("%d", &x);
            bath.push_back(x);
        }
        if(n < m)
        {
            printf("0\n");
            continue;
        }
        //pq stores the dequeue time of each item
        priority_queue<int, vector<int>, greater<int> >pq;
        int ans = 0;
        int wait = n - m + 1;
        int k = 0; 
        for(k = 0; k < m; k++)
            pq.push(bath[k]);
        while(wait)
        {
            int cur = pq.top();
            ans = cur;
            pq.pop();
            pq.push(bath[k++] + cur);
            if(cur > 600)
            {
                ans = -1;
                break;
            }
            wait--;
        }
        printf("%d\n", ans);
    }
}

