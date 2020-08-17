#include <iostream>
#include <algorithm>
using namespace std;
////////////////////////////////////////////////
int binary_search(int *arr, int n, int key)
{
    int start=0, end =n-1;
    int mid;
    while(start<=end)
    {
        mid = (start+end)/2;
        if(arr[mid]==key)
        {
            return mid;
        }
        else if(arr[start]<=arr[mid])
        {
            if(key>=arr[start] && key<=arr[mid])
            {
                end = mid-1;
            }
            else
            {
                start =mid+1; 
            }
            
        }
        else
        {
            if(key<=arr[end] && key>=arr[mid])
            {
                start = mid+1;
            }
            else
            {
                end = mid-1;
            }
            
        }
        
    }
    return -1;
}
////////////////////////////////////////////
int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    ///////////////////////////
    int key;
    cin>>key;
    cout<<binary_search(a,n,key);

    return 0;
}