#include<iostream>
using namespace std;
// int * func()
// {
//     int a[] ={ 1, 2, 3, 4, 5 };
//     cout<<a<<endl;
//     cout<<a[0]<<endl;
//     return a;  //returning the address
// }

int * func()
{
    int * a = new int[4]{0};
    cout<<a<<endl;
    cout<<a[0]<<endl;
    return a;  //returning the address
}


int main()
{
    int * adress = func();
    cout<<"******"<<endl;
    cout<<adress<<endl;
    cout<<adress[0];

    return 0;
}