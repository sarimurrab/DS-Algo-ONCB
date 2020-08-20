#include<iostream>
using namespace std;
bool can_we_put_cow(int * stall,int size,int mid,int cows)
{
    int count = 0;
    int last_cow = stall[0];
    for(int i=1;i<size;i++)
    {
        if(stall[i]-last_cow>=mid)
        {
            last_cow = stall[i];
            count++;
            if(count == cows)
            {
                return true;
            } 
        }
    }
    return false;
}
int main()
{
    int stall[]={1,2,4,8,9};
    int size = 5;
    int mid = 3;
    int cows = 3;
cout<<can_we_put_cow(stall,size,mid, cows);
}