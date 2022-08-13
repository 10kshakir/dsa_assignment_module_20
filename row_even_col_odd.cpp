#include <iostream>

using namespace std;

int main()
{
    int row,col;
    cin>>row>>col;
    int a[row][col];

    for(int i =0;i<row;i++)
    {
        for(int j =0;j<col;j++)
        {
            cin>>a[i][j];
        }
    }

    int sum =0;

    for(int i =0;i<row;i++)
    {
        for(int j =0;j<col;j++)
        {
            if(i%2==0&&j%2!=0)
            {
                sum+=a[i][j];
            }

        }
    }
    cout<<sum;

    return 0;
}
