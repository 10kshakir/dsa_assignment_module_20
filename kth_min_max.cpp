#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int n,d;
    cin>>n>>d;
    int a[n];
    for(int i =0;i<n;i++)cin>>a[i];

    sort(a,a+n);

    cout<<a[d-1]<<" ";

    int k =n-d;

    cout<<a[k]<<" ";

    return 0;
}
