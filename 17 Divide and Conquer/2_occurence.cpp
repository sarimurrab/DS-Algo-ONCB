#include <iostream>
using namespace std;
// first occurence
int first_occurence(int *arr, int n, int key)
{
    int start = 0, end = n - 1;
    int mid;
    int first_ocur = -1;
    while (start <= end)
    {
        mid = (start + end) / 2;
        if (arr[mid] == key)
        {
            first_ocur = mid;
            end = mid - 1;
        }
        else if (arr[mid] > key)
        {
            end = mid - 1;
        }
        else if (arr[mid] < key)
        {
            start = mid + 1;
        }
    }
    return first_ocur;
}
// second occurence
int second_occurence(int *arr, int n, int key)
{
    int start = 0, end = n - 1;
    int mid;
    int second_ocur = -1;
    while (start <= end)
    {
        mid = (start + end) / 2;
        if (arr[mid] == key)
        {
            second_ocur = mid;
            start = mid + 1;
        }
        else if (arr[mid] > key)
        {
            end = mid - 1;
        }
        else if (arr[mid] < key)
        {
            start = mid + 1;
        }
    }
    return second_ocur;
}
int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int key;
    cout << "Enter key: ";
    cin >> key;
    int first_itr = first_occurence(arr, n, key);
    int second_itr = second_occurence(arr, n, key);
    if (first_itr == -1 || second_itr == -1)
    {
        cout << 0;
    }
    else
    {
        cout << second_itr - first_itr + 1;
    }
    return 0;
}