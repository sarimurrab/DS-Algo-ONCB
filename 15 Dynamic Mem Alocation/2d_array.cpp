#include<iostream>
using namespace std;
int main()
{
    int r,c;
    cin>>r>>c;
    int* * arr ;
    arr = new int*[r];

    for (int i = 0; i < r; i++)
    {
        arr[i] = new int[c]{0};
    }

    //printing
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
    
    
    return 0;
}