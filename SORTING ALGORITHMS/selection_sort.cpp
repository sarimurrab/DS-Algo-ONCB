#include "iostream"
#include "climits"
using namespace std;

// ************SELECTION SORT**********************

// selecting the minimum element from an array and 
// putting onto the first position and so on.
void selection_sort(int *a, int size)
{
    int pointer = 0;
    while(pointer!=size-2)
    {
        int loc_min = INT_MAX;
        int pointer_sec;
        for(int i=pointer;i<size;i++)
        {
            if(a[i]<loc_min)
            {
                loc_min = a[i];
                pointer_sec = i;
            }
        }
        swap(a[pointer],a[pointer_sec]);
        pointer++;
    }
}

int main()
{
    int a[] = {2, 3, 1, 5, 3, 4, 5, 6, 7, 4};
    int size = sizeof(a) / sizeof(int);
    selection_sort(a,size);
    for(int i=0;i<size;i++)
    cout<<a[i]<<" ";

    return 0;
}