#include <iostream>

/*
insertion sort time complexity is n-1 =O(n);
bubble sort time complexity is n =O(n);
counting sort time complexity is always (no matter it sorted or not) n =O(n);

*/

using namespace std;
//bubble sort implementation
void bubble_sort(int a[],int n)
{
    int count=0;
    for(int i =1;i<n;i++)
    {

        int flag =0;
        for(int j =0;j<n-i;j++)
        {

            if(a[j]>a[j+1])
            {
                int temp =a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
                flag++;
            }


           count++;

        }
        count++;

        if(flag==0) break;
    }
    cout<<count<<endl;
}
 //insertion sort implementation
void insertion_sort(int a[],int n)
{
    int count =0;
    for(int i =1;i<n;i++)
    {
        int key =a[i];
        int j =i-1;

        while(j>=0&&a[j]>key)
        {
            a[j+1]=a[j];
            j--;

            count++;
        }
        a[j+1]=key;


        count++;
    }
    cout<<count<<endl;
}


int main()
{
    int a[]={1,2,3,4,5};
    insertion_sort(a,5);
    bubble_sort(a,5);

    return 0;
}

