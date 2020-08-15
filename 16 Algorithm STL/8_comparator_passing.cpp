#include <iostream>
#include <climits>
using namespace std;
bool compare(int a, int b)
{
    return a > b;
}
void selection_sort(int *a, int n, bool (&cmp)(int a, int b))
{

    for (int i = 0; i < n - 1; i++)
    {
        int temp = i;
        for (int j = i; j < n; j++)
        {
            if (cmp(a[j], a[temp]))    ///FUNCTION USED IN ANOTHER FUNCTION
            {
                temp = j;
            }
        }
        swap(a[temp], a[i]);
    }
}
int main()
{
    int n = 7;
    int a[7] = {5, 3, 7, 1, 9, 3, 2};
    selection_sort(a, n, compare);
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << "  ";
    }
    return 0;
}