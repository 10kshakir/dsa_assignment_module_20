#include <iostream>

using namespace std;

int binarySearch(int arr[], int l, int r, int x)
{
    if(l<=r)
    {
        int mid =l+(r-l)/2;

        if(mid ==x)return mid;
        if(mid>l&&arr[mid-1]==x)return mid-1;
        if(mid<r&&arr[mid+1]==x)return mid+1;

        if(arr[mid]>x)return binarySearch(arr,l,mid-2,x);


        return binarySearch(arr,mid+2,r,x);
    }
    return -1;
}

int main()
{
    int n,x;
    cin>>n>>x;
    int a[n];
    for(int i =0;i<n;i++)cin>>a[i];

    int d= binarySearch(a,0,n-1,x);
    cout<<d+1;
}

