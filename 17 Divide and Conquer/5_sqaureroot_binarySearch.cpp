#include<iostream>
#include<math.h>
using namespace std;
int find_square( int n)
{
    int start =0,end=n,mid;
    int square_root;
    while(start<=end)
    {
        mid = (start+end)/2;
        
        if(pow(mid,2)>n)
        {
            end = mid-1;
        }
        else if(pow(mid,2)<=n)
        {
            square_root = mid;
            start = mid+1;
        }
    }
    return square_root;
}
int main()
{
    int n;
    cin>>n;
    
    
    cout<<find_square(n); // n+1 is size here 
    return 0;
}