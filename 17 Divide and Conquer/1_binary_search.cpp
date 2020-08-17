#include<iostream>
using namespace std;

void binary_search(int *arr, int n,int key)
{
    int start = 0,end = n,mid;
    while(start<=end)
    {
        mid = (start+end)/2;
        if(arr[mid]==key)
        {
            cout<<"OK at :"<<mid<<" index";
            break;
        }
        else if(arr[mid]<key)
        {
            start= mid+1;
        }
        else
        {
            end = mid-1;
        }
        
    }
}
int main()
{
    int n;
    cin>>n;
    int arr[n];
    for (int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    int key = 7;
    binary_search(arr,n,key);
    return 0;
}