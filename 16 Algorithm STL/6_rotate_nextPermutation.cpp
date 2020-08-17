#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    ////////////////////////////////////////////
    // 1--> rotate
    int arr[] = {1, 2, 3, 4, 5};
    int size = sizeof(arr) / sizeof(int);
    rotate(arr, arr + 2, arr + size);

    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    ///////////////////////////////////////////
    // 2--> rotate on vector
    vector<int> v{1, 2, 3, 4, 5};
    rotate(v.begin(), v.begin() + 2, v.end());
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }

    cout << endl;
    ///////////////////////////////////////////
    // 3--> next_permutation---next bigger number having same digit
    vector<int> e{1, 2, 3};
    next_permutation(e.begin(), e.end());
    prev_permutation(e.begin(), e.end());
    for (int i = 0; i < e.size(); i++)
    {
        cout << e[i] << " ";
    }

    return 0;
}