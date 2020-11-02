#include "iostream"
#include "climits"
using namespace std;

int partition(int *a, int s, int e)
{
    int pivot = a[e];

    // i is one step back from starting position
    int i = s - 1;
    for (int j = s; j <= e - 1; j++)
    {
        if (a[j] <= pivot)
        {
            i++;
            swap(a[i], a[j]);
        }
    }
    // Upto ith position, number are less than pivot
    // It means pivot position is i+1
    i++;
    swap(a[i], a[e]);
    return i;
}

void quick_sort(int *a, int s, int e)
{
    if (s < e)
    {
        int q = partition(a, s, e);
        quick_sort(a, s, q - 1);
        quick_sort(a, q + 1, e);
    }
}
int main()
{
    int a[] = {2, 3, 1, 5, 10, 102, 304, 608, 76, 3, 4, 5, 6, 7, 4};
    int n = sizeof(a) / sizeof(int);
    int s = 0;
    int e = n - 1;
    quick_sort(a, s, e);

    for (int i = 0; i < n; i++)
        cout << a[i] << " ";

    return 0;
}
