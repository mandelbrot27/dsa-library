#include <bits/stdc++.h>
using namespace std;

map<int,int> leader,Size;
map<int,vector<int>> st;
vector<vector<int>> edges;
bool visited[10000]={0};
map<int,vector<pair<int,int>>> G;

bool sortbyweight(const vector<int> &a, const vector<int> &b)
{
    return (a[2] < b[2]);
}

void addedge(map<int,vector<pair<int,int>>>& G, int u, int v, int w)
{
    leader[u]=u;
    leader[v]=v;
    Size[leader[u]]=1;
    Size[leader[v]]=1;
    st[u].push_back(u);
    st[v].push_back(v);

    G[u].push_back({v,w});
   

}



void Union(int u, int v)
{
    if(Size[leader[u]]>=Size[leader[v]])
    {
        for (auto i: st[leader[v]])
        {
            leader[i]=leader[u];
            Size[leader[u]]++;
            st[leader[u]].push_back(i);
        }
    }
    else
    {
        for(auto i: st[leader[u]])
        {
            leader[i]=leader[v];
            Size[leader[v]]++;
            st[leader[v]].push_back(i);
        }
    }
}

int Find(int u)
{
    return leader[u];
}

void getedges()
{
    for (auto i: G)
    {
        for (auto j: i.second)
        {
            edges.push_back({i.first,j.first,j.second});
        }
    }
}

map<int,vector<pair<int,int>>> kruskal(map<int,vector<pair<int,int>>> G)
{
    map<int,vector<pair<int,int>>> T;
    getedges();
    sort(edges.begin(),edges.end(),sortbyweight);

    
    for(auto i: edges)
    {
        int u=i[0],v=i[1],w=i[2];
        if (Find(u)!=Find(v))
        {
            Union(u,v);
            T[u].push_back({v,w});
        }
    }
    return T;
}

int main()
{
    addedge(G,0,1,1);
    addedge(G,0,2,5);
    addedge(G,0,3,3);
    addedge(G,0,4,4);
    addedge(G,1,2,7);
    addedge(G,2,3,6);
    addedge(G,3,4,2);

    map<int,vector<pair<int,int>>> T= kruskal(G);
    for (auto i: T)
    {
        for (auto j: i.second)
        {
            cout<<i.first<<" "<<j.first<<" "<<j.second<<"\n";
        }
    }
}
