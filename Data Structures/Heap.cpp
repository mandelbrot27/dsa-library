#include<bits/stdc++.h>
using namespace std;
void siftdown(vector<int>& heap, int node)
{
    int n=heap.size();
    int child1=2*node+1;
    int child2=2*node+2;
    int min=node;
    if (child1<n && heap[child1]<heap[min]) min=child1;
    if (child2<n && heap[child2]<heap[min]) min=child2;
    
    if (min==node) return;
    swap(heap[node],heap[min]);
    siftdown(heap,min);
}

void siftup(vector<int>& heap, int node)
{
    int parent=(node%2)? node/2: node/2-1;
    if (parent>-1 && heap[node]<heap[parent])
    {
        swap(heap[node],heap[parent]);
        siftup(heap,parent);
    }
}

void makeheap(vector<int>& heap)
{
    int n=heap.size();
    int lastparent=n/2 -1;
    for (int i=lastparent;i>-1;i--) siftdown(heap,i);
}

void insert(vector<int>& heap,int k)
{
    heap.push_back(k);
    siftup(heap,heap.size()-1);
}

int extractmin(vector<int>& heap)
{
    int k=heap[0];
    swap(heap[0],heap[heap.size()-1]);
    heap.pop_back();
    siftdown(heap,0);
    return k;
}

int main()
{
    vector<int> heap={7,11,99,20,52,40,17,3};   //not a heap yet.
    makeheap(heap); //makes a min-heap.
    for (auto i: heap) printf("%d ",i);
    printf("\n");
}
