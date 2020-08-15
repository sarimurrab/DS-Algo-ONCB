#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6};
    int sz = sizeof(arr) / sizeof(int);

    int key = 3;

    auto it = find(arr, arr + sz, key);   // ** auto 
    int index = it - arr;    // (arr+index) - (arr)

    if (index == sz)
    {
        cout << "not present";
    }
    else
    {
        cout << index;
    }
}