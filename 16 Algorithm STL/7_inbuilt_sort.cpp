#include <iostream>
#include <algorithm>
using namespace std;
bool compare(string a, string b)
{
    cout << "Comparing " << a << " and " << b << endl;
    if (a.length() == b.length())
        return a < b;
    return a.length() < b.length();
}
int main()
{
    int n ;
    cin>>n;
    string arr[n];

    for (int i = 0; i <= n - 1; i++)
    {
        cin >> arr[i];
    }
    ////////////////////////////////

    sort(arr, arr + n, compare);
    for (int i = 0; i <= n - 1; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}