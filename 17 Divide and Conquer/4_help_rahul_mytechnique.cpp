#include <iostream>
#include <algorithm>
using namespace std;
////////////////////////////////////////////////
int binary_search(int *arr, int key, int start, int end)
{
    int mid;
    while (start <= end)
    {
        mid = (start + end) / 2;
        if (arr[mid] == key)
        {
            return mid;
        }
        else if (arr[mid] < key)
        {
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
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
    int position = 0;
    for (int i = 1; i < n; i++)
    {
        if (a[i] < a[position])
        {
            position = i;
            break;
        }
        position++;
    }
    if (a[0] < a[position])
    {
        position = 0;
    }
    //cout << "breakpoint : "<<a[position];
    /////////////////////////////
    // cout << endl
    //      << "enter key: ";
    int key;
    cin >> key;
    if (binary_search(a, key, 0, position - 1) != -1)
    {
        cout << binary_search(a, key, 0, position - 1);
    }
    else
    {
        cout << binary_search(a, key, position , n);
    }

    return 0;
}