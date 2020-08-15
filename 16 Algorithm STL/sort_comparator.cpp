#include <iostream>
#include <algorithm>
using namespace std;
bool anything(int a,int b)
{
    cout<<"Comparing "<<a<<"and "<<b<<endl;
    return a>b;
    
}
int main()
{
    int arr[] = {3, 4, 5, 6, 1, 2};
    int size = sizeof(arr) / sizeof(int);
    sort(arr, arr + size,anything);
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}
