#include<iostream>
using namespace std;
int main()
{
    // 1--> static allocation   int a[100] = {0}
    int a[100];
    cout<<"Static Size: "<<sizeof(a)<<endl;
    // "a" comes from symbol table and can't be overwritten    ***

    // 2--> Dynamic allocation in heap memory   int * b = new int[n]{0}
    int n;
    cout<<"Enter Size of Dynamic Array";
    cin>>n;
    int * b = new int[n];
    //b can be overwritten      a = new int[100];              ***
    cout<<"Dynamic SIZE: "<<sizeof(b)<<endl;

    //input values to dyanmic array
    cout<<"Enter values to dyanmic array"<<endl;
    for (int i = 0; i < n; i++)
    {
        cin>>b[i];

    }
    //Printing Dynamic Array Values
    for (int i = 0; i < n; i++)
    {
        cout<<b[i]<<" ";

    }


    // 3--> delete [] b
    delete [] b;



    return 0;
}