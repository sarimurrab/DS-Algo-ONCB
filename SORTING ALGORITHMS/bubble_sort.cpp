#include "iostream"
#include "climits"
using namespace std;

// ************BUBBLE SORT**********************

void bubble_sort(int *a, int n)
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<=n-2-i;j++)
        {
            if(a[j]>a[j+1])
            swap(a[j],a[j+1]);
        }
    }
}

int main()
{
    int a[] = {2, 3, 1, 5, 3, 4, 5, 6, 7, 4};
    int n = sizeof(a) / sizeof(int);
    bubble_sort(a,n);
    for(int i=0;i<n;i++)
    cout<<a[i]<<" ";

    return 0;
}