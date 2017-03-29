#include<stdio.h>
#include<string.h>
#include<vector>
#include<algorithm>
#include<string>
#include<queue>
#include<map>
using namespace std;

vector<char>adj[300];

char readChar()
{
    char ch[10];
    scanf("%s",ch);
    return ch[0];
}

void topoSort(int n)
{
   int deg[300];
   map<char,bool>show;
   for(int i = 0; i < 300; i++)
       adj[i].clear();
   memset(deg,0,sizeof(deg));
   for(int i = 0; i < n; i++) 
   {
       char a,b;
       a = readChar();
       b = readChar();
       adj[a].push_back(b);
       deg[b]++;
       show[a]=true;
       show[b]=true;
   }
   queue<char>Q;
   for(int i = 'A'; i <= 'Z'; i++)
   {
       if(!show[i]) continue; 
       if(deg[i]==0)
           Q.push(i);
   }
   while(!Q.empty())
   {
       char front = Q.front();
       Q.pop();
       printf("%c ", front);
       for(int j = 0; j < adj[front].size(); j++)
       {
           char next = adj[front][j];
           deg[next]--;
           if(deg[next]==0)
               Q.push(next);
       }
   }
   if(n>0)
       printf("\n");
}

int main()
{
    int n;
    while(scanf("%d",&n)==1)
    {
        topoSort(n);
    }
}

