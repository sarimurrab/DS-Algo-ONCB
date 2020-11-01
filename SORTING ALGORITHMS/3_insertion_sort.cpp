#include "iostream"
#include "climits"
using namespace std;

// ************INSERTION SORT**********************
// mycodeschool
void insertion_sort(int *a, int n)
{
    for(int i=1;i<n;i++)
    {
        int temp = a[i];
        int hole = i;
        while(a[hole-1]>temp && hole>0)
        {
            a[hole] = a[hole-1];
            hole--;
        }
        a[hole]= temp;
    }
}

int main()       
{
    int a[] = {2, 3, 1, 5, 3, 4, 5, 6, 7, 4};
    int n = sizeof(a) / sizeof(int);
    for(int i=0;i<n;i++)
    cout<<a[i]<<" ";
    cout<<endl;
    insertion_sort(a,n);
    for(int i=0;i<n;i++)
    cout<<a[i]<<" ";

    return 0;
}

// OUTPUT
// 2 3 1 5 3 4 5 6 7 4
// 2 3 1 5 3 4 5 6 7 4
// 1 2 3 5 3 4 5 6 7 4
// 1 2 3 5 3 4 5 6 7 4
// 1 2 3 3 5 4 5 6 7 4
// 1 2 3 3 4 5 5 6 7 4
// 1 2 3 3 4 5 5 6 7 4
// 1 2 3 3 4 5 5 6 7 4
// 1 2 3 3 4 5 5 6 7 4
// 1 2 3 3 4 4 5 5 6 7
// 1 2 3 3 4 4 5 5 6 7