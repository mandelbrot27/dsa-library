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

void makeheap(vector<int>& heap)
{
    int n=heap.size();
    int lastparent=n/2 -1;
    for (int i=lastparent;i>-1;i--) siftdown(heap,i);
}

void heapsort(vector<int>& heap)
{
    for(int i=heap.size()-1;i>-1;i--)
    {
        swap(heap[0],heap[i]);
        siftdown(heap,0);
    }
}

int main()
{
    vector<int> heap={7,11,99,20,52,40,17,3};   //not a heap yet.
    makeheap(heap); //makes a min-heap.
    heapsort(heap);
    for (auto i: heap) printf("%d ",i);
    printf("\n");
}
