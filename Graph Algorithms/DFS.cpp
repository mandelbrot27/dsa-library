#include<bits/stdc++.h>
using namespace std;

void DFS(map<int,vector<int>> G, int start, int visited[])
{
    visited[start-1]=1;
    printf("%d\n",start);

    for (auto i: G[start])
    {
        if (!visited[i-1]) DFS(G,i,visited);
    }

}


int main()
{
    //Definition of Graph.
    map<int,vector<int>> G;
    G[1]={2,3},G[2]={4,5},G[3]={6},G[4]={7},G[5]={8};
    int visited[8]={0};
    DFS(G,1,visited);
}
