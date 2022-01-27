#include<bits/stdc++.h>
using namespace std;

int BFS(map<int,vector<int>> G, int start,int visited[])
{
    queue<int> Q;
    Q.push(start);
    visited[start-1]=1;
    while (!Q.empty())
    {
        int s= Q.front();
        printf("%d\n",s);
        Q.pop();
        for (auto i: G[s])
        {
            if (!visited[i-1])
            {
                Q.push(i);
                visited[i-1]=1;
            }
        }
    }
}




int main()
{
    map<int,vector<int>> G;
    G[1]={2,3},G[2]={4,5},G[3]={6},G[4]={7},G[5]={8};
    int visited[8]={0};
    BFS(G,1,visited);
}
