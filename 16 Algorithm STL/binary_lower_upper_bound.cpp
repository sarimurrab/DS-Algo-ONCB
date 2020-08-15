#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    int arr[] = {1, 2,3,3,3,3,3, 4, 5};
    int n = 9;

    int key = 3;

    // 1--> binary_search(arr, arr+n, key)
    bool is_present = binary_search(arr, arr + 5, key);
    cout << is_present;

    // 2--> Lower Bound   ( 1st element match with > or equal to )

    auto l_iter = lower_bound(arr, arr + n, key);
    cout << endl
         << "Lower Bound " << (l_iter - arr);

    // 3--> Upper Bound   ( 1st element match with >  )

    auto u_iter = upper_bound(arr, arr + n, key);
    cout << endl
         << "Upper Bound " << (u_iter - arr);

    //  Upper - Lower = Occurence of key
    cout<<endl<<"Occurence of "<<key<<": "<<u_iter-l_iter;
}