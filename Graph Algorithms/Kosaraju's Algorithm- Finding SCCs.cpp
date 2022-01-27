#include<bits/stdc++.h>
using namespace std;

map<int,vector<int>> reverse(map<int,vector<int>> G)
{
    map<int,vector<int>>revG;
    for (auto i: G)
    {
        for (auto j: i.second)
        {
            revG[j].push_back(i.first);
        }
    }
    return revG;
}

void DFS(map<int,vector<int>> G,int node,stack<int>& S,int* visited)
{
    visited[node]=1;
    for (auto i: G[node])
    {
        if (!visited[i]) DFS(G,i,S,visited);
    }
    S.push(node);
}

void DFS2(map<int,vector<int>> revG,int node,int* visited)
{
    visited[node]=1;
    printf("%d ",node);
    for (auto i: revG[node])
    {
        if (!visited[i]) DFS2(revG,i,visited);
    }
}

void kosaraju(map<int,vector<int>> G)
{
    map<int,vector<int>> revG=reverse(G);
    int visited[8]={0};
    int size=*(&visited+1)-visited;
    stack<int> S;
    for (auto i: G)
    {
        if (!visited[i.first]) DFS(G,i.first,S,visited);
    }
    for (int i=0;i<size;i++) visited[i]=0;
    while (!S.empty())
    {
        int k=S.top();
        S.pop();
        if (!visited[k]){DFS2(revG,k,visited); printf("\n");}
    }
}

int main()
{
    map<int,vector<int>> G;
    G[0]={1},G[1]={2},G[2]={0,3},G[3]={4},G[4]={5,7},G[5]={6},G[6]={4,7};
    kosaraju(G);
}
