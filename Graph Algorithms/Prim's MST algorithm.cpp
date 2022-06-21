#include<bits/stdc++.h>
using namespace std;

void addedge(map<int,vector<pair<int,int>>>& G, int u, int v,int w)
{
    G[u].push_back({v,w});
    G[v].push_back({u,w});
}

void prim(map<int,vector<pair<int,int>>> G, int n)
{
    priority_queue<pair<int,int>> pq;
    vector<int> key(n,1e8);
    vector<int> parent(n,-1);
    vector<bool> inMST(n,false);
    pq.push({0,0}); //(weight,vertex)
    key[0]=0;
    while(!pq.empty())
    {
        int u=pq.top().second;
        pq.pop();
        if (!inMST[u])
        {
            inMST[u]=true;
            for (auto i: G[u])
            {
                int v=i.first; int w=i.second;
                if (!inMST[v] && key[v]>w)
                {
                    key[v]=w;
                    pq.push({-key[v],v});
                    parent[v]=u;
                }
            }
        }
    }
    for (int i=1;i<n;i++)
    {
        printf("%d:%d\n",parent[i],i);
    }
}

int main()
{
    map<int,vector<pair<int,int>>> G;
    addedge(G,0,1,4);
    addedge(G,0,2,9);
    addedge(G,0,3,2);
    addedge(G,1,2,5);
    addedge(G,2,3,3);
    prim(G,4);
}
