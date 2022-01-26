#include<bits/stdc++.h>
using namespace std;

int Rselect(int* arr,int l,int r,int k)
{
    // To get the kth order statistic.
    if (r<=l) return arr[l];

    int pivot=l+rand()%(r-l+1);
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
    if (k==i) return arr[i-1];
    else if (k<i) return Rselect(arr,l,i-2,k);
    else return Rselect(arr,i,r,k);
}


int main()
{
    int arr[8]={6,5,1,9,2,4,3,11};
    int size=*(&arr+1)-arr;
    int l=0,r=size-1;
    int k=4;
    printf("%d\n",Rselect(arr,l,r,k));
}
