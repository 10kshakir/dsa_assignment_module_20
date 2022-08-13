#include <iostream>
#include <algorithm>
/*
BY each iteration  binary search size of an array reduce by 1/2 .that's why it time complexity is
log2(n) or O(log(n)).
*/
using namespace std;

int BinarySearch(int a[],int x,int lb,int hb)
{
    if(lb<=hb)
    {
        int mid =(lb+hb)/2;
        //mid case
        if(x==a[mid] )
        {
            return mid;
        }

        //x>a[mid]
        else if(x>a[mid])
        {
            BinarySearch(a,x,mid+1,hb);
        }

        //x<a[mid]
        else{
            BinarySearch(a,x,lb,mid-1);
        }
    }
    else return -1;
}

int main()
{
    int size;
    cin>>size;

    int a[size];

    for(int i =0;i<size;i++)
    {
        cin>>a[i];
    }



    int check_value ;
    cin>>check_value;


    int index=BinarySearch(a,check_value,0,size-1);

    if(index!=-1)
    {
        cout<<"Index : "<<index<<" position : "<<index+1;
    }
    else
    {
        cout<<"Not found in the array"<<endl;
    }

    return 0;
}

