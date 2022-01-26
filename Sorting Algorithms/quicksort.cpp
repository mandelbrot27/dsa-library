#include<bits/stdc++.h>
using namespace std;

void quickSort(int* arr,int l, int r)
{
    if (r<=l) return;
    int pivot= l + rand()%(r-l+1);
    swap(arr[l],arr[pivot]);
    int i=l+1;
    for (int j=l+1;j<=r;j++)
    {
        if (arr[j]<arr[l])
        {
            swap(arr[j],arr[i]);
            i++;
        }
    }
    swap(arr[l],arr[i-1]);
    quickSort(arr,l,i-2);
    quickSort(arr,i,r);
}


int main()
{
    int arr[8]={6,5,1,9,2,4,3,11};
    int size=*(&arr+1)-arr;
    int l=0,r=size-1;
    quickSort(arr,l,r);
    for (int i=0;i<size;i++) printf("%d ",arr[i]);
    printf("\n");
}