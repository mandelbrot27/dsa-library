#include<bits/stdc++.h>
using namespace std;

void siftdown(vector<int>& heap, int node, int n)
{
    int child1=2*node+1;
    int child2=2*node+2;
    int max=node;
    if (child1<n && heap[child1]>heap[max]) max=child1;
    if (child2<n && heap[child2]>heap[max]) max=child2;
    
    if (max==node) return;
    swap(heap[node],heap[max]);
    siftdown(heap,max,n);
}

void makeheap(vector<int>& heap)
{
    int n=heap.size();
    int lastparent=n/2 -1;
    for (int i=lastparent;i>-1;i--) siftdown(heap,i,n);
}


void heapsort(vector<int>& heap)
{
    for(int i=heap.size()-1;i>-1;i--)
    {
        swap(heap[0],heap[i]);
        siftdown(heap,0,i);
    }
}

int main()
{
    vector<int> heap={4,10,3,5,1};   //not a heap yet.
    makeheap(heap); //makes a max-heap.
    heapsort(heap);
    for (auto i: heap) printf("%d ",i);
    printf("\n");
}
