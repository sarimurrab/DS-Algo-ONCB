#include <iostream>
#include <algorithm>
using namespace std;
void find_min_combination(int *arr, int money, int size)
{

    while (money > 0)
    {
        auto itr = upper_bound(arr, arr + size, money);
        cout << arr[itr - arr - 1] << " ";
        money = money - arr[itr - arr - 1];
    }
}
int main()
{
    int arr[] = {1, 2, 5, 10, 50, 100, 200, 500, 2000};
    int money = 54;
    int size = sizeof(arr) / sizeof(int);
    find_min_combination(arr, money, size);
    return 0;
}