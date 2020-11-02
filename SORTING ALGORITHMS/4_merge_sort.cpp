#include "iostream"
#include "climits"
using namespace std;

void merge(int *a, int s, int mid, int e)
{
    int m = mid - s + 1;
    int n = e - mid;
    int tema[m], temb[n];

    for (int i = 0; i < m; i++)
    {
        tema[i] = a[s + i];
    }
    for (int i = 0; i < n; i++)
    {
        temb[i] = a[mid + 1 + i];
    }

    int ia = 0, ib = 0;
    while (ia < m and ib < n)
    {
        if (tema[ia] <= temb[ib])
        {
            a[s] = tema[ia];
            ia++;
            s++;
        }
        else
        {
            a[s] = temb[ib];
            ib++;
            s++;
        }
    }

    while (ia < m)
    {
        a[s] = tema[ia];
        ia++;
        s++;
    }

    while (ib < n)
    {
        a[s] = temb[ib];
        ib++;
        s++;
    }
}

void merge_sort(int *a, int s, int e)
{

    if (s < e)
    {
        int mid = (s + e) / 2;
        merge_sort(a, s, mid);
        merge_sort(a, mid + 1, e);
        merge(a, s, mid, e);
    }
}

int main()
{
    int a[] = {2, 3, 1, 5, 10, 102, 304, 608, 76, 3, 4, 5, 6, 7, 4};
    int n = sizeof(a) / sizeof(int);
    int s = 0;
    int e = n - 1;
    merge_sort(a, s, e);

    for (int i = 0; i < n; i++)
        cout << a[i] << " ";

    return 0;
}
