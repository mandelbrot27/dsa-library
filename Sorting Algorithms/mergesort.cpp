#include<bits/stdc++.h>
using namespace std;

void mergeSort(int* arr,int l,int r)
{
    if (r<=l) return;

    int mid= (r+l)/2, sizeleft=mid-l+1,sizeright=r-mid;
    int left[sizeleft];
    int right[sizeright];

    for (int i=0;i<sizeleft;i++) left[i]=arr[l+i];
    for (int i=0;i<sizeright;i++) right[i]=arr[mid+1+i];

    mergeSort(left,0,sizeleft-1);
    mergeSort(right,0,sizeright-1);

    int i=0,j=0,k=0;
    while (i<sizeleft && j<sizeright)
    {
        if (left[i]<right[j])
        {
            arr[k]=left[i];
            i++;
        }
        else
        {
            arr[k]=right[j];
            j++;
        }
        k++;
    }
    while (i<sizeleft){arr[k]=left[i]; i++;k++;}
    while (j<sizeright){arr[k]=right[j];j++;k++;}
}



int main()
{
    int arr[8]={2,4,1,9,11,2,5,3};
    int size=*(&arr + 1) - arr;
    int l=0, r=size-1;
    mergeSort(arr,l,r);
    for (auto i: arr) printf("%d ",i);
    printf("\n");
}