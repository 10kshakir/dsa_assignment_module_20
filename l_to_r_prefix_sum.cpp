#include <iostream>

using namespace std;

int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i =0;i<n;i++)cin>>a[i];
    int pre[n];
    pre[0]=a[0];
    for(int i =1;i<n;i++)
    {
        pre[i]=a[i]+pre[i-1];
    }
    int d;
    cin>>d;
    for(int i =0;i<d;i++)
    {

        int x,y;
        cin>>x>>y;
        if(x==1)cout<<pre[y-1];
        else{

        int ans =(pre[y-1]- pre[x-2]);
        cout<<ans;

        }

        cout<<endl;

    }
    return 0;
}
