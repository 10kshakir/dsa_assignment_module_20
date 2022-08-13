#include <iostream>
#include <math.h>
using namespace std;

bool check_prime(int n)
{
    if(n<2)return false;


    for(int i =2;i<=sqrt(n);i++ )
    {
        if(n%i==0)return false;
    }
    return true;
}

int main()
{
    int n;
    cin>>n;
    for(int i =1;i<=n;i++)
    {
        if(check_prime(i))cout<<i<<" ";
    }

    return 0;
}
