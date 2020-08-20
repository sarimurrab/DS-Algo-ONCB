#include <iostream>
#include <algorithm>
using namespace std;
bool can_we_put_cow(int *stall, int size, int mid, int cows)
{
    int count = 1;
    int last_cow = stall[0];
    for (int i = 1; i < size; i++)
    {
        if (stall[i] - last_cow >= mid)
        {
            last_cow = stall[i];
            count++;
            if (count == cows)
            {
                return true;
            }
        }
    }
    return false;
}
// int main()
// {
//     int stall[]={1,2,4,8,9};
//     int size = 5;
//     int mid = 3;
//     int cows = 3;
// cout<<can_we_put_cow(stall,size,mid, cows);
// }

int greatest_min_difference(int *stall, int size, int cows)
{
    //making a search space
    int start = 0, end = stall[size - 1] - stall[0];
    int ans, mid;

    while (start <= end)
    {
        mid = (start + end) / 2;

        bool yes_no = can_we_put_cow(stall, size, mid, cows);
        if (yes_no == false)
        {
            end = mid - 1;
        }
        else
        {
            ans = mid;
            start = mid + 1;
        }
    }
    return ans;
}
int main()
{
    int n, cows;
    
    cin >> n >> cows;
    int stall[n];

    for (int i = 0; i < n; i++)
    {
        cin >> stall[i];
    }
    sort(stall, stall + n);
    cout << greatest_min_difference(stall, n, cows);
    return 0;
}