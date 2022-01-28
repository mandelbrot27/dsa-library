#include<bits/stdc++.h>
using namespace std;

void addedge(int u, int v, int w, vector<pair<int,int>>* G)
{
    G[u].push_back({v,w});
    G[v].push_back({u,w});
}

void dijkstra(vector<pair<int,int>> G[], int source, vector<int>& distance,int* visited)
{

    priority_queue<pair<int,int>> heap; //weight,node.
    distance[source]=0;
    heap.push({0,source});
    while (!heap.empty())
    {
        int x= heap.top().second;
        visited[x]=1;
        heap.pop();
        for (auto i: G[x])
        {
            if (!visited[i.first] && distance[i.first]> distance[x]+i.second)
            {
                distance[i.first]=distance[x] + i.second;
                heap.push({-distance[i.first],i.first});  //-distance[t] as priority_queue is max-heap.
            }
        }
    }
}

int main()
{
    int n=9;
    vector<pair<int,int>> G[n];    // pair of node and it's weight.
    vector<int> distance(n,INT_MAX);  // distance of node from source.
    int visited[n]={0};
    addedge(0, 1, 4,G);
    addedge(0, 7, 8,G);
    addedge(1, 2, 8,G);
    addedge(1, 7, 11,G);
    addedge(2, 3, 7,G);
    addedge(2, 8, 2,G);
    addedge(2, 5, 4,G);
    addedge(3, 4, 9,G);
    addedge(3, 5, 14,G);
    addedge(4, 5, 10,G);
    addedge(5, 6, 2,G);
    addedge(6, 7, 1,G);
    addedge(6, 8, 6,G);
    addedge(7, 8, 7,G);
    dijkstra(G,0,distance,visited);

    for (int i=0;i<9;i++) printf("%d\n",distance[i]);
}
